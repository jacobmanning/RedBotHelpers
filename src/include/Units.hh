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

namespace units
{

constexpr static int M_TO_MM = 1000;
constexpr static int CM_TO_MM = 10;
constexpr static int S_TO_MS = 1000;

redbot::Millimeters m_to_mm(const redbot::Meters);
redbot::Millimeters cm_to_mm(const redbot::Centimeters);

redbot::Milliseconds s_to_ms(const redbot::Seconds);

}  // namespace units

#endif  // UNITS_H_
