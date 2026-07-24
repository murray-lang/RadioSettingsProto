#include "iq/source/IqSourceFactory.h"

ResultCode
IqSourceFactory::create(const Config::IqIo::IqSourceConfigVariant& config, IqSourceVariant& source)
{
  ResultCode rc = ResultCode::OK;
  if (holds_alternative<Config::AdcIqSource::Fields>(config)) {
    source.emplace<AdcIqSource>();
    rc = get<AdcIqSource>(source).configure(get<Config::AdcIqSource::Fields>(config));
    if (rc != ResultCode::OK) {
      source.emplace<monostate>();
    }
    return rc;
  }
  return ResultCode::ERR_IQ_SOURCE_UNKNOWN_TYPE;
}
