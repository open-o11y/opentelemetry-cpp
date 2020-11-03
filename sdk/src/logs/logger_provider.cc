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

   LoggerProvider::LoggerProvider() noexcept
        : processor_{nullptr}
   {}
   
   opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> LoggerProvider::GetLogger(opentelemetry::nostd::string_view name, opentelemetry::nostd::string_view options) noexcept
   {
       //Search if a logger with the given name already exists.
       //If so, return it
       for(std::shared_ptr<Logger> &logger : loggers_)
       {
           if(logger->GetName() == name.data())
                return opentelemetry::nostd::shared_ptr<Logger>(logger);
       }
       //If no logger with that name exists yet,
       //Create it and add it to the list of loggers
       auto loggerInstance = new Logger(name.data());
       loggerInstance->SetProcessor(GetProcessor());
       std::shared_ptr<Logger> loggerPtr{loggerInstance};
       loggers_.push_back(loggerPtr);
       return opentelemetry::nostd::shared_ptr<Logger>(loggerPtr);
   }

   opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> LoggerProvider::GetLogger(opentelemetry::nostd::string_view name, nostd::span<nostd::string_view> args) noexcept
   {
   }

   
   /*
   bool LoggerProvider::RemoveLogger(nostd::string_view name) noexcept
   {
       //Search if a logger with the given name already exists.
       //If so, set it to a Noop logger and remove it from list of loggers
       int count = 0;
       for(std::shared_ptr<Logger> &logger : loggers_)
       {
           if(logger->GetName() == name.data())
           {
               auto loggerPtr = loggers_[count];
               loggerPtr = new opentelemetry::logs::NoopLogger();
               loggers_.erase(loggers_.begin() + count);
               return true;
           }
           count++;
       }

       return false;
   }
   */
   
   std::shared_ptr<LogProcessor> LoggerProvider::GetProcessor() noexcept
   {
       return processor_.load();
   }

   void LoggerProvider::SetProcessor(std::shared_ptr<LogProcessor> processor) noexcept
   {
       processor_.store(processor);

       //Add this new processor to all the Logger instances
       for(int i = 0; i < loggers_.size(); i++)
       {
            auto sdkLogger = static_cast<Logger *>(loggers_[i].get());
            sdkLogger->SetProcessor(processor);
       }
   }
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE
