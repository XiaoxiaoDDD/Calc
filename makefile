
mycalc: mycalc.o mycalc_functions.o
	g++ mycalc.o mycalc_functions.o -o mycalc


mycalc.o: mycalc.cpp
	g++ -std=c++11 -c mycalc.cpp

	
mycalc_functions.o: mycalc_functions.cpp
	g++ -std=c++11 -c mycalc_functions.cpp

clean:
	rm *.o mycalc