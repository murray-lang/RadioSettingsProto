#include <radio/iq/rx/BasicIqRxRadio.h>
#include <settings/model/lookup/radio/generalCoverageRadioLookup.h>
#include <config/json/RadioConfig.json.h>

#include <fstream>

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <ArduinoJson.h>


ResultCode loadRadioConfig(const QString& configHome, Config::Radio::Fields& radioConfig)
{
  ResultCode rc = ResultCode::OK;
  // Resolve config path under the current user's home directory: ~/.config/nexusdr/nexusdr.json

  const QString configPath = configHome + "/rx-radio-test.json";
  if (QFile::exists(configPath)) {
    try {
      std::ifstream f(configPath.toStdString());
      JsonDocument doc;
      DeserializationError error = deserializeJson(doc, f, DeserializationOption::NestingLimit(12));
      if (error) {
        qDebug() << "Failed to parse config at" << configPath << ":" << error.c_str();
        rc = ResultCode::ERR_CONFIG_INVALID_JSON;
      } else if (doc["radio"]) {
        // Prefer fromJson for symmetry with toJson()
        rc = Config::Radio::fromJson(doc["radio"].as<JsonVariantConst>(), radioConfig);
      } else {
        qDebug() << "Config file present but no 'radio' section found:" << configPath;
        rc = ResultCode::ERR_CONFIG_MISSING_RADIO;
      }
    } catch (const std::exception& ex) {
      qDebug() << "Failed to read config at" << configPath << ":" << ex.what();
      rc = ResultCode::ERR_CONFIG_FILE_READ_ERROR;
    }
  } else {
    qDebug() << "No config file found at" << configPath << "; using defaults.";
    rc = ResultCode::ERR_CONFIG_FILE_MISSING;
  }
  return rc;
}


RadioLookup radioLookup(generalCoverageRadioLookup);

int main(int argc, char *argv[])
{

  QCoreApplication app(argc, argv);

  const QString configHome = QDir::homePath() + "/.config/nexusdr";
  Config::Radio::Fields radioConfig;
  ResultCode rc = loadRadioConfig(configHome, radioConfig);
  if (rc != ResultCode::OK) {
    return -1;
  }
  BasicIqRxRadio radio(radioLookup);
  rc = radio.configure(radioConfig);
  if (rc != ResultCode::OK) {
    return -1;
  }
  rc = radio.start();
  if (rc != ResultCode::OK) {
    return -1;
  }

  while (true) {
    // QCoreApplication::processEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}