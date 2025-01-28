#include <chrono>
#include <iostream>
#include "Train.h"
#include "time.h"
#include "chrono"
#include "Dilatation.h"
#include <unistd.h>
int main(){
    IMG* pic = new IMG("picture.txt");
    IMG* mask = new IMG("mask.txt");
    ImgProc a = ImgProc(pic,mask);
    a.showImg();
    a.dilataion();
    a.showImg();

    //IMG* mask = new IMG("mask.txt");
    //ImgProc test(pic,mask);
    //test.showImg();
}
