COMPILER=g++
CPPFLAGS=-W -Wall

main_date: main_date.o date.o
	$(COMPILER) $(CPPFLAGS) -o main_date main_date.o date.o

main_date.o: main_date.cpp date.h
	$(COMPILER) $(CPPFLAGS) -c main_date.cpp date.h common_defs.h

date.o: date.cpp date.h
	$(COMPILER) $(CPPFLAGS) -c date.cpp

clean:
	rm -rf *.o
	rm -rf main_date
	rm -rf *.gch