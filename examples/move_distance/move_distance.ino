#include <RedBotHelpers.h>

auto gonk = RedBot();

void setup() {}

void loop()
{
  // Explicit types
  gonk.move_forward(Meters(1));
  gonk.move_backward(Meters(1));

  // Literal operator conversions
  gonk.move_forward(0.5_m);
  gonk.move_backward(0.5_m);
}
