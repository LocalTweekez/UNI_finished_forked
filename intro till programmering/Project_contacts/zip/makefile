main: main.o remove.o addContact.o search.o
	g++ -o main main.o remove.o addContact.o search.o
main.o: main.cpp remove.cpp remove.h addContact.cpp addContact.h search.cpp search.h
	g++ -c main.cpp remove.cpp addContact.cpp search.cpp
	