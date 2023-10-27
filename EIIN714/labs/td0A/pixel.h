/**********************************************
* Pixel header                                *  
*---------------------------------------------*
* Julien Deantoni --- No Copyright 2016       *
*     v0.2 2016/11/30                         *
**********************************************/
#pragma once

#include <iostream>


class Pixel{
public:
    unsigned short int R =0;	// Red
    unsigned short int G =0;	// Green
    unsigned short int B =0;	// Blue

    void makeItGrey() {
        unsigned short int grey = (R + G + B) / 3;
        R = grey;
        G = grey;
        B = grey;
    }
    void makeItBW(int threshold) {
        unsigned short int grey = (R + G + B) / 3;
        if (grey < threshold) {
            R = 0;
            G = 0;
            B = 0;
        } else {
            R = 255;
            G = 255;
            B = 255;
        }
    }
    friend std::istream& operator>>(std::istream& is, Pixel& pix);
    friend std::ostream& operator<<(std::ostream& os, const Pixel& pix);
};
