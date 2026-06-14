#include <cstdint>
#include <private/firmware_instance.h>
#include <private/signals_mapping.h>
#include <pico/stdlib.h>

int main()
{
  using namespace Hardware_layer;

  Runtime_Environment::Firmware& firmware = Runtime_Environment::get_firmware_instance();
  firmware.configure(signalConfigs);
  firmware.init(signalConfigs);

  while (true)
  {
    static bool state = true;
    firmware.get_signal(SignalId::SIGNAL_GPIO_1).write(state);
    firmware.get_signal(SignalId::SIGNAL_GPIO_2).write(state);
    firmware.get_signal(SignalId::SIGNAL_GPIO_3).write(state);
    state = !state;
    sleep_ms(1000);
  }

  return 0;
}
