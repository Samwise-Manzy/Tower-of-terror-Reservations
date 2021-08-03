#makefile
a.out: TowerOfTerror.o Queue.o
	g++ TowerOfTerror.o Queue.o
TowerOfTerror.o: TowerOfTerror.cpp Queue.h
	g++ -c -std=gnu++0x TowerOfTerror.cpp
Queue.o: Queue.cpp Queue.h
	g++ -c -std=gnu++0x Queue.cpp