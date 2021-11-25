#include <iostream>

#include "ImageManagement/NewImage.h"
#include "local/ReadWrite.h"


using namespace std;

int main(int argc, char *argv[]) {

    NewImage newImage;
    ReadWrite readWrite;

    string characters = newImage.characterList("local/example.ppm");

    string numberList = newImage.frecuencyList("local/example.ppm",characters);

    cout<<numberList<<endl;
    cout<<characters<<endl;
    return 0;

}