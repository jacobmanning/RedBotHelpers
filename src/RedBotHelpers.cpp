#include <RedBot.h>
#include "include/RedBotHelpersImpl.hh"

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

void RedBot::move_forward(const Speed speed, const Time time)
{
  move::forward(*this, speed, time);
}

void RedBot::move_forward(const Time time)
{
  move_forward(MEDIUM_SPEED, time);
}

void RedBot::move_backward(const Speed speed, const Time time)
{
  move::backward(*this, speed, time);
}

void RedBot::move_backward(const Time time)
{
  move_backward(MEDIUM_SPEED, time);
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

void go_straight(RedBotMotors& motors, const Speed speed, const Time time)
{
  motors.drive(speed.get());
  delay(time.get());
  motors.stop();
}

void forward(RedBot& redbot, const Speed speed, const Time time)
{
  go_straight(redbot.get_motors(), speed, time);
}

void backward(RedBot& redbot, const Speed speed, const Time time)
{
  go_straight(redbot.get_motors(), Speed(-speed.get()), time);
}

}  // namespace move

namespace experimental
{

namespace v1
{

void turn(RedBotMotors& motors, const Speed speed, const Angle angle)
{
  motors.rightMotor(speed.get());
  motors.leftMotor(speed.get());

  if (angle.get() <= 90)
  {
    delay(angle.get() * 12);
  }
  else if (angle.get() <= 90)
  {
    delay(angle.get() * 9);
  }
  else if (angle.get() <= 180)
  {
    delay(angle.get() * 8);
  }
  else if (angle.get() <= 270)
  {
    delay(angle.get() * 7);
  }
  else if (angle.get() < 360)
  {
    delay(angle.get() * 4);
  }

  motors.stop();
}

void pivot_right(RedBot& redbot, const Speed speed, const Angle angle)
{
  turn(redbot.get_motors(), Speed(-speed.get()), angle);
}

void pivot_right(RedBot& redbot, const Angle angle)
{
  pivot_right(redbot, MEDIUM_SPEED, angle);
}

void pivot_left(RedBot& redbot, const Speed speed, const Angle angle)
{
  turn(redbot.get_motors(), speed, angle);
}

void pivot_left(RedBot& redbot, const Angle angle)
{
  pivot_left(redbot, MEDIUM_SPEED, angle);
}

}  // namespace v1

namespace v2
{

boolean check_if_right_turn(const Speed speed)
{
  return speed.get() < 0;
}

int get_expected_left_ticks(const Angle desired_angle, const boolean is_right_turn)
{
  return desired_angle.get();
}

int get_expected_right_ticks(const Angle desired_angle, const boolean is_right_turn)
{
  return desired_angle.get();
}

void turn(RedBot& redbot, const Speed speed, const Angle angle)
{
  auto& encoder = redbot.get_encoder();
  encoder.clearEnc(BOTH);

  auto& motors = redbot.get_motors();

  const auto is_right_turn = check_if_right_turn(speed);
  const auto expected_left_ticks = get_expected_left_ticks(angle, is_right_turn);
  const auto expected_right_ticks = get_expected_right_ticks(angle, is_right_turn);

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
      motors.leftMotor(speed.get());
    }
    else
    {
      motors.leftMotor(MOTORS_STOP);
    }

    if (rotate_right)
    {
      motors.rightMotor(speed.get());
    }
    else
    {
      motors.rightMotor(MOTORS_STOP);
    }
  }
}

void pivot_right(RedBot& redbot, const Speed speed, const Angle angle)
{
  turn(redbot, Speed(-speed.get()), angle);
}

void pivot_right(RedBot& redbot, const Angle angle)
{
  pivot_right(redbot, MEDIUM_SPEED, angle);
}

void pivot_left(RedBot& redbot, const Speed speed, const Angle angle)
{
  turn(redbot, speed, angle);
}

void pivot_left(RedBot& redbot, const Angle angle)
{
  pivot_left(redbot, MEDIUM_SPEED, angle);
}

} // namespace v2

}  // namespace experimental

}  // namespace redbot
