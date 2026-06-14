#pragma once
#include <cstdint>

enum class SignalId : uint8_t
{
  // GPIO signals
  GPIO_BEGIN = 0,
  SIGNAL_GPIO_1 = GPIO_BEGIN,
  SIGNAL_GPIO_2,
  SIGNAL_GPIO_3,

  SIGNAL_COUNT
};
