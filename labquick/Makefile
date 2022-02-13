output: main.o qsorts.o functions.o
	g++ main.o qsorts.o functions.o -o qsorts

main.o: main.cpp
	g++ -c main.cpp

sorts.o: qsorts.cpp
	g++ -c qsorts.cpp

aux-functions.0: functions.cpp functions.h
	g++ -c functions.cpp

clean:
	rm *.o
