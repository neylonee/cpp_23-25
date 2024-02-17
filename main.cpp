#include <iostream>
#include "sorts.h"
#include "work_array.h"
using namespace std;
int main() {
	const int size = 10;
	int arr[size] = {-1,-100,-100,-200,500,1000,1001,0,1,100};
	ShowAr(arr,size, ' ');
	cout<<CheckSorts(arr,size)<<endl;	
	QuickSort(arr,size);
	ShowAr(arr,size, ' ');
	cout<<CheckSorts(arr,size)<<endl;	
	
	SelectionSort(arr,size);
	ShowAr(arr,size, ' ');
	cout<<CheckSorts(arr,size)<<endl;	

	InsertionSort(arr,size);
	ShowAr(arr,size, ' ');
	cout<<CheckSorts(arr,size)<<endl;	

	BubbleSort(arr,size);
	ShowAr(arr,size, ' ');
	cout<<CheckSorts(arr,size)<<endl;	


 
}
