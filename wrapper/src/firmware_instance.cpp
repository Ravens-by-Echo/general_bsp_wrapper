#include <private/firmware_instance.h>

namespace Runtime_Environment
{
  Firmware& get_firmware_instance()
  {
    static Firmware instance;
    return instance;
  }

  SignalHandle Firmware::get_signal(SignalId id)
  {
    return SignalHandle(*this, id);
  }

  void Firmware::configure(const SignalConfig* configs)
  {
    for (std::size_t i = 0; i < MAX_SIGNALS; ++i)
    {
      const std::size_t index = static_cast<std::size_t>(configs[i].id);

      m_signals[index].isConfigured = true;
      m_signals[index].config = configs[i];
    }
  }

  void Firmware::init(const SignalConfig* configs)
  {
    for (std::size_t i = 0; i < MAX_SIGNALS; ++i)
    {
      if (m_signals[i].isConfigured)
      {
        m_signals[i].config.interface->configure(&m_signals[i].config);
        m_signals[i].config.interface->init(&m_signals[i].config);
      }
    }
  }

  int32_t Firmware::read(SignalId id) const
  {
    const std::size_t index = static_cast<std::size_t>(id);
    if (index >= MAX_SIGNALS || !m_signals[index].isConfigured)
    {
      return false;
    }

    const int32_t value = m_signals[index].config.interface->read(&m_signals[index].config);
    return value;
  }

  void Firmware::write(SignalId id, bool state)
  {
    const std::size_t index = static_cast<std::size_t>(id);
    if (index >= MAX_SIGNALS || !m_signals[index].isConfigured)
    {
      return;
    }

    m_signals[index].config.interface->write(&m_signals[index].config, state);
  }

}
