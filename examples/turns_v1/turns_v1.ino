#include <RedBot.h>
#include <redbot_helpers.hh>

auto gonk = redbot::init();

void test_pivot(const int angle)
{
  redbot::experimental::v1::pivot_right(gonk, Angle(angle));
  redbot::experimental::v1::pivot_left(gonk, Angle(angle));
}

void setup() {}

void loop()
{
  test_pivot(90);
  test_pivot(180);
  test_pivot(270);
}
