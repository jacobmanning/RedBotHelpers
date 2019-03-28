# Redbot Helpers

Library to help learn how to use Redbots

## Installation
### RedBot
+ **Note:** This library depends on the [SparkFun RedBot library](https://github.com/sparkfun/SparkFun_RedBot_Arduino_Library), you _must_ install that before installing this library

### ZIP
1. Download library as zip
1. Arduino IDE -> Sketch -> Include Library -> Add ZIP Library

### Library Manager
+ Coming soon!

## Basic Usage
```C++
// FILE: examples/basic/basic.ino
#include <RedBotHelpers.h>

auto my_redbot = RedBot();

void setup() {}

void loop()
{
  my_redbot.move_forward(2_s);
  my_redbot.move_backward(2_s);
}
```
