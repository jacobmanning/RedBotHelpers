#pragma once
#ifndef REDBOT_HELPERS_IMPL_H_
#define REDBOT_HELPERS_IMPL_H_

#include <RedBot.h>
#include "named_type/named_type.hh"

namespace redbot
{

constexpr int LED_PIN = 13;
constexpr int COUNTS_PER_REV = 192;
constexpr int LEFT_ENCODER_PIN = A2;
constexpr int RIGHT_ENCODER_PIN = 10;
constexpr int MOTORS_STOP = 0;

using Angle = util::named_type<int, struct AngleTag>;

using Milliseconds = util::named_type<int, struct MillisecondsTag>;
using Seconds = util::named_type<double, struct SecondsTag>;

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

  void move_backward(const Speed, const Milliseconds);
  void move_backward(const Milliseconds);
  void move_backward(const Speed, const Seconds);
  void move_backward(const Seconds);

private:
  RedBotMotors motors_;
  RedBotEncoder encoder_;
};

/// Basic function to blink LED
void blink_led(const int pin, const Milliseconds);

namespace move
{

/// Function to move redbot forward
/// @param  Speed   The power for the motors (0 - 255)
/// @param  Milliseconds    The duration the redbot should go forward (milliseconds)
void forward(RedBot&, const Speed, const Milliseconds);

void forward(RedBot&, const Speed, const Seconds);

/// Function to move redbot forward
/// @param  Speed    The power for the motors (0 - 255)
/// @param  Milliseconds     The duration the redbot should go forward (milliseconds)
void backward(RedBot&, const Speed, const Milliseconds);

void backward(RedBot&, const Speed, const Milliseconds);

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
