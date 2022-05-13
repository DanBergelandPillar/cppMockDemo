#include "i2c/i2c.h"

class LEDController{
    public:
        LEDController(i2c::I2cInterface *bus);
        void enableLights();
    private:
        i2c::I2cInterface* i2cBus;
};