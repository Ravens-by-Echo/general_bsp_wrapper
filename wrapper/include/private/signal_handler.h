#pragma once
#include <private/firmware_instance.h>

namespace Runtime_Environment
{
  class Firmware; // Forward declaration

  class SignalHandle
  {
    public:
      SignalHandle(Firmware& fw, SignalId id);

      int32_t read() const;
      void write(bool state);

    private:
      Firmware& m_firmware;
      SignalId m_id;
  };
}
