#include "sorts.h"
#include "work_array.h"
#include "cstring"
void (*all_sorts[6])(int*,int) = {BubbleSort, InsertionSort,SelectionSort, QuickSort, MergeSort};
void BubbleSort(int* ar,int size){
	for (int i=0;i<size; i++){
		for(int j=0;j<size-1-i;j++){
			if (ar[j]>ar[j+1]){
				Swap(&ar[j],&ar[j+1]);
			}
		}
	}
}
void QuickSort(int *ar, int size){
	int l =0;
	int r = size-1;
	int p= ar[size/2];
	while(l<=r){
		while(ar[l]<p){
			l++;
		}
		while(ar[r]>p){
			r--;
		}
		if(l<=r){
			Swap(&ar[l],&ar[r]);
			r--;
			l++;
		}
	}
	if(r>0){
		QuickSort(&ar[0],l);
	}
	if(l<size){
		QuickSort(&ar[l],size-l);
	}
}
void SelectionSort(int* ar, int size) {
    for (int i = 0; i < size - 1; i = i + 1) {
        int min = ar[i];
        int id = i;
        for (int j = i+ 1;j < size; j += 1){
            if (ar[j] < min){
                min = ar[j];
                id = j;
            }
        }
        Swap(&ar[i],&ar[id]);
    }
}
void InsertionSort(int* ar, int size) {
    for (int j = 1; j < size; j = j + 1) {
        int key = ar[j];
        int i = j - 1;
        while (i >= 0 and ar[i] > key) {
            ar[i + 1] = ar[i];
            i = i - 1;
        }
        ar[i + 1] = key;
    }

}

static void merge(int* ar,int left,int size){
	int l =0;
	int r = left;
	int i=0;
	int* res = new int [size];
	while(i<size){
		if(ar[l]>=ar[r]){
			res[i]=ar[r];
			i++;
			r++;
			if(r>=size){
				while(l<left){
					res[i++]=ar[l++];
				}
				break;
			}
		}
		if(ar[l]<ar[r]){
			res[i]=ar[l];
			l++;
			i++;
			if(l>=left){
				while(r<size){
					res[i++]=ar[r++];
				}
				break;
			}
		}
	}
	memcpy(ar,res,size*4);
	delete [] res;
}
void MergeSort(int*ar,int size){
	if(size<=1){
		return;
	}
	MergeSort(&ar[0],size/2);
	MergeSort(&ar[size/2],size - size/2);
	merge(&ar[0],size/2,size);
}

void CountSort(int* ar, int size){
		long int count[1024];
		memset(count,0,sizeof(long int)*1024);
		for(int i=0; i<size;i++){
				++count[ar[i]];
		}				
		int c = 0;
		for(int k =0;k<1024;k++){
				for(int j = 0;j<count[k];j++){
						ar[c++] = k;
				}
		}
}
