application  : function.o main.o
	g++ function.o main.o -o application
main.o : main.cpp function.h
	g++ -c main.cpp -o main.o
fucntion.o : fucntion.cpp
	g++ -c fucntion.cpp -o fucntion.o 

run:
	./application

temizle:
	rm *.o
	rm application