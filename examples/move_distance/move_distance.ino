#include <RedBotHelpers.h>

auto gonk = RedBot();

void setup() {
  Serial.begin(9600);
}

void loop()
{
  gonk.move_forward(Speed(255), 1_m);
  gonk.move_backward(Speed(255), 1_m);
}
