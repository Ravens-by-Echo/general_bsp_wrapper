#pragma once

#include <interface/hal_interface.h>
#include <private/fixed_signals_enum.h>
#include <private/gpio_wrapper.h>
#include <cassert>
#include <iterator>

namespace Hardware_layer
{
  static const SignalConfig signalConfigs[] = {
    {SignalId::SIGNAL_GPIO_1, 25, SignalDirection::Output, &get_gpio_instance(), true},
    {SignalId::SIGNAL_GPIO_2, 0, SignalDirection::Output, &get_gpio_instance(), false},
    {SignalId::SIGNAL_GPIO_3, 1, SignalDirection::Output, &get_gpio_instance(), false},
  };

  static_assert(std::size(signalConfigs) == static_cast<std::size_t>(SignalId::SIGNAL_COUNT), "Signal count mismatch");
}
