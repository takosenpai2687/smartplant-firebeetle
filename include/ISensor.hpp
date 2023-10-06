#pragma once

class ISensor {
  protected:
    String name;
    ISensor(const String &name) : name(name) {}

  public:
    virtual void ReadData() = 0;
    virtual double_t GetData() const = 0;
    const String &GetName() const { return name; }
    virtual ~ISensor() = default;
};
