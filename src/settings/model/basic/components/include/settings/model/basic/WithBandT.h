#pragma once
#include "settings/model/base/Band.h"


template <typename protoT, int requestTag, int bandTag>
class WithBandT
{
public:
  explicit WithBandT(protoT& rawWithBand)
  {
    setBandOrRequestVariant(rawWithBand);
  }

  [[nodiscard]] bool isBandValid() const { return m_bandOrRequest.index() != 0; }
  [[nodiscard]] bool hasBandRequest() const { return m_bandOrRequest.index() == requestTag; }
  [[nodiscard]] bool hasBand() const { return m_bandOrRequest.index() == bandTag; }
  [[nodiscard]] const StringRef* bandName() const
  {
    const StringRef* request = get_if<StringRef>(&m_bandOrRequest);
    if (request != nullptr) return request;
    const Band* band = get_if<Band>(&m_bandOrRequest);
    if (band != nullptr) return &band->name();
    return nullptr;
  }
  [[nodiscard]] const Band* band() const { return get_if<Band>(&m_bandOrRequest); }

protected:
  void setBandOrRequestVariant(protoT& rawWithBand)
  {
    if (rawWithBand.which_band_or_request == requestTag) {
      m_bandOrRequest.emplace<StringRef>(
        rawWithBand.band_or_request.band_request,
        rawWithBand.band_or_request.band_request,
        sizeof(rawWithBand.band_or_request.band_request)
      );
    } else if (rawWithBand.which_band_or_request == bandTag) {
      m_bandOrRequest.emplace<Band>(rawWithBand.band_or_request.band);
    }
  }

  BandOrRequestVariant m_bandOrRequest;
};
