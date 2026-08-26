#include "ui/qt/util/QtUtil.h"

#include <QFile>
#include <QTextStream>
#include <fstream>
#include <ArduinoJson.h>
#include <config/json/RadioConfig.json.h>
#include <qdebug.h>


ResultCode loadRadioConfig(const QString& configPath, Config::Radio::Fields& radioConfig)
{
  ResultCode rc = ResultCode::OK;
  // Resolve config path under the current user's home directory: ~/.config/nexusdr/nexusdr.json

  // const QString configPath = configHome + "/dual-iq-split-radio-test.json";
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

ResultCode loadStylesheets(const QString& configHome, QApplication& app)
{
  ResultCode rc = ResultCode::OK;
  const QString styleSheetPath = configHome + "/nexusdr.qss";
  const QString standardFaceQssPath = configHome + "/StandardFace.qss";

  auto readQssFile = [](const QString& path, QString& qss) -> ResultCode {
    QFile f(path);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
      return ResultCode::ERR_UI_STYLESHEET_OPEN;
    }
    QTextStream ts(&f);
    qss = ts.readAll();
    return ResultCode::OK;
  };

  QString combinedQss;
  QString baseQss;
  rc = readQssFile(styleSheetPath, baseQss);
  if (rc != ResultCode::OK) {
    qDebug() << "Error " << static_cast<uint32_t>(rc) << " reading stylesheet from:" << styleSheetPath;
    return rc;
  }
  if (baseQss.isEmpty()) {
    return ResultCode::ERR_UI_EMPTY_STYLESHEET;
  }
  combinedQss += baseQss;
  combinedQss += "\n";

  QString faceQss;
  rc = readQssFile(standardFaceQssPath, faceQss);
  if (rc == ResultCode::OK && !faceQss.isEmpty()) {
    combinedQss += "\n/* ---- StandardFace.qss ---- */\n";
    combinedQss += faceQss;
    combinedQss += "\n";
    app.setStyleSheet(combinedQss);
  }
  return rc;
}
