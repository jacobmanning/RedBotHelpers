# Redbot Helpers

Library to help learn how to use Redbots

## Installation
```
git clone https://github.com/jacobmanning/redbot_helpers
cd redbot_helpers
```

+ Create a new sketch in the cloned repo

## Basic Usage
```
// hello_redbots.ino
#include <RedBot.h>
#include "redbot_helpers.hh"

auto motors = RedBotMotors();

void setup() {}

void loop()
{
  redbot::move::forward(motors, Speed(200), Time(2000));
  redbot::move::backward(motors, Speed(200), Time(2000));
}
```
