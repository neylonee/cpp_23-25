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
        if(a == 1){
            istrm >> width;
            istrm >> height;
            x_core = 0;
            y_core = 0;
            core_width = 0;
            core_height = 0;
            img_pixels = new int[width*height];
            copy_image_pixels = new int[width*height];
            for(int i =0;i<height;i++){
                for(int j = 0; j<width;j++){
                    istrm>>img_pixels[i*width+j];
                    copy_image_pixels[i*width+j] = img_pixels[i*width+j];
                }
            }
        }
        else{
            if(a == 0){
                width = 0;
                height = 0;
                istrm >> x_core;
                istrm >> y_core;
                istrm >> core_width;
                istrm >> core_height;
                mask_pixels = new int[core_width*core_height];
                for(int i = 0; i < core_height; i++){
                    for(int j = 0; j < core_width; j++){
                        istrm >> mask_pixels[i*core_width+j];
                    }
                }
            }
        }
        
        istrm.close();
    }
};


void ImgProc::dilataion(){
    for(int y = 0;y<img->height;y++){
        for(int x = 0; x < img->width;x++){
            if(img->copy_image_pixels[img->width*y+x] == 0){
            }
            else{
                int tempx = x;
                int tempy = y;
                for(int i = 0; i < mask->core_width; i++){
                    for(int j = 0; j < mask->core_width; j++){
                        if(img->img_pixels[(tempy-mask->y_core)*img->width+tempx-mask->x_core] == 0){
                        img->img_pixels[(tempy-mask->y_core)*img->width+tempx-mask->x_core] = mask->mask_pixels[i*mask->core_width+j];
                        }
                        tempx++;
                    }
                    tempy++;
                    tempx = x;
                }


            }
        }
    }
}
void ImgProc::showImg(){
    std::cout<<"Вывод картинки: \n\n";
    for(int i = 0; i < img->height; i ++){
        for(int j = 0; j < img->width; j++){
            std::cout<<img->img_pixels[i*img->width + j];
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"Вывод закончен\n\n";
}
ImgProc::ImgProc(IMG *picture, IMG *maska){
    img = picture;
    mask = maska;
}

