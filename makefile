all: main.o bin_oper.o
	g++ main.cpp bin_oper.cpp -g
main.o: main.cpp
	g++ -c main.cpp -g
bin_oper.o: bin_oper.cpp
	g++ -c bin_oper.cpp -g
clear:
	rm -rf *o *a.out
