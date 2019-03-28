#pragma once
#ifndef UNITS_H_
#define UNITS_H_

#include "RedBotHelpersImpl.hh"

/// Duration units
redbot::Seconds operator"" _s(unsigned long long value);
redbot::Seconds operator"" _s(long double value);

redbot::Milliseconds operator"" _ms(unsigned long long value);

/// Distance units
redbot::Meters operator"" _m(unsigned long long value);
redbot::Meters operator"" _m(long double value);

redbot::Millimeters operator"" _mm(unsigned long long value);
redbot::Millimeters operator"" _mm(long double value);

redbot::Centimeters operator"" _cm(unsigned long long value);
redbot::Centimeters operator"" _cm(long double value);

redbot::Angle operator"" _degrees(unsigned long long value);
redbot::Angle operator"" _deg(unsigned long long value);

#endif  // UNITS_H_
