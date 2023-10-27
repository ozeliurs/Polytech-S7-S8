//
// Created by Maxime BILLY on 27/10/2023.
//

#include "image.h"
#include <iostream>
#include <fstream>

Image::Image(std::string imagePath) {
    std::ifstream imageFile(imagePath);

    if (!imageFile.is_open()) {
        std::cerr << "Error: could not open file " << imagePath << std::endl;
        exit(1);
    }

    imageFile >> format >> nbColumns >> nbLines >> maxDepth;

    int r, g, b;
    while (imageFile >> r >> g >> b) {
        Pixel p = Pixel();
        p.R = r;
        p.G = g;
        p.B = b;
        data.push_back(p);
    }
}
