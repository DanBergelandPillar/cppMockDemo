#include "ledController.h"
#include "i2c/i2c.h"

int main(){
    i2c::I2cBus i2cBus;
    LEDController LedController = LEDController(&i2cBus);

    LedController.enableLights();
    return 0;
}