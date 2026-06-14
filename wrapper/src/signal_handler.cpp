#include <private/signal_handler.h>

namespace Runtime_Environment
{
  SignalHandle::SignalHandle(Firmware& fw, SignalId id) :
      m_firmware(fw),
      m_id(id)
  {
  }

  int32_t SignalHandle::read() const
  {
    return m_firmware.read(m_id);
  }

  void SignalHandle::write(bool state)
  {
    m_firmware.write(m_id, state);
  }

}
