/*
 * Copyright The OpenTelemetry Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "opentelemetry/sdk/logs/logger_provider.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
LoggerProvider::LoggerProvider(std::shared_ptr<LogProcessor> processor) noexcept
    : processor_{processor}
{}

LoggerProvider::LoggerProvider() noexcept : processor_{nullptr} {}

opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> LoggerProvider::GetLogger(
    opentelemetry::nostd::string_view name,
    opentelemetry::nostd::string_view options) noexcept
{
  // If a logger with a name "name" already exists, return it
  std::unordered_map<std::string, std::shared_ptr<Logger>>::iterator loggerkv =
      loggers_.find(name.data());
  if (loggerkv != loggers_.end())
  {
    return opentelemetry::nostd::shared_ptr<Logger>(loggerkv->second);
  }

  // If no logger with that name exists yet,
  // Create it and add it to the map of loggers
  auto loggerInstance = new Logger(GetProcessor());
  std::shared_ptr<Logger> loggerPtr{loggerInstance};
  loggers_[name.data()] = loggerPtr;
  return opentelemetry::nostd::shared_ptr<Logger>(loggerPtr);
}

opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> LoggerProvider::GetLogger(
    opentelemetry::nostd::string_view name,
    nostd::span<nostd::string_view> args) noexcept
{
  // Currently, no args support
  return GetLogger(name);
}

bool LoggerProvider::RemoveLogger(std::string name) noexcept
{
  // Search if a logger with the given name already exists.
  // If so, set it to a Noop logger and remove it from list of loggers
  std::unordered_map<std::string, std::shared_ptr<Logger>>::iterator loggerkv = loggers_.find(name);
  if (loggerkv != loggers_.end())
  {
    // TODO: Test this functionality
    std::shared_ptr<opentelemetry::logs::Logger> apilogger = loggerkv->second;
    apilogger.reset(new opentelemetry::logs::NoopLogger);
    loggers_.erase(name);
    return true;
  }

  return false;
}

std::shared_ptr<LogProcessor> LoggerProvider::GetProcessor() noexcept
{
  return processor_.load();
}

void LoggerProvider::SetProcessor(std::shared_ptr<LogProcessor> processor) noexcept
{
  processor_.store(processor);

  // Add this new processor to all the Logger instances
  for (auto loggerkv : loggers_)
  {
    auto sdkLogger = static_cast<Logger *>(loggerkv.second.get());
    sdkLogger->SetProcessor(processor);
  }
}
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
