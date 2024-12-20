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
        int a;
        istrm >> a;
        if(int(a) == 1){
            istrm >> width;
            istrm >> height;
            img_pixels = new char[width*height];
            for(int i =0;i<height;i++){
                for(int j = 0; j<width;j++){
                    istrm>>img_pixels[i*width+j];
                }
            }
            std::cout<<"Картина записана\n";
            for(int i = 0; i < height; i ++){
                for(int j = 0; j < width; j++){
                    std::cout<<img_pixels[i*height + j];
                }
                std::cout<<"\n";
            }
            istrm.close();
        }
        std::cout<<"End\n";
    }
};


void ImgProc::dilataion(){
    img->img_pixels = new char[img->width * img->height];
    for(int y = 0;y<img->height;y++){
        for(int x = 0; x < img->width;x++){
            if(img->img_pixels[img->width*y+x] == 0){
            }
            else{
                for(int i = y-mask->y_core; i < mask->height;i++){
                    for(int j = x - mask->x_core; j < mask->width;j++){
                        if(img->img_pixels[i*img->height+j] == 0){
                            img->img_pixels[i*img->height + j] = mask->mask_pixels[i*img->height + j];
                        }
                    }
                }
            }
        }
    }
}
void ImgProc::showImg(){
    for(int i = 0; i < img->height; i ++){
        for(int j = 0; j < img->width; j++){
            std::cout<<img->img_pixels[i*img->height + j];
        }
    }
    std::cout<<"Вывод закончен\n";
}
ImgProc::ImgProc(IMG *picture, IMG *maska){
    img = picture;
    mask = maska;
}

