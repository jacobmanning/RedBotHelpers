# Redbot Helpers

Library to help learn how to use Redbots

## Installation
### ZIP
1. Download library as zip
1. Arduino IDE -> Sketch -> Include Library -> Add ZIP Library

### Git clone
```
git clone https://github.com/jacobmanning/redbot_helpers
ln -s /abs/path/to/redbot_helpers /home/$USER/Arduino/libraries/redbot_helpers
```

**Note:** This library depends on the SparkFun RedBot library

## Basic Usage
```C++
// examples/hello_redbots/hello_redbots.ino
#include <RedBotHelpers.h>

auto my_redbot = redbot::init();

void setup() {}

void loop()
{
  my_redbot.move_forward(Speed(200), Time(2000));
  my_redbot.move_backward(Speed(200), Time(2000));
}
```
