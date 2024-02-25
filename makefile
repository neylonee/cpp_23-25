all : main.o sorts.o work_array.o
	g++ main.o sorts.o work_array.o -g
main.o: main.cpp
	g++ -c main.cpp -g
sorts.o: sorts.cpp
	g++ -c sorts.cpp -g
work_array.o: work_array.cpp
	g++ -c work_array.cpp -g
clean:
	rm -rf *o a.out
