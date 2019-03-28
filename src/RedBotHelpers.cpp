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

void RedBot::move_forward(const Speed speed, const Milliseconds duration_ms)
{
  move::forward(*this, speed, duration_ms);
}

void RedBot::move_forward(const Speed speed, const Millimeters distance_mm)
{
  move::forward(*this, speed, distance_mm);
}

void RedBot::move_forward(const Milliseconds duration_ms)
{
  move_forward(MEDIUM_SPEED, duration_ms);
}

void RedBot::move_forward(const Speed speed, const Seconds duration_s)
{
  move_forward(speed, Milliseconds(duration_s.get() * 1000));
}

void RedBot::move_forward(const Seconds duration_s)
{
  move_forward(MEDIUM_SPEED, duration_s);
}

void RedBot::move_forward(const Millimeters distance_mm)
{
  move_forward(MEDIUM_SPEED, distance_mm);
}

void RedBot::move_forward(const Speed speed, const Centimeters distance_cm)
{
  move_forward(speed, Millimeters(distance_cm.get() * 10));
}

void RedBot::move_forward(const Centimeters distance_cm)
{
  move_forward(MEDIUM_SPEED, distance_cm);
}

void RedBot::move_forward(const Speed speed, const Meters distance_m)
{
  move_forward(speed, Millimeters(distance_m.get() * 1000));
}

void RedBot::move_forward(const Meters distance_m)
{

  move_forward(MEDIUM_SPEED, distance_m);
}

void RedBot::move_backward(const Speed speed, const Milliseconds duration_ms)
{
  move::backward(*this, speed, duration_ms);
}

void RedBot::move_backward(const Speed speed, const Millimeters distance_mm)
{
  move::backward(*this, speed, distance_mm);
}

void RedBot::move_backward(const Milliseconds duration_ms)
{
  move_backward(MEDIUM_SPEED, duration_ms);
}

void RedBot::move_backward(const Speed speed, const Seconds duration_s)
{
  move_backward(speed, Milliseconds(duration_s.get() * 1000));
}

void RedBot::move_backward(const Seconds duration_s)
{
  move_backward(MEDIUM_SPEED, duration_s);
}

void RedBot::move_backward(const Millimeters distance_mm)
{
  move_backward(MEDIUM_SPEED, distance_mm);
}

void RedBot::move_backward(const Speed speed, const Centimeters distance_cm)
{
  move_backward(speed, Millimeters(distance_cm.get() * 10));
}

void RedBot::move_backward(const Centimeters distance_cm)
{
  move_backward(MEDIUM_SPEED, distance_cm);
}

void RedBot::move_backward(const Speed speed, const Meters distance_m)
{
  move_backward(speed, Millimeters(distance_m.get() * 1000));
}

void RedBot::move_backward(const Meters distance_m)
{

  move_backward(MEDIUM_SPEED, distance_m);
}

void blink_led(const int pin, const Milliseconds wait_time)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(wait_time.get());
  digitalWrite(pin, LOW);
  delay(wait_time.get());
}

int mm_to_ticks(const Millimeters distance_mm)
{
  return static_cast<int>(distance_mm.get() * MM_PER_REV / COUNTS_PER_REV);
}

Millimeters ticks_to_mm(const int ticks)
{
  return Millimeters(ticks * COUNTS_PER_REV / MM_PER_REV);
}

namespace move
{

void go_straight(RedBotMotors& motors, const Speed speed, const Milliseconds duration_ms)
{
  motors.drive(speed.get());
  delay(duration_ms.get());
  motors.stop();
}

void go_straight(RedBot& redbot, const Speed speed, const Millimeters distance_mm)
{
  auto current_ticks = int{0};
  const auto expected_ticks = mm_to_ticks(distance_mm);

  auto& motors = redbot.get_motors();
  auto& encoder = redbot.get_encoder();
  encoder.clearEnc(BOTH);

  motors.drive(speed.get());

  while (current_ticks < expected_ticks)
  {
    const auto left_ticks = abs(encoder.getTicks(LEFT));
    const auto right_ticks = abs(encoder.getTicks(RIGHT));
    current_ticks = max(left_ticks, right_ticks);
  }

  motors.stop();
}

void forward(RedBot& redbot, const Speed speed, const Milliseconds duration_ms)
{
  go_straight(redbot.get_motors(), speed, duration_ms);
}

void forward(RedBot& redbot, const Speed speed, const Millimeters distance_mm)
{
  go_straight(redbot, speed, distance_mm);
}

void backward(RedBot& redbot, const Speed speed, const Milliseconds duration_ms)
{
  go_straight(redbot.get_motors(), Speed(-speed.get()), duration_ms);
}

void backward(RedBot& redbot, const Speed speed, const Millimeters distance_mm)
{
  go_straight(redbot, Speed(-speed.get()), distance_mm);
}

void forward(RedBot& redbot, const Speed speed, const Seconds duration_s)
{
  forward(redbot, speed, Milliseconds(duration_s.get() * 1000));
}

void backward(RedBot& redbot, const Speed speed, const Seconds duration_s)
{
  backward(redbot, speed, Milliseconds(duration_s.get() * 1000));
}

}  // namespace move

namespace experimental
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
  const auto is_right_turn = check_if_right_turn(speed);
  const auto expected_left_ticks = get_expected_left_ticks(angle, is_right_turn);
  const auto expected_right_ticks = get_expected_right_ticks(angle, is_right_turn);

  auto rotate_left = true;
  auto rotate_right = true;

  auto& motors = redbot.get_motors();
  auto& encoder = redbot.get_encoder();
  encoder.clearEnc(BOTH);

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

  motors.leftMotor(MOTORS_STOP);
  motors.rightMotor(MOTORS_STOP);
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

}  // namespace experimental

}  // namespace redbot
