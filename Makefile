CC     = /opt/local/bin/gcc
SRC    = src/euler.cpp

all: euler.o

euler.o: $(SRC)
	$(CC) -std=c++0x -o euler -Ilib/UnitTest++/src -Llib/UnitTest++/ -lUnitTest++ $(SRC)  -lstdc++ 
