#include <RedBotHelpers.h>

auto gonk = RedBot();

void setup() {}

void loop()
{
  gonk.move_forward(Speed(200), Seconds(2));
  gonk.move_backward(Speed(200), Seconds(2));

  gonk.move_forward(MEDIUM_SPEED, 2_s);
  gonk.move_backward(MEDIUM_SPEED, 2_s);
}
