#pragma once
#include <iostream>
struct IMG{
    int *img_pixels;
    unsigned int width;
    unsigned int height;
    unsigned int _x_core;
    unsigned int _y_core;
    IMG(int x_core, int y_core);
    IMG();
    IMG(const char*);
    ~IMG(){
        delete [] img_pixels;
    }
};
class ImgProc{
    private:
        IMG mask(1,1);
        IMG img[2];
        int curImg{0};
        void showImg(int img_num);
        void clearUpdatedImg();
        void copyMask(int x_core, int y_core);
    public:
        ImgProc() {
            int t = 0;
            while(t++ < img[1].width * img[1].height){
                img[1].img_pixels[t] = 0x00;
            }

        }
        ~ImgProc(){}

        void setImg(const std::string&);
        void dilataion();
        void saveImg(const std::string&);
        void update();
};
