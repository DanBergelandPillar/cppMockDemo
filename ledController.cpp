#include "ledController.h"
#include "i2c/i2c.h"
#include <iostream>

using namespace std;

LEDController::LEDController(i2c::I2cInterface *bus){
    i2cBus = bus;
}

void LEDController::enableLights(){
    int masterEnableAddress = 42;
    int enableLEDdata = 0xFF;
    i2cBus->writeData(masterEnableAddress, enableLEDdata);
}