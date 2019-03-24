#include <RedBot.h>
#include <redbot_helpers.hh>

void setup() {}

void loop()
{
  redbot::blink_led(redbot::LED_PIN, Time(1000));
}
