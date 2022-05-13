#include "i2c/i2c.h"
#include "ledController.h"
#include <iostream>
#include <string>

using namespace std;

struct RESULT{
    bool testPassed;
    string errorText;
};

RESULT test_WhenledControllerWritesI2cThenI2cWriteDataIsCalledOneTime(){
    //Setup using our cool mock
    i2c::I2cMock mockI2cBus = i2c::I2cMock();
    LEDController controller = LEDController(&mockI2cBus);
    
    //Action: When ledController turns the lights on, it has to talk to I2C
    controller.enableLights();
    
    //Just show the information in the mock for fun.
    mockI2cBus.report();

    //Since we're not using a test framework...
    RESULT testOutcome;
    testOutcome.errorText = "LED Controller did not use WriteData";
    
    //Then I2C Bus should have one used WriteData on the I2C bus one time
    //Weird ASSERT statement without a test framework:
    testOutcome.testPassed = (mockI2cBus.writeDataCalled == 1);
    return testOutcome;
}

int main(){
    cout << "Starting Tests" << endl;
    RESULT test1 = test_WhenledControllerWritesI2cThenI2cWriteDataIsCalledOneTime();
    cout << "Finished Running Tests" << endl;
    if(test1.testPassed != true){
        cout << "Test Failed: " << test1.errorText << endl;
        return 1;
    }
    cout << "No test failures." << endl;
    return 0;
}

