#include <RedBotHelpers.h>

auto gonk = RedBot();

void setup() {}

void loop()
{
  gonk.move_forward(Seconds(2));
  gonk.move_backward(Seconds(2));

  gonk.move_forward(2_s);
  gonk.move_backward(2_s);
}
