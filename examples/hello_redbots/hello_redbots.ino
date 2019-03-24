#include <RedBot.h>
#include <redbot_helpers.hh>

auto gonk = redbot::init();

void setup() {}

void loop()
{
  gonk.move_forward(Speed(200), Time(2000));
  gonk.move_backward(Speed(200), Time(2000));
}
