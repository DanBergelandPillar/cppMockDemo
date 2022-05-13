#ifndef I2C_H // I2C_H guard
#define I2C_H

#include <iostream>

namespace i2c
{
    class I2cInterface
    {
        public:
            virtual bool writeData(int address, int data) = 0;
    };

    class I2cBus : public I2cInterface
    {
        public:
            bool writeData(int address, int data);
    };

    class I2cMock : public I2cInterface
    {
        public:
            I2cMock();
            bool writeData(int address, int data);
            void restore();
            int writeDataCalled;
            int lastAddressWrittenTo;
            int lastDataWritten;
            void report();
    };
}
#endif // I2C_H guard