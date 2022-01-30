shell: main.o shellsort.o aux-functions.o
	g++ main.o shellsort.o aux-functions.o -o shell

main.o: main.cpp
	g++ -c main.cpp

shellsort.o: shellsort.cpp
	g++ -c shellsort.cpp

aux-functions.o: aux-functions.cpp aux-functions.h
	g++ -c aux-functions.cpp

clean:
	rm *.o
