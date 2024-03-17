#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
char* ConvertNumberToStr(int number){
    string s = "";
    int a = 0;
    while (number>0){
        for(int j = 0; j<10; j++){
            if(number%10==j){
                s+=48+j;
                }
            }
        number/=10;
        }
    reverse(s.begin(),s.end());
    char* ch = s.data();
    return ch;
}

