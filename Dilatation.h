#pragma once
#include <iostream>
#include <fstream>
#include <string>
struct IMG{
    int *img_pixels;
    int *copy_image_pixels;
    int *mask_pixels;
    unsigned int width;
    unsigned int height;
    unsigned int x_core;
    unsigned int y_core;
    unsigned int core_width;
    unsigned int core_height;
    IMG();
    IMG(std::string filename);
    ~IMG(){
        delete [] img_pixels;
    }
};
class ImgProc{
    private:
        IMG *img;
        IMG *mask;
        void clearUpdatedImg();
    public:
        void showImg();
        ImgProc() {
            int t = 0;
            while(t++ < img->width * img->height){
                img->img_pixels[t] = 0x00;
            }

        }

        ImgProc(IMG *picture, IMG *mask);
        ~ImgProc(){}
        void dilataion();
};
