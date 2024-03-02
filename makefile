all : main.o sorts.o work_array.o work_files.o
	g++ main.o sorts.o work_array.o work_files.o -g
main.o: main.cpp
	g++ -c main.cpp -g
sorts.o: sorts.cpp
	g++ -c sorts.cpp -g
work_array.o: work_array.cpp
	g++ -c work_array.cpp -g
work_files.0: work_files.cpp
	g++ -c work_files.cpp -g
clean:
	rm -rf *o a.out
