#include <iostream>
class FOO{
    private: //свва и методы класса
        int *t;

    public:
        int p;
};
template <class T>
class FILO{
    private: //свва и методы класса. методы которые реализуют внутреннюю работу(органы человека)
       T *ar; 
       unsigned int size;
       unsigned int countEl;

    public:
        int p;
        int getCountEl() const{
            return countEl;
        }
        void setCountEl(int nCountEl){
            if(countEl>nCountEl){
                countEl = nCountEl;
            }
        }
        FILO():size(10),countEl(0){
            ar = new T[size];

        }
};

int main(){
    class FOO a;
    class FOO *pa=&a;
    //a.t = 8  - ТАК МЫ НЕ МОЖЕМ!!!!
    a.p = 100; // ТАК МОЖЕМ
    pa->p=200;//p становится равным 200
}
