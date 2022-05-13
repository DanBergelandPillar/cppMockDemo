sub-make:
	make -C i2c

CPP = g++

ledController.o: ledController.cpp ledController.h
	$(CPP) -c ledController.cpp

main.o: main.cpp ledController.o i2c/i2cBus.o
	$(CPP) -c main.cpp

app: ledController.o i2c/i2cBus.o main.o
	$(CPP) main.o i2c/i2cBus.o ledController.o -o app

test: ledControllerTest.o ledController.o i2c/i2cMock.o
	$(CPP) ledControllerTest.o ledController.o i2c/i2cMock.o -o testExec -Wall

clean:
	make -C i2c clean
	rm -f *.o
	rm testExec app