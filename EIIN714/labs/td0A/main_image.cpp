/**********************************************
* ppm Image manipualtion example              *  
*---------------------------------------------*
* Julien Deantoni --- No Copyright 2016       *
*     v0.2 2016/11/30                         *
**********************************************/
// modified Sylvain Lippi
// voir <<ppm>> pour le format d'image <<Portable Pixmap>>
// tests de la classe Image

#include "image.h"
#include <iostream>
#include <fstream>

int main() {

    std::string basePath = "/Users/ozeliurs/Desktop/Polytech/EIIN714/labs/td0A/";

    Image mon_image(basePath + "billc.ppm"); // lecture dans un fichier
    Image mon_image_cpy = mon_image; // copie

	mon_image.makeGrey(); // transforme l'image en niveaux de gris : R=G=B=moyenne des couleurs

    ofstream mon_image2("billc2.ppm"); // écriture dans un fichieer
    mon_image2 << mon_image;

	mon_image_cpy.makeBlack_White(int threshold); // transforme l'image en Noir en Blanc :
	// Si moyenne des couleurs < threshold => BLANC sinon NOIR

    ofstream mon_image3("billc3.ppm"); // écriture dans un fichieer
    mon_image3 << mon_image_cpy;

    return 0;
}
