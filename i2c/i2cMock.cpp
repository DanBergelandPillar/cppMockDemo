#include "i2c.h"
#include <iostream>

using namespace i2c;
using namespace std;

I2cMock::I2cMock(void){
    restore();
}

bool I2cMock::writeData(int address, int data){
    cout << "Don't worry, this is a mock without hardware." << endl;
    cout << "I'm definitely NOT sending address: " << address << " this data: " << data << endl;
    writeDataCalled++;
    lastDataWritten = data;
    lastAddressWrittenTo = address;
    bool success = true;
    return success; 
}

void I2cMock::restore(){
    writeDataCalled = 0;
    lastDataWritten = 0;
    lastAddressWrittenTo = 0;
}

void I2cMock::report(){
    cout << ">>>> A Very Useful MOCK REPORT <<<<" << endl;
    cout << "WriteData Called #: " << writeDataCalled << endl;
    cout << "Last Address: " << lastAddressWrittenTo << endl;
    cout << "Last Data: " << lastDataWritten << endl;
}