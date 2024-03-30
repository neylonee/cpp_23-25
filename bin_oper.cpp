#include "bin_oper.h"
int isNeg(int num){
	num  = (num &(1<<31));
	return num;

}
int isPos(int num){
	return !isNeg(num);

}
int isEven(int num){
	return !isOdd(num);	
}
int isOdd(int num){
	return(num&(1));
}

