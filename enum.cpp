#include <iostream>
enum class Typefile{
    text = 1;
    dir = 2;
    picture = 3;
    doc = 4;

};

#define TF_TEXT 1
#define TF_DIR 2

void setTypeFile(, int typefile){}
void setTypefile1(, TypeFile tf){}

int main(){
    setTypeFile1(Typefile::text);
    TypeFile test;
    test = TypeFile::text;
    int Typefile = TF_TEXT;
}
