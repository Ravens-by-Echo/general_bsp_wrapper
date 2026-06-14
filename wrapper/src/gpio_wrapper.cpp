#include <private/gpio_wrapper.h>
#include <pico/stdlib.h>

namespace Hardware_layer
{

  void GpioWrapper::configure(const SignalConfig* config)
  {
    (void)config;
  }

  void GpioWrapper::init(const SignalConfig* config)
  {
      gpio_init(config->pin);
      gpio_set_dir(config->pin, static_cast<bool>(config->direction));
  }

  int32_t GpioWrapper::read(const SignalConfig* configs) const
  {
    if (configs == nullptr)
    {
      return false;
    }

    return static_cast<int32_t>(gpio_get(configs->pin));
  }

  void GpioWrapper::write(const SignalConfig* configs, bool state)
  {
    if (configs == nullptr)
    {
      return;
    }

    gpio_put(configs->pin, state);
  }

  GpioWrapper& get_gpio_instance()
  {
    static GpioWrapper instance;
    return instance;
  }
}
