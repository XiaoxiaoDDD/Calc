
myspeller: main.o enquiry.o incomplete.o
	g++ main.o enquiry.o incomplete.o -o myspeller
	
main.o: main.cpp
	g++ -c main.cpp

enquiry.o: enquiry.cpp
	g++ -c enquiry.cpp

incomplete.o: incomplete.cpp
	g++ -c incomplete.cpp

clean:
	rm *.o myspeller