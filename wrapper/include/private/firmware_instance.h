#pragma once

#include <private/fixed_signals_enum.h>
#include <private/signal_handler.h>
#include <private/gpio_wrapper.h>

using namespace Hardware_layer;

namespace Runtime_Environment
{
  class SignalHandle; // Forward declaration

  class Firmware
  {
    public:
      Firmware() = default;
      ~Firmware() = default;

      void configure(const SignalConfig* configs);
      void init(const SignalConfig* configs);
      int32_t read(SignalId id) const;
      void write(SignalId id, bool state);

      SignalHandle get_signal(SignalId id);

    private:
      Firmware(const Firmware&) = delete;
      Firmware& operator=(const Firmware&) = delete;
      Firmware(Firmware&&) = delete;
      Firmware& operator=(Firmware&&) = delete;

      struct SignalEntry
      {
        bool isConfigured = false;
        SignalConfig config{};
      };

      static constexpr std::size_t MAX_SIGNALS = static_cast<std::size_t>(SignalId::SIGNAL_COUNT);
      SignalEntry m_signals[MAX_SIGNALS]{};
  };

  Firmware& get_firmware_instance();
}
