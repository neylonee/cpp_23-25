#pragma once
#include <iostream>
struct IMG{
    unsigned char *img;
    unsigned int width;
    unsigned int height;
    int x_core;
    int y_core;
    IMG();
    IMG(const char*);
    ~IMG();
};
class SimpleImgProcess{
    private:
        IMG * pic;
        IMG * mask;
        IMG * n_pic;
    public:
        void dilataion(IMG*, const IMG*);
        void setImg(const std::string&);
        void saveImg(const std::string&);
        void update();
};
