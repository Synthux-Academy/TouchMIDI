#pragma once
#include "nocopy.h"
#include <stdint.h>

namespace synthux {

class MIntValue {
public:
  MIntValue();
  ~MIntValue() {}

uint8_t Process(const uint8_t value, const bool active);

uint8_t Value() const { return _value; }

void Set(const uint8_t value) {
  _is_tracking = false;
  _is_active = false;
  _value = value;
}

bool IsTracking() {
  return _is_tracking;
}

private:
  NOCOPY(MIntValue)

  bool _set_active(const bool active, const uint8_t value);

  uint8_t _init_value;
  uint8_t _value;
  bool _is_active;
  bool _is_tracking;
};

};
