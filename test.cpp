#include <iostream>
struct temp{
    int a;
    char b;
    int a1;
    char b1;
    int a2;
    char b2;
    int a3;
    char b3;
};
struct temp1{
    int a,a1,a2,a3;
    char b,b1,b2,b3;
};

int main(){
    std::cout<<sizeof(temp)<<std::endl;
    std::cout<<sizeof(temp1)<<std::endl;
    int a = 1;
    switch(a){
        case 0:
            std::cout<<"Zero";
        case 1:
            std::cout<<"One";
    }
}
