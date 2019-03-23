#include <RedBot.h>
#include "redbot_helpers.hh"

auto motors = RedBotMotors();
const int LED_PIN = 13;

void verify_motors()
{
  redbot::move::forward(motors, Speed(50), Time(2000));
  redbot::move::backward(motors, Speed(50), Time(2000));

  redbot::move::forward(motors, Speed(100), Time(2000));
  redbot::move::backward(motors, Speed(100), Time(2000));

  redbot::move::forward(motors, Speed(150), Time(2000));
  redbot::move::backward(motors, Speed(150), Time(2000));

  redbot::move::forward(motors, Speed(200), Time(2000));
  redbot::move::backward(motors, Speed(200), Time(2000));

  redbot::move::forward(motors, Speed(250), Time(2000));
  redbot::move::backward(motors, Speed(250), Time(2000));
}

void setup()
{
  redbot::move::right_v2(motors, Angle(200));
}

void loop()
{
  redbot::blink_led(LED_PIN, Time(1000));
  redbot::move::forward(motors, Speed(200), Time(2000));
  redbot::move::backward(motors, Speed(200), Time(2000));

  redbot::move::right_v2(motors, Angle(200));
}
