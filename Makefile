objects = main.o constructor.o template.o

Exe : $(objects) 
	g++ -g -std=c++11 -o Exe $(objects)

main.o : main.cpp constructor.h log.h template.h
	g++ -g -std=c++11 -c main.cpp

constructor.o : constructor.h constructor.cpp
	g++ -g -std=c++11 -c constructor.cpp

template.o : template.h template.cpp
	g++ -g -std=c++11 -c template.cpp

.PHONY : clean
clean:
	rm Exe $(objects)
