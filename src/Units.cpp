#include "include/Units.hh"

redbot::Seconds operator"" _s(unsigned long long value)
{
  return redbot::Seconds(value);
}

redbot::Seconds operator"" _s(long double value)
{
  return redbot::Seconds(value);
}

redbot::Milliseconds operator"" _ms(unsigned long long value)
{
  return redbot::Milliseconds(value);
}

redbot::Meters operator"" _m(unsigned long long value)
{
  return redbot::Meters(value);
}

redbot::Meters operator"" _m(long double value)
{

  return redbot::Meters(value);
}

redbot::Millimeters operator"" _mm(unsigned long long value)
{

  return redbot::Millimeters(value);
}

redbot::Millimeters operator"" _mm(long double value)
{

  return redbot::Millimeters(value);
}

redbot::Centimeters operator"" _cm(unsigned long long value)
{
  return redbot::Centimeters(value);
}

redbot::Centimeters operator"" _cm(long double value)
{
  return redbot::Centimeters(value);
}

redbot::Angle operator"" _degrees(unsigned long long value)
{
  return redbot::Angle(value);
}

redbot::Angle operator"" _deg(unsigned long long value)
{
  return redbot::Angle(value);
}

namespace units
{

redbot::Millimeters m_to_mm(const redbot::Meters distance_m)
{
  return redbot::Millimeters(distance_m.get() * M_TO_MM);
}

redbot::Millimeters cm_to_mm(const redbot::Centimeters distance_cm)
{
  return redbot::Millimeters(distance_cm.get() * CM_TO_MM);
}

redbot::Milliseconds s_to_ms(const redbot::Seconds duration_s)
{
  return redbot::Milliseconds(duration_s.get() * S_TO_MS);
}

}  // namespace units
