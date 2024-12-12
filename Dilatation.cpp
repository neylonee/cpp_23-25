#include "Dilatation.h"
#include <iostream>
#include <fstream>
IMG::IMG(const char* fl){}
IMG::IMG(){
    width = 20;
    height = 20;
    img_pixels = new int[width*height];
    for(int i = 0; i<width*height;i++){
        img_pixels[i] = 0x00;
    }
    img_pixels[width*height/2+height/2] = 0x01;
}

IMG::IMG(int x_core, int y_core): _x_core(x_core), _y_core(y_core){
    width = 3;
    height = 3;
    img_pixels = new int[9] {0,1,0,1,1,1,0,1,0};
}
void ImgProc::clearUpdatedImg(){
    int width = img[1-curImg].width;
    int height = img[1-curImg].height;
    memset(&img[1-curImg].img_pixels[0],0x00, width*height*sizeof(int));

}


void ImgProc::copyMask(int x_core, int y_core){
    int cur_update_img = 1 - curImg;
    for(int y = 0; y < mask.height;y++){
        for(int x = 0; x < mask.width;x++){

        }
    }



}


void ImgProc::dilataion(){
    clearUpdatedImg();
    for(int y = 0; y_img ; y++){
        for(int x = 0; x < img[curImg].width;x++){
            if(img[curImg].img_pixels[img[curImg].width*y+x]!=1){
                continue;
            }
            copyMask(x,y);

        }
    }
}
