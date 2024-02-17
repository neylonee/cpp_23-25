#include "work_array.h"

void ShowAr(const int* ar,int size,char del = ' '){
	std::cout<<ar[0];
	for (int i =1;i<size;i++){
		std::cout<<del<<ar[i];
	}
	std::cout<<std::endl;
}

void Swap(int* a, int* b){
	int c =*a;
	*a = *b;
	*b=c;
}
int GetMin(const int* ar, int size){
	int l = 0;
	int r = size-1;
	while(l<r){
		while(ar[l]>=ar[r] && l<r){
			l++;
		}
		while(ar[r]>ar[l] && l<r){
			r--;
		}
	}
	return l;
}

int GetMax(const int* ar, int size){
	int l = 0;
	int r = size-1;
	while(l<r){
		while(ar[l]<=ar[r] && l<r){
			l++;
		}
		while(ar[r]<ar[l] && l<r){
			r--;
		}
	}
	return l;            
}

