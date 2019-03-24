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

using Speed = util::named_type<int, struct SpeedTag>;
using Time = util::named_type<int, struct TimeTag>;
using Angle = util::named_type<int, struct AngleTag>;

class RedBot
{
public:
  RedBot();

  RedBotMotors& get_motors();
  RedBotEncoder& get_encoder();

  void move_forward(const Speed s, const Time t);
  void move_backward(const Speed s, const Time t);

private:
  RedBotMotors motors_;
  RedBotEncoder encoder_;
};

/// Creates a new RedBot object
RedBot init();

/// Basic function to blink LED
void blink_led(const int pin, const Time);

namespace move
{

/// Function to move redbot forward
/// @param  Speed   The power for the motors (0 - 255)
/// @param  Time    The duration the redbot should go forward (milliseconds)
// void forward(RedBotMotors& motors, const Speed, const Time);
void forward(RedBot& rb, const Speed, const Time);

/// Function to move redbot forward
/// @param  Speed    The power for the motors (0 - 255)
/// @param  Time     The duration the redbot should go forward (milliseconds)
// void backward(RedBotMotors& motors, const Speed, const Time);
void backward(RedBot& rb, const Speed, const Time);

}  // namespace move

namespace experimental
{

namespace v1
{

void pivot_right(RedBot& rb, const Angle);
void pivot_right(RedBot& rb, const Speed, const Angle);

void pivot_left(RedBot& rb, const Angle);
void pivot_left(RedBot& rb, const Speed, const Angle);

}  // namespace v1

namespace v2
{

void pivot_right(RedBot& rb, const Angle);
void pivot_right(RedBot& rb, const Speed, const Angle);

void pivot_left(RedBot& rb, const Angle);
void pivot_left(RedBot& rb, const Speed, const Angle);

}  // namespace v2

}  // namespace experimental

}  // namespace redbot

#endif  // REDBOT_HELPERS_IMPL_H_
