# Redbot Helpers

Library to help learn how to use Redbots

## Installation
### ZIP
1. Download library as zip
1. Arduino IDE -> Sketch -> Include Library -> Add ZIP Library

### Git clone
```
git clone https://github.com/jacobmanning/RedBotHelpers
ln -s /abs/path/to/RedBotHelpers /home/$USER/Arduino/libraries/RedBotHelpers
```

**Note:** This library depends on the SparkFun RedBot library

## Basic Usage
```C++
// FILE: examples/basic/basic.ino
#include <RedBotHelpers.h>

auto my_redbot = RedBot();

void setup() {}

void loop()
{
  my_redbot.move_forward(Time(2000));
  my_redbot.move_backward(Time(2000));
}
```
