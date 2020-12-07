#pragma once

#include "opentelemetry/logs/log_record.h"
#include "opentelemetry/nostd/type_traits.h"
#include "opentelemetry/sdk/logs/exporter.h"
#include "opentelemetry/version.h"

#include <iostream>
#include <map>
#include <sstream>

namespace nostd   = opentelemetry::nostd;
namespace sdklogs = opentelemetry::sdk::logs;

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace logs
{
/**
 * The OStreamLogExporter exports logs through an ostream (default set to std::cout)
 */
class OStreamLogExporter final : public sdklogs::LogExporter
{
private:
  template <typename T>
  void print_value(const T &item)
  {
    sout_ << item;
  }

// Prior to C++14, generic lambda is not available so fallback to functor.
#if __cplusplus < 201402L

  class AttributeValueVisitor
  {
  public:
    AttributeValueVisitor(OStreamLogExporter &exporter) : exporter_(exporter) {}

    template <typename T>
    void operator()(T &&arg)
    {
      exporter_.print_value(arg);
    }

  private:
    OStreamLogExporter &exporter_;
  };

#endif

  void print_value(common::AttributeValue &value)
  {
#if __cplusplus < 201402L
    // nostd::visit(AttributeValueVisitor(*this), value);
#else
    nostd::visit([this](auto &&arg) { sout_ << arg; }, value);
#endif
  }

  void printKV(nostd::string_view &key, common::AttributeValue &value)
  {
    if (firstKV)
    {
      firstKV = false;
    }
    else
    {
      sout_ << ", ";
    }

    sout_ << "{" << key << ": ";
    print_value(value);
    sout_ << "}";
  }

public:
  /**
   * Create an OStreamLogExporter. This constructor takes in a reference to an ostream that the
   * export() function will send log data into.
   * The default ostream is set to stdout
   */
  explicit OStreamLogExporter(std::ostream &sout = std::cout) noexcept;
  sdklogs::ExportResult Export(const nostd::span<std::shared_ptr<opentelemetry::logs::LogRecord>>
                                   &records) noexcept override;

  bool Shutdown(
      std::chrono::microseconds timeout = std::chrono::microseconds::max()) noexcept override;

private:
  std::ostream &sout_;
  bool isShutdown_ = false;
  bool firstKV     = true;

  // Mapping severity number to severity text from api/include/opentelemetry/logs/log_record.h
  std::map<int, std::string> severityMap{
      {1, "kTrace"},  {2, "kTrace2"},  {3, "kTrace3"},  {4, "kTrace4"},  {5, "kDebug"},
      {6, "kDebug2"}, {7, "kDebug3"},  {8, "kDebug4"},  {9, "kInfo"},    {10, "kInfo2"},
      {11, "kInfo3"}, {12, "kInfo4"},  {13, "kWarn"},   {14, "kWarn2"},  {15, "kWarn3"},
      {16, "kWarn4"}, {17, "kError"},  {18, "kError2"}, {19, "kError3"}, {20, "kError4"},
      {21, "kFatal"}, {22, "kFatal2"}, {23, "kFatal3"}, {24, "kFatal4"}};
};
}  // namespace logs
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
