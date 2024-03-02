#ifndef _sorts_h_
#define _sorts_h_

#include<iostream>

#define ASCENDING true
#define DESCENDING false

void SelectionSort(int*,int);
void InsertionSort(int*,int);
void BubbleSort(int*,int);
void QuickSort(int*,int);
int CheakSorts(const int*, int);
void MergeSort(int*,int);
void  CountSort(int*,int);
static void merge(int*,int);
#endif
