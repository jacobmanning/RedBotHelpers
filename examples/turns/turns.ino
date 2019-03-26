#include <RedBotHelpers.h>

auto gonk = RedBot();

void test_pivot(const int angle)
{
  redbot::experimental::pivot_right(gonk, Angle(angle));
  redbot::experimental::pivot_left(gonk, Angle(angle));
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  test_pivot(90);
  // test_pivot(180);
  // test_pivot(270);
}
