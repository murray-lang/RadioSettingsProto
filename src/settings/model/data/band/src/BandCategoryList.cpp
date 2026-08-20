#include "settings/model/data/band/BandCategoryList.h"

#include "etl/algorithm.h"
#include "settings/model/data/band/BandList.h"

// #include "settings/model/core/ProtobufIo.h"

BandCategoryList::BandCategoryList(const makesdr_BandCategoryListPb& raw)
  : m_rawSettings(raw)
  , m_categories(raw.categories, MAX_BAND_CATEGORIES)
{
}

const makesdr_BandCategoryPb*
BandCategoryList::findCategory(const BandCategoryName& name) const
{
  uint32_t max = count();
  for (uint32_t i = 0; i < max; i++) {
    if (name == m_categories[i].name) {
      return &m_categories[i];
    }
  }
  return nullptr;
}

int
BandCategoryList::findCategoryIndex(const BandCategoryName& name) const
{
  uint32_t max = count();
  for (int i = 0; i < max; i++) {
    if (name == m_categories[i].name) {
      return i;
    }
  }
  return -1;
}

const makesdr_BandPb*
BandCategoryList::findBand(const BandName& name) const
{
  uint32_t max = count();
  for (uint32_t i = 0; i < max; i++) {
    BandList bands(m_categories[i].bands);
    const makesdr_BandPb* band = bands.findBand(name);
    if (band != nullptr) {
      return band;
    }
  }
  return nullptr;
}

const makesdr_BandCategoryPb*
BandCategoryList::findCategoryOfBand(const BandName& name) const
{
  uint32_t max = count();
  for (uint32_t i = 0; i < max; i++) {
    BandList bands(m_categories[i].bands);
    const makesdr_BandPb* band = bands.findBand(name);
    if (band != nullptr) {
      return &m_categories[i];
    }
  }
  return nullptr;
}

int
BandCategoryList::findCategoryIndexOfBand(const BandName& name) const
{
  uint32_t max = count();
  for (int i = 0; i < max; i++) {
    BandList bands(m_categories[i].bands);
    const makesdr_BandPb* band = bands.findBand(name);
    if (band != nullptr) {
      return i;
    }
  }
  return -1;
}

// ResultCode
// BandCategoryList::readProtobuf(const uint8_t *buffer, size_t msg_length) {
//   return ProtobufIo::readProtobuf<makesdr_BandCategoryListPb>(
//     buffer,
//     msg_length,
//     makesdr_BandCategoryListPb_fields,
//     makesdr_BandCategoryListPb_init_zero,
//     m_rawSettings
//   );
// }