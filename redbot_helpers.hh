#include <RedBot.h>
#include "named_type.hh"

using Speed = util::named_type<int, struct SpeedTag>;
using Time = util::named_type<int, struct TimeTag>;
using Angle = util::named_type<int, struct AngleTag>;

namespace redbot
{

/// Basic function to blink LED
void blink_led(const int pin, const Time);

namespace move
{

/// Function to move redbot forward
/// @param  Speed   The power for the motors (0 - 255)
/// @param  Time    The duration the redbot should go forward (milliseconds)
void forward(RedBotMotors& rbm, const Speed, const Time);

/// Function to move redbot forward
/// @param  Speed    The power for the motors (0 - 255)
/// @param  Time     The duration the redbot should go forward (milliseconds)
void backward(RedBotMotors& rbm, const Speed, const Time);

void right(RedBotMotors& rbm, const Speed, const Angle);

void right_v2(RedBotMotors& rbm, const Angle);

void left(RedBotMotors& rbm, const Speed, const Angle);

}  // namespace move

}  // namespace redbot
