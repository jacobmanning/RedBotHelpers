#pragma once
#ifndef REDBOT_HELPERS_IMPL_H_
#define REDBOT_HELPERS_IMPL_H_

#include <RedBot.h>
#include "named_type/named_type.hh"

namespace redbot
{

constexpr static int LED_PIN = 13;
constexpr static int COUNTS_PER_REV = 192;
constexpr static double MM_PER_REV = 204.216;
constexpr static int LEFT_ENCODER_PIN = A2;
constexpr static int RIGHT_ENCODER_PIN = 10;

/// Alias strong type for a degree the redbot will turn
/// _deg and _degrees literal operators
using Angle = util::named_type<int, struct AngleTag>;

/// Alias strong type for duration in milliseconds
/// _ms literal operator
using Milliseconds = util::named_type<int, struct MillisecondsTag>;
/// Alias strong type for duration in seconds
/// _s literal operator
using Seconds = util::named_type<double, struct SecondsTag>;

/// Alias strong type for distance in millimeters
/// _mm literal operator
using Millimeters = util::named_type<double, struct MillimetersTag>;
/// Alias strong type for distance in centimeters
/// _cm literal operator
using Centimeters = util::named_type<double, struct CentimetersTag>;
/// Alias strong type for distance in meters
/// _m literal operator
using Meters = util::named_type<double, struct MetersTag>;

using Speed = util::named_type<int, struct SpeedTag>;
const Speed LOW_SPEED = Speed{80};
const Speed MEDIUM_SPEED = Speed{160};
const Speed HIGH_SPEED = Speed{240};

class RedBot
{
public:
  RedBot();

  RedBotMotors& get_motors();
  RedBotEncoder& get_encoder();

  void move_forward(const Speed, const Milliseconds);
  void move_forward(const Milliseconds);
  void move_forward(const Speed, const Seconds);
  void move_forward(const Seconds);

  void move_forward(const Speed, const Millimeters);
  void move_forward(const Millimeters);
  void move_forward(const Speed, const Centimeters);
  void move_forward(const Centimeters);
  void move_forward(const Speed, const Meters);
  void move_forward(const Meters);

  void move_backward(const Speed, const Milliseconds);
  void move_backward(const Milliseconds);
  void move_backward(const Speed, const Seconds);
  void move_backward(const Seconds);

  void move_backward(const Speed, const Millimeters);
  void move_backward(const Millimeters);
  void move_backward(const Speed, const Centimeters);
  void move_backward(const Centimeters);
  void move_backward(const Speed, const Meters);
  void move_backward(const Meters);

private:
  RedBotMotors motors_;
  RedBotEncoder encoder_;
};

/// Basic function to blink LED
/// @param  pin   The pin to blink (LED_PIN = 13 for redbot)
/// @param  Milliseconds  The duration the LED should stay on
void blink_led(const int pin, const Milliseconds);

/// Basic function to blink LED
/// @param  pin   The pin to blink (LED_PIN = 13 for redbot)
/// @param  Seconds  The duration the LED should stay on
void blink_led(const int pin, const Seconds);

/// Convert mm to encoder ticks to travel that distance
/// @param Millimeters  The distance to convert to encoder ticks
/// @return   The number of encoder ticks to travel the argument distance
int mm_to_ticks(const Millimeters);

/// Convert encoder ticks to mm
/// @param ticks  The number of encoder ticks
/// @param Millimeters  The distance (mm) travelled in that many encoder ticks
Millimeters ticks_to_mm(const int ticks);

namespace move
{

/// Function to move redbot forward
/// @param  Speed   The power for the motors (0 - 255)
/// @param  Milliseconds    The duration the redbot should go forward (milliseconds)
void forward(RedBot&, const Speed, const Milliseconds);

/// Function to move redbot backward
/// @param  Speed    The power for the motors (0 - 255)
/// @param  Millimeters     The duration the redbot should go backward (millimeters)
void forward(RedBot&, const Speed, const Millimeters);

/// Function to move redbot forward
/// @param  Speed    The power for the motors (0 - 255)
/// @param  Milliseconds     The duration the redbot should go forward (milliseconds)
void backward(RedBot&, const Speed, const Milliseconds);

/// Function to move redbot backward
/// @param  Speed    The power for the motors (0 - 255)
/// @param  Millimeters     The distance the redbot should go backward (millimeters)
void backward(RedBot& , const Speed, const Millimeters);

}  // namespace move

namespace experimental
{

void pivot_right(RedBot&, const Angle);
void pivot_right(RedBot&, const Speed, const Angle);

void pivot_left(RedBot&, const Angle);
void pivot_left(RedBot&, const Speed, const Angle);

}  // namespace experimental

}  // namespace redbot

#endif  // REDBOT_HELPERS_IMPL_H_
