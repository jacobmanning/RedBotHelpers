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
