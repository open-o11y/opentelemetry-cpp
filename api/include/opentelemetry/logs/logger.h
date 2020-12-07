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

#include <chrono>
#include <map>
#include <vector>

#include "opentelemetry/common/key_value_iterable.h"
#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/nostd/shared_ptr.h"
#include "opentelemetry/nostd/span.h"
#include "opentelemetry/nostd/string_view.h"
#include "opentelemetry/version.h"

OPENTELEMETRY_BEGIN_NAMESPACE
namespace logs
{
/**
 * Handles log record creation.
 **/
class Logger
{
public:
  virtual ~Logger() = default;

  /* Returns the name of the logger */
  virtual const nostd::string_view GetName() noexcept = 0;

  /**
   * Each of the following overloaded log(...) methods
   * creates a log message with the specific parameters passed.
   *
   * @param name the name of the log event.
   * @param severity the severity level of the log event.
   * @param message the string message of the log (perhaps support std::fmt or fmt-lib format).
   * @param record the log record (object type LogRecord) that is logged.
   * @param attributes the attributes, stored as a 2D list of key/value pairs, that are associated
   * with this log.
   * @throws No exceptions under any circumstances.
   */

  /**
   * Logs a LogRecord, which contains all the fields of the Log Data Model. Normally called
   * indirectly from other Log() Methods, but can be called directly for high detail.
   * @param record A log record filled with information from the user.
   */
  virtual void Log(const LogRecord &record) noexcept = 0;

  /// Overloaded Log methods, which are simpler than calling a LogRecord directly

  /**
   * Writes a log.
   * @param severity The log's severity
   * @param message The message to log
   */
  inline void Log(Severity severity, nostd::string_view message) noexcept
  {
    // Create a LogRecord to hold this information
    LogRecord r;
    r.severity = severity;
    r.body     = message;

    // Call the main Log(LogRecord) method
    Log(r);
  }

  /**
   * Writes a log.
   * @param severity The log's severity
   * @param name The name of the log
   * @param message The message to log
   */
  inline void Log(Severity severity, nostd::string_view name, nostd::string_view message) noexcept
  {
    // Create a LogRecord to hold this information
    LogRecord r;
    r.severity = severity;
    r.name     = name;
    r.body     = message;

    // Call the main Log(LogRecord) method
    Log(r);
  }

  /**
   * Writes a log.
   * @param severity The severity of the log, from 1 to 24
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Log(Severity severity, const T &attributes) noexcept
  {
    // Create a LogRecord to hold this information
    LogRecord r;
    r.severity   = severity;
    r.SetAttributes(attributes);

    // Call the main Log(LogRecord) method
    Log(r);
  }

  /**
   * Writes a log.
   * @param severity The severity of the log, from 1 to 24
   * @param name The name of the log
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Log(Severity severity, nostd::string_view name, const T &attributes) noexcept
  {
    // Create a LogRecord to hold this information
    LogRecord r;
    r.severity   = severity;
    r.name       = name;
    r.SetAttributes(attributes);

    // Call the main Log(LogRecord) method
    Log(r);
  }

  /**
   * Writes a log with a severity of trace.
   * @param message The message to log
   */
  inline void Trace(nostd::string_view message) noexcept { Log(Severity::kTrace, message); }

  /**
   * Writes a log with a severity of trace.
   * @param name The name of the log
   * @param message The message to log
   */
  inline void Trace(nostd::string_view name, nostd::string_view message) noexcept
  {
    Log(Severity::kTrace, name, message);
  }

  /**
   * Writes a log with a severity of trace.
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Trace(const T &attributes) noexcept
  {
    Log(Severity::kTrace, attributes);
  }

  /**
   * Writes a log with a severity of trace.
   * @param name The name of the log
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Trace(nostd::string_view name, const T &attributes) noexcept
  {
    Log(Severity::kTrace, name, attributes);
  }

  /**
   * Writes a log with a severity of debug.
   * @param message The message to log
   */
  inline void Debug(nostd::string_view message) noexcept { Log(Severity::kDebug, message); }

  /**
   * Writes a log with a severity of debug.
   * @param name The name of the log
   * @param message The message to log
   */
  inline void Debug(nostd::string_view name, nostd::string_view message) noexcept
  {
    Log(Severity::kDebug, name, message);
  }

  /**
   * Writes a log with a severity of debug.
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Debug(const T &attributes) noexcept
  {
    Log(Severity::kDebug, attributes);
  }

  /**
   * Writes a log with a severity of debug.
   * @param name The name of the log
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Debug(nostd::string_view name, const T &attributes) noexcept
  {
    Log(Severity::kDebug, name, attributes);
  }

  /**
   * Writes a log with a severity of info.
   * @param message The message to log
   */
  inline void Info(nostd::string_view message) noexcept { Log(Severity::kInfo, message); }

  /**
   * Writes a log with a severity of info.
   * @param name The name of the log
   * @param message The message to log
   */
  inline void Info(nostd::string_view name, nostd::string_view message) noexcept
  {
    Log(Severity::kInfo, name, message);
  }

  /**
   * Writes a log with a severity of info.
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Info(const T &attributes) noexcept
  {
    Log(Severity::kInfo, attributes);
  }

  /**
   * Writes a log with a severity of info.
   * @param name The name of the log
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Info(nostd::string_view name, const T &attributes) noexcept
  {
    Log(Severity::kInfo, name, attributes);
  }

  /**
   * Writes a log with a severity of warn.
   * @param message The message to log
   */
  inline void Warn(nostd::string_view message) noexcept { Log(Severity::kWarn, message); }

  /**
   * Writes a log with a severity of warn.
   * @param name The name of the log
   * @param message The message to log
   */
  inline void Warn(nostd::string_view name, nostd::string_view message) noexcept
  {
    Log(Severity::kWarn, name, message);
  }

  /**
   * Writes a log with a severity of warn.
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Warn(const T &attributes) noexcept
  {
    Log(Severity::kWarn, attributes);
  }

  /**
   * Writes a log with a severity of warn.
   * @param name The name of the log
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Warn(nostd::string_view name, const T &attributes) noexcept
  {
    Log(Severity::kWarn, name, attributes);
  }

  /**
   * Writes a log with a severity of error.
   * @param message The message to log
   */
  inline void Error(nostd::string_view message) noexcept { Log(Severity::kError, message); }

  /**
   * Writes a log with a severity of error.
   * @param name The name of the log
   * @param message The message to log
   */
  inline void Error(nostd::string_view name, nostd::string_view message) noexcept
  {
    Log(Severity::kError, name, message);
  }

  /**
   * Writes a log with a severity of error.
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Error(const T &attributes) noexcept
  {
    Log(Severity::kError, attributes);
  }

  /**
   * Writes a log with a severity of error.
   * @param name The name of the log
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Error(nostd::string_view name, const T &attributes) noexcept
  {
    Log(Severity::kError, name, attributes);
  }

  /**
   * Writes a log with a severity of fatal.
   * @param message The message to log
   */
  inline void Fatal(nostd::string_view message) noexcept { Log(Severity::kFatal, message); }

  /**
   * Writes a log with a severity of fatal.
   * @param name The name of the log
   * @param message The message to log
   */
  inline void Fatal(nostd::string_view name, nostd::string_view message) noexcept
  {
    Log(Severity::kFatal, name, message);
  }

  /**
   * Writes a log with a severity of fatal.
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Fatal(const T &attributes) noexcept
  {
    Log(Severity::kFatal, attributes);
  }

  /**
   * Writes a log with a severity of fatal.
   * @param name The name of the log
   * @param attributes A key/value object
   */
  template <class T,
            nostd::enable_if_t<common::detail::is_key_value_iterable<T>::value> * = nullptr>
  inline void Fatal(nostd::string_view name, const T &attributes) noexcept
  {
    Log(Severity::kFatal, name, attributes);
  }

  /** Future enhancement: templated method for objects / custom types (e.g. JSON, XML, custom
   * classes, etc) **/
  // template<class T> virtual void log(T &some_obj) noexcept;
};
}  // namespace logs
OPENTELEMETRY_END_NAMESPACE