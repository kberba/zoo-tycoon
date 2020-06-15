runzoo: mainZoo.o Zoo.o Animal.o Tiger.o Turtle.o Penguin.o
	g++ -std=c++11 mainZoo.o Zoo.o Animal.o Tiger.o Turtle.o Penguin.o -o runzoo

mainZoo.o: mainZoo.cpp
	g++ -std=c++11 -c mainZoo.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -std=c++11 -c Zoo.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -std=c++11 -c Animal.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -std=c++11 -c Tiger.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -std=c++11 -c Turtle.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -std=c++11 -c Penguin.cpp

clean:
	rm *.o runzoo