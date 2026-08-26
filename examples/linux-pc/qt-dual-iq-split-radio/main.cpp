#include <radios/iq/SplitBandDualIqRadio.h>
#include <settings/model/radios/iq/SplitBandDualIqRxTxSettings.h>
#include <settings/model/data/radio/generalCoverageRadioLookup.h>
#include <config/json/RadioConfig.json.h>

#include <fstream>

// #include <QCoreApplication>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <ui/qt/util/QtUtil.h>


SplitBandSettingsCache bandSettingsCache;
RadioLookup radioLookup(generalCoverageRadioLookup);

int main(int argc, char *argv[])
{

  // QCoreApplication app(argc, argv);

  const QString configHome = QDir::homePath() + "/.config/nexusdr";
  const QString configPath = configHome + "/dual-iq-split-radio-test.json";
  Config::Radio::Fields radioConfig;
  ResultCode rc = loadRadioConfig(configPath, radioConfig);
  if (rc != ResultCode::OK) {
    return -1;
  }
  SplitBandDualIqRadio radio(radioLookup, bandSettingsCache);
  rc = radio.configure(radioConfig);
  if (rc != ResultCode::OK) {
    return -1;
  }

  QApplication app(argc, argv);

  rc = loadStylesheets(configHome, app);
  if (rc != ResultCode::OK) {
    qDebug() << "Error loading stylesheets: " << static_cast<uint32_t>(rc);
    return -1;
  }

  rc = radio.start();
  if (rc != ResultCode::OK) {
    qDebug() << "Error starting radio: " << static_cast<uint32_t>(rc);
    return 1;
  }

  int rc2 = app.exec();

  radio.stop();

  // while (true) {
  //   // QCoreApplication::processEvents();
  //   std::this_thread::sleep_for(std::chrono::milliseconds(100));
  // }

  return rc2;
}