#include <RedBot.h>
#include "redbot_helpers.hh"

namespace redbot
{

void blink_led(const int pin, const Time wait_time)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(wait_time.get());
  digitalWrite(pin, LOW);
  delay(wait_time.get());
}

namespace move
{

void go_straight(RedBotMotors& rbm, const Speed s, const Time t)
{
  motors.drive(s.get());
  delay(t.get());
  motors.stop();
}

void forward(RedBotMotors& rbm, const Speed s, const Time t)
{
  go_straight(rbm, s, t);
}

void backward(RedBotMotors& rbm, const Speed s, const Time t)
{
  go_straight(rbm, Speed(-s.get()), t);
}

void turn(RedBotMotors& rbm, const Speed s, const Angle right, const Angle left)
{
  motors.rightMotor(right.get());
  motors.leftMotor(left.get());
  delay(s.get());
  motors.stop();
}

///
///
/// IDEA!
/// Use the wheel encoder to measure how far the wheel has travelled to do a precise angle
///
///

void turn_v2(RedBotMotors& rbm, const Angle right, const Angle left)
{
  motors.rightMotor(right.get());
  motors.leftMotor(left.get());

  if (right.get() > 0)
  {
    delay(right.get());
  }
  else
  {
    delay(left.get());
  }

  motors.stop();
}

void right(RedBotMotors& rbm, const Speed s, const Angle a)
{
  turn(rbm, s, Angle(-a.get()), Angle(a.get()));
}

void right_v2(RedBotMotors& rbm, const Angle a)
{
  turn_v2(rbm, Angle(a.get()), Angle(-a.get()));
}

void left(RedBotMotors& rbm, const Speed s, const Angle a)
{
  turn(rbm, s, Angle(a.get()), Angle(-a.get()));
}

}  // namespace move

}  // namespace redbot
