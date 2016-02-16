objects = main.o constructor.o

Exe : $(objects) 
	g++ -g -std=c++11 -o Exe $(objects)

main.o : main.cpp constructor.h 
	g++ -g -std=c++11 -c main.cpp

constructor.o : constructor.h constructor.cpp
	g++ -g -std=c++11 -c constructor.cpp

.PHONY : clean
clean:
	rm Exe $(objects)
