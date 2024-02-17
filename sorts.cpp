#include "sorts.h"
#include "work_array.h"

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
