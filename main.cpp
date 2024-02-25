#include <iostream>
#include "sorts.h"
#include "work_array.h"
#include <chrono>


using namespace std;
int main() {
		
		int c = 10;
		
 		int arr[c] = {5,10,100,-100,10,8,15,20,25,999};
		MergeSort(arr,c);
		ShowAr(arr,c,' ');
		int sizes[c] = {100, 500, 1000, 2500, 5000, 10000, 50000, 100000, 500000, 1000000};
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
