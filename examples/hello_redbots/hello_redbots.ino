#include <RedBotHelpers.h>

auto gonk = RedBot();

void setup() {}

void loop()
{
  // Explicit types
  gonk.move_forward(Speed(200), Seconds(2));
  gonk.move_backward(Speed(200), Seconds(2));

  // Built-in speeds and literal operator conversion
  gonk.move_forward(MEDIUM_SPEED, 2_s);
  gonk.move_backward(MEDIUM_SPEED, 2_s);
}
