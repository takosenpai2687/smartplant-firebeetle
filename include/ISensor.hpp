#pragma once

#include <Arduino.h>

namespace SmartPlant {

class ISensor {
  private:
    String name;

  protected:
    ISensor(const String &name) : name(name) {}

  public:
    virtual void ReadData() = 0;
    virtual const double_t GetData() const = 0;
    const String &GetName() const { return name; }
    virtual ~ISensor() = default;
};

} // namespace SmartPlant
