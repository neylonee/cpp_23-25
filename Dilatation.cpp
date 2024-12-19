#include "Dilatation.h"
#include <iostream>
#include <fstream>
#include <string>
IMG::IMG(std::string fl){
    std::ifstream istrm(fl);
    if (!istrm.is_open())
        std::cout << "failed to open - " << fl << '\n';
    else
    {
        char temp;
        istrm>>temp;
        switch(temp)
        {
            case 'p':
                istrm >> width;
                istrm >> height;
                img_pixels = new char[width*height];
                for(int i =0;i<height;i++){
                    for(int j = 0; j<width;j++){
                        istrm>>img_pixels[i*width+j];
                    }
                }
                for(int i = 0; i<height;i++){
                    for(int j = 0; j<width;j++){
                        std::cout<<img_pixels[i*width+j];
                    }
                    std::cout<<"\n";
                }
                break;
            case 'm':
                istrm>>x_core;
                istrm>>y_core;
                istrm>>core_width;
                istrm>>core_height;
                for(int i = 0; i < height;i++){
                    for(int j = 0; j < width; j++){
                        istrm>>mask_pixels[i*width+j];
                    }
                }
                break;
        }
    }
};
void ImgProc::dilataion(){
    IMG picture = IMG("picture.txt");
    IMG mask = IMG("mask.txt");
    picture.img_pixels = new char[picture.width * picture.height];
    for(int i = 0;i<picture.height;i++){
        if(picture.img_pixels[i] == 0){
        }
        else{

        }
    }
}
