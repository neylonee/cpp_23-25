#include "Dilatation.h"
#include <iostream>
#include <fstream>
IMG::IMG(){}
IMG::IMG(const char *fl){
    std::ifstream fin;
    fin.open(fl);
    if(fin.is_open())
        std::cout << "Failed to open"<< fl<<'\n';
    else{
        std::cout<<"File is open"<< fl<<'\n';

    }
    fin.close();



 //   img = new unsigned char[width*height];
 //   for( int i=0;i<height;i++){
 //       for(int j =0;j<width;j++){
 //           fscanf(f,"%lf",&img[i*width+j]);
 //       }
 //   }
 //   fclose(f);
    //memcpy(ma,m1,c*r*4);


};
