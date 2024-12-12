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
    temp *a = new temp();
    temp1 *b = new temp1();
    std::cout<<sizeof(&a)<<std::endl;
    std::cout<<sizeof(&b)<<std::endl;
}
