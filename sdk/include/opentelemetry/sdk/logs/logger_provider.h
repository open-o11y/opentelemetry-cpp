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

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "opentelemetry/nostd/shared_ptr.h"
#include "opentelemetry/sdk/logs/processor.h"
#include "opentelemetry/sdk/logs/logger.h"
#include "opentelemetry/logs/logger_provider.h"
#include "opentelemetry/logs/noop.h"
#include "opentelemetry/sdk/common/atomic_shared_ptr.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace sdk
{
namespace logs
{
class LoggerProvider final : public opentelemetry::logs::LoggerProvider
{
public:
  /**
   * Initialize a new logger provider with a specified processor
   * @param processor The processor for this logger provider. This must
   * not be a nullptr.
   */
   explicit LoggerProvider(std::shared_ptr<LogProcessor> processor) noexcept;

   /**
   * Initialize a new logger provider. A processor must later be assigned
   * to this logger provider via the SetProcessor() method.
   */
   explicit LoggerProvider() noexcept;
   
   /**
    * Creates a logger with the given name, and returns a shared pointer to it.
    * If a logger with that name already exists, return a shared pointer to it
    * @param name The name of the logger to be created.
    * @param options (OPTIONAL) The options for the logger. TODO: Give list of options
    */
   opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> GetLogger(opentelemetry::nostd::string_view name, opentelemetry::nostd::string_view options = "") noexcept override;

   /**
    * Creates a logger with the given name, and returns a shared pointer to it.
    * If a logger with that name already exists, return a shared pointer to it
    * @param name The name of the logger to be created.
    * @param args (OPTIONAL) The arguments for the logger.
    */
   opentelemetry::nostd::shared_ptr<opentelemetry::logs::Logger> GetLogger(opentelemetry::nostd::string_view name, nostd::span<nostd::string_view> args) noexcept override;

   /**
    * Removes a logger with the given name. If no logger exists with that name,
    * return false.
    * @param name The name of the logger to be removed.
    */
   //bool RemoveLogger(nostd::string_view name) noexcept;
   
   /**
    * Returns a shared pointer to the processor currently stored in the
    * logger provider. If no processor exists, returns a nullptr
    */
   std::shared_ptr<LogProcessor> GetProcessor() noexcept;

   //Sets the common processor that all the Logger instances will use
   /**
    * Sets the processor that is stored internally in the logger provider.
    * @param processor The processor to be stored inside the logger provider.
    * This must not be a nullptr.
    */
   void SetProcessor(std::shared_ptr<LogProcessor> processor) noexcept;

private:
   //A pointer to the processor stored by this logger provider
   opentelemetry::sdk::AtomicSharedPtr<LogProcessor> processor_;

   //A vector of pointers to all the loggers that have been created
   std::vector<std::shared_ptr<Logger>> loggers_;
};
}  // namespace logs
}  // namespace sdk
OPENTELEMETRY_END_NAMESPACE

