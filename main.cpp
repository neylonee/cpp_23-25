#include <iostream>
#include "sorts.h"
#include "work_array.h"
int main() {
	const int size = 10;
	int arr[size] = {-1,-100,-100,-200,500,1000,1001,0,1,100};
	ShowAr(arr,size, ' ');
	

	QuickSort(arr,size);
	ShowAr(arr,size, ' ');

	SelectionSort(arr,size);
	ShowAr(arr,size, ' ');
	
	InsertionSort(arr,size);
	ShowAr(arr,size, ' ');

	BubbleSort(arr,size);
	ShowAr(arr,size, ' ');



 
}
