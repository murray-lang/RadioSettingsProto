#pragma once
#include <QObject>

// Base class to provide QObject functionality for QtSettingsControlSinkT template
// This allows the template to derive from QObject without needing Q_OBJECT itself
class QtSettingsControlSinkBase : public QObject
{
  Q_OBJECT
public:
  QtSettingsControlSinkBase() = default;
  ~QtSettingsControlSinkBase() override = default;

protected:
  // QObject cannot be moved or copied
  QtSettingsControlSinkBase(const QtSettingsControlSinkBase&) = delete;
  QtSettingsControlSinkBase& operator=(const QtSettingsControlSinkBase&) = delete;
  QtSettingsControlSinkBase(QtSettingsControlSinkBase&&) = delete;
  QtSettingsControlSinkBase& operator=(QtSettingsControlSinkBase&&) = delete;
};
