#pragma once
#include <QDialog>

#include <settings/model/proto/RadioSettings.pb.h>
#include <settings/model/radio/RadioSettingsSink.h>

using BandCategory = makesdr_BandCategoryPb;

class Bands;

namespace Ui
{
  class QtBandDialog;
}

using BandUpdateCallback = std::function<void(const BandName&)>;

template<typename T, void (T::*MemberFn)(const BandName&)>
inline BandUpdateCallback makeBandUpdateCallback(T* self)
{
  return [self](const BandName& bandName) {
    (self->*MemberFn)(bandName);
  };
}

class QtBandDialog : public QWidget
{
  Q_OBJECT
public:
  explicit QtBandDialog(
    BandCategoryList& bandCategories,
    const char * selectedBandName,
    BandUpdateCallback& bandUpdateCallback,
    QWidget *parent = nullptr);

  ~QtBandDialog() override;

  void setSelectedBand(const char * bandName);

protected:
  void addCategoryTabs(const char * selectedBandName);
  void addCategoryTab(const BandCategory& category, bool isSelected, const char * selectedBandName);
  void updateTabs(const char * bandName);
  void updateBandButtons(const char * bandName);
  void updateBandButtons(const Band* band);

private:
  Ui::QtBandDialog *ui;
  BandCategoryList& m_bandCategories;
  BandUpdateCallback& m_bandUpdateCallback;
  QList<QPushButton*> m_bandButtons;
};