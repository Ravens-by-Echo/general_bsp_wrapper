#pragma once

#include <interface/hal_interface.h>

namespace Hardware_layer
{
  class GpioWrapper : public HardwareInterface
  {
    public:
      void configure(const SignalConfig* config) override;
      void init(const SignalConfig* config) override;
      int32_t read(const SignalConfig* configs) const override;
      void write(const SignalConfig* configs, bool state) override;
  };

  GpioWrapper& get_gpio_instance();
}
