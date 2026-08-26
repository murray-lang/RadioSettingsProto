#pragma once
#include <ResultCode.h>
#include <QApplication>
#include <QString>
#include <config/struct/RadioConfig.h>

extern ResultCode loadRadioConfig(const QString& configHome, Config::Radio::Fields& radioConfig);
extern ResultCode loadStylesheets(const QString& configHome, QApplication& app);
