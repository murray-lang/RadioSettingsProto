#pragma once
#include <settings/model/data/band/BandCategoryList.h>
#include "Band.h"


template <typename protoT, int requestTag, int bandTag, typename CacheClass>
class WithBandT
{
public:
  explicit WithBandT(protoT& rawWithBand)
    : m_rawBandSettings(rawWithBand)
    , m_bandRequest(
      rawWithBand.band_or_request.band_request,
      rawWithBand.band_or_request.band_request,
      sizeof(rawWithBand.band_or_request.band_request))
    , m_band(rawWithBand.band_or_request.band)
  {
    // setBandOrRequestVariant(rawWithBand);
  }

  [[nodiscard]] bool isBandRequest() const { return m_rawBandSettings.which_band_or_request == requestTag; }
  [[nodiscard]] bool isBand() const { return m_rawBandSettings.which_band_or_request == bandTag; }
  [[nodiscard]] const StringRef& bandRequest() const { return m_bandRequest; }
  Band& band() { return m_band; }
  protoT& rawBand() { return m_rawBandSettings; }

  ResultCode autoCompleteBand(const BandCategoryList& bands, CacheClass& cache)
  {
    return ResultCode::OK;
  }

  ResultCode autoCompleteBand(
    SettingDescriptor& setting,
    uint32_t startIndex,
    const BandCategoryList& bands,
    CacheClass& cache)
  {
    return ResultCode::OK;
  }

  // [[nodiscard]] bool isBandValid() const { return m_bandOrRequest.index() != 0; }
  // [[nodiscard]] bool hasBandRequest() const { return m_bandOrRequest.index() == requestTag; }
  // const StringRef& bandRequest() const { return get<StringRef>(m_bandOrRequest); }
  // [[nodiscard]] bool hasBand() const { return m_bandOrRequest.index() == bandTag; }
  // [[nodiscard]] const StringRef* bandName() const
  // {
  //   const StringRef* request = get_if<StringRef>(&m_bandOrRequest);
  //   if (request != nullptr) return request;
  //   const Band* band = get_if<Band>(&m_bandOrRequest);
  //   if (band != nullptr) return &band->name();
  //   return nullptr;
  // }
  // [[nodiscard]] const Band* band() const { return get_if<Band>(&m_bandOrRequest); }

protected:
  // void setBandOrRequestVariant(protoT& rawWithBand)
  // {
  //   if (rawWithBand.which_band_or_request == requestTag) {
  //     m_bandOrRequest.emplace<StringRef>(
  //       rawWithBand.band_or_request.band_request,
  //       rawWithBand.band_or_request.band_request,
  //       sizeof(rawWithBand.band_or_request.band_request)
  //     );
  //   } else if (rawWithBand.which_band_or_request == bandTag) {
  //     m_bandOrRequest.emplace<Band>(rawWithBand.band_or_request.band);
  //   }
  // }
  protoT& m_rawBandSettings;
  StringRef m_bandRequest;
  Band m_band;
  // BandOrRequestVariant m_bandOrRequest;
};
