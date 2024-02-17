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
int CheckSorts(const int* ar, int size){
	int v=0;
	int u =0;
	for(int i =0; i<size-1;i++){
		if(ar[i]>= ar[i+1]){
			u++;
		}
		if(ar[i]<=ar[i+1]){
			v++;
		} 
	}
	if(v==size-1){
		return 0;
	}
	else if(u == size-1){
		return 1;
	}
	else if( v==0 && u==0){
		return 0;
	}
	else{
		return -1;
	}
}


