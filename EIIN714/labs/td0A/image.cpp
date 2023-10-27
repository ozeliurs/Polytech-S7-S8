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
    
    Pixel p = Pixel();
    while (imageFile >> p) {
        data.push_back(p);
        p = Pixel();
    }
}

void Image::makeItGrey() {
    for (auto &pixel : data) {
        pixel.makeItGrey();
    }
}

void Image::makeItBW(unsigned int threshold) {
    for (auto &pixel : data) {
        pixel.makeItBW(threshold);
    }
}

std::ostream &operator<<(std::ostream &os, const Image &image) {
    os << image.format << std::endl;
    os << image.nbColumns << " " << image.nbLines << std::endl;
    os << image.maxDepth << std::endl;

    for (auto &pixel : image.data) {
        os << pixel << std::endl;
    }

    return os;
}
