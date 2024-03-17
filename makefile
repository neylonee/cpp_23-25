all : main.o sorts.o work_array.o work_files.o processkeys.o numbers.o
	g++ main.o sorts.o work_array.o work_files.o processkeys.o numbers.o -g
main.o: main.cpp
	g++ -c main.cpp -g
sorts.o: sorts.cpp
	g++ -c sorts.cpp -g
work_array.o: work_array.cpp
	g++ -c work_array.cpp -g
work_files.o: work_files.cpp
	g++ -c work_files.cpp -g
processkeys.o: processkeys.cpp
	g++ -c processkeys.cpp -g
numbers.o: numbers.cpp
	g++ -c numbers.cpp -g
clean:
	rm -rf *o a.out
