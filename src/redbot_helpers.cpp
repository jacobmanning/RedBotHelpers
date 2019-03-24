#include <RedBot.h>
#include "include/redbot_helpers_impl.hh"

namespace redbot
{

RedBot::RedBot() :
  encoder_{RedBotEncoder(LEFT_ENCODER_PIN, RIGHT_ENCODER_PIN)} {}

RedBotMotors& RedBot::get_motors()
{
  return motors_;
}

RedBotEncoder& RedBot::get_encoder()
{
  return encoder_;
}

void RedBot::move_forward(const Speed s, const Time t)
{
  move::forward(*this, s, t);
}

void RedBot::move_backward(const Speed s, const Time t)
{
  move::backward(*this, s, t);
}

RedBot init()
{
  return RedBot();
}

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

void go_straight(RedBotMotors& motors, const Speed s, const Time t)
{
  motors.drive(s.get());
  delay(t.get());
  motors.stop();
}

void forward(RedBot& rb, const Speed s, const Time t)
{
  go_straight(rb.get_motors(), s, t);
}

void backward(RedBot& rb, const Speed s, const Time t)
{
  go_straight(rb.get_motors(), Speed(-s.get()), t);
}

}  // namespace move

namespace experimental
{

namespace v1
{

void turn(RedBotMotors& motors, const Speed s, const Angle a)
{
  motors.rightMotor(s.get());
  motors.leftMotor(s.get());

  const auto angle = a.get();

  if (angle <= 90)
  {
    delay(angle * 12);
  }
  else if (angle <= 90)
  {
    delay(angle * 9);
  }
  else if (angle <= 180)
  {
    delay(angle * 8);
  }
  else if (angle <= 270)
  {
    delay(angle * 7);
  }
  else if (angle < 360)
  {
    delay(angle * 4);
  }

  motors.stop();
}

void pivot_right(RedBot& rb, const Speed s, const Angle a)
{
  turn(rb.get_motors(), Speed(-s.get()), a);
}

void pivot_right(RedBot& rb, const Angle a)
{
  pivot_right(rb, Speed(100), a);
}

void pivot_left(RedBot& rb, const Speed s, const Angle a)
{
  turn(rb.get_motors(), s, a);
}

void pivot_left(RedBot& rb, const Angle a)
{
  pivot_left(rb, Speed(100), a);
}

}  // namespace v1

namespace v2
{

boolean check_if_right_turn(const Speed s)
{
  return s.get() < 0;
}

int get_expected_left_ticks(const Angle desired_angle, const boolean is_right_turn)
{
  return desired_angle.get();
}

int get_expected_right_ticks(const Angle desired_angle, const boolean is_right_turn)
{
  return desired_angle.get();
}

void turn(RedBot& rb, const Speed s, const Angle a)
{
  auto& encoder = rb.get_encoder();
  encoder.clearEnc(BOTH);

  auto& motors = rb.get_motors();

  const auto is_right_turn = check_if_right_turn(s);
  const auto expected_left_ticks = get_expected_left_ticks(a, is_right_turn);
  const auto expected_right_ticks = get_expected_right_ticks(a, is_right_turn);

  auto rotate_left = true;
  auto rotate_right = true;

  while (rotate_left || rotate_right)
  {
    const auto left_ticks = abs(encoder.getTicks(LEFT));
    const auto right_ticks = abs(encoder.getTicks(RIGHT));

    Serial.print("[ DEBUG ] left_ticks = ");
    Serial.print(left_ticks);
    Serial.print(", expected_left_ticks = ");
    Serial.println(expected_left_ticks);
    Serial.print("[ DEBUG ] right_ticks = ");
    Serial.print(right_ticks);
    Serial.print(", expected_right_ticks = ");
    Serial.println(expected_right_ticks);

    rotate_left = left_ticks < expected_left_ticks;
    rotate_right = right_ticks < expected_right_ticks;

    if (rotate_left)
    {
      motors.leftMotor(s.get());
    }
    else
    {
      motors.leftMotor(0);
    }

    if (rotate_right)
    {
      motors.rightMotor(s.get());
    }
    else
    {
      motors.rightMotor(0);
    }
  }
}

void pivot_right(RedBot& rb, const Speed s, const Angle a)
{
  turn(rb, Speed(-s.get()), a);
}

void pivot_right(RedBot& rb, const Angle a)
{
  pivot_right(rb, Speed(100), a);
}

void pivot_left(RedBot& rb, const Speed s, const Angle a)
{
  turn(rb, s, a);
}

void pivot_left(RedBot& rb, const Angle a)
{
  pivot_left(rb, Speed(100), a);
}

} // namespace v2

}  // namespace experimental

}  // namespace redbot
