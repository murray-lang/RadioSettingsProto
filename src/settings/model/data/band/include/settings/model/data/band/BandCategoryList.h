#pragma once

#include <ResultCode.h>
#include <settings/model/proto/RadioSettings.pb.h>
#include "BandTypes.h"


#ifdef USE_ETL
#include <etl/span.h>

using BandCategorySpan = etl::span<const makesdr_BandCategoryPb, MAX_BAND_CATEGORIES>;
#else
#include <span>
using BandCategorySpan = std::span<const makesdr_BandCategoryPb>;
#endif

class BandCategoryList
{
public:
  BandCategoryList(const makesdr_BandCategoryListPb& raw);

  [[nodiscard]] uint32_t count() const { return m_rawSettings.categories_count; }

  [[nodiscard]] const BandCategorySpan& categories() const { return m_categories; }

  [[nodiscard]] const makesdr_BandCategoryPb* findCategory(const BandCategoryName& name) const;
  [[nodiscard]] int findCategoryIndex(const BandCategoryName& name) const;
  [[nodiscard]] const makesdr_BandPb* findBand(const BandName& name) const;
  [[nodiscard]] const makesdr_BandCategoryPb* findCategoryOfBand(const BandName& name) const;
  [[nodiscard]] int findCategoryIndexOfBand(const BandName& name) const;



protected:

  const makesdr_BandCategoryListPb& m_rawSettings;
  BandCategorySpan m_categories;
};