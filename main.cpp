#include <iostream>
#include "sorts.h"
#include "work_array.h"
#include <chrono>
#include <fstream>
#include "work_files.h"
void foo(){
		int test = 10;
		FILE* f = fopen("test","w");
		for (int i = 1;i<11;i++){
				for (int j = 1; j<11; j++){
						fprintf(f,"%d\t",i*j);
				}
				fprintf(f,"\n");
		}
		fclose(f);
}

using namespace std;
int main() {
		
		int c = 10;
		
 		int arr[c] = {5,10,100,-100,10,8,15,20,25,999};
		CountSort(arr,c);

		ShowAr(arr,c,' ');
		int sizes[c] = {100, 500, 1000, 2500, 5000, 10000, 50000, 100000, 500000, 1000000};
		foo();
		
		WriteRes("zadanie2",52,52.52,1);
		for(int i = 0; i <c;i++){
			int size = sizes[i];
			int* arr = new int[size];
			for(int j;j<size; ++j){
				arr[j]=rand()%100;
			}




			auto start = std::chrono::steady_clock::now();
			BubbleSort(arr,size);
			auto end = std::chrono::steady_clock::now();
			long int time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout<<size<<'\t'<<time<<'\n';
			delete [] arr;
}



}
