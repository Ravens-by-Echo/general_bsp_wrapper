#pragma once

#include <cstdint>
#include <cstddef>
#include <private/fixed_signals_enum.h>

namespace Hardware_layer
{
  class HardwareInterface;

  enum class SignalDirection : uint8_t
  {
    Input = 0,
    Output
  };

  struct SignalConfig
  {
    SignalId id;
    uint8_t pin;
    SignalDirection direction;
    HardwareInterface* interface;
    bool initialState;
  };

  class HardwareInterface
  {
    public:
      virtual ~HardwareInterface() = default;

      virtual void configure(const SignalConfig* config) = 0;
      virtual void init(const SignalConfig* configs) = 0;
      virtual int32_t read(const SignalConfig* configs) const = 0;
      virtual void write(const SignalConfig* configs, bool state) = 0;
  };
}
