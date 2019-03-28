#include <RedBotHelpers.h>

auto gonk = RedBot();

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Explicit types
  redbot::experimental::pivot_right(gonk, Angle(90));
  redbot::experimental::pivot_left(gonk, Angle(90));

  // Literal operators
  redbot::experimental::pivot_right(gonk, 90_degrees);
  redbot::experimental::pivot_left(gonk, 90_degrees);

  redbot::experimental::pivot_right(gonk, 90_deg);
  redbot::experimental::pivot_left(gonk, 90_deg);
}
