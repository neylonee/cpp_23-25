#pragma once
#include <iostream>
#include <fstream>
#include <string>
struct IMG{
    char *img_pixels;
    char *mask_pixels;
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
        IMG img[2];
        int curImg{0};
        void clearUpdatedImg();
        void showImg(int img_num);
    public:
        ImgProc() {
            int t = 0;
            while(t++ < img[1].width * img[1].height){
                img[1].img_pixels[t] = 0x00;
            }

        }
        ~ImgProc(){}
        void dilataion();
        void update();
};
