#include "i2c.h"
#include <iostream>

using namespace i2c;
using namespace std;

bool I2cBus::writeData(int address, int data){
    cout << "Writing real data to address: " << address << " with data: " << data << endl; 
    bool success = true;
    return success;
}