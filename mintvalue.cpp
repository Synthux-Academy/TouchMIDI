#include "mintvalue.h"
#include <math.h>

using namespace synthux;

MIntValue::MIntValue(): 
_init_value   { 0 },
_value        { 0 },
_is_active    { false },
_is_tracking  { false }
{};

uint8_t MIntValue::Process(const uint8_t value, const bool active) {
  if (!_set_active(active, value)) {
    _is_tracking = false;
    return _value;
  }
  _is_tracking =  value != _value;
  _value = value;
  return _value;
};

bool MIntValue::_set_active(const bool active, const uint8_t value) {
  if (active && !_is_active) {
    _value = value;
  }
  _is_active = active;
  return active;
};
