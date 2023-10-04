#pragma once

class ISensor {
  protected:
    std::string name;
    ISensor(const std::string &name) : name(name) {}

  public:
    virtual void ReadData() = 0;
    virtual double_t GetData() const = 0;
    const std::string &GetName() const { return name; }
    virtual ~ISensor() = default;
};
