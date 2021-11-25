#ifndef GALLERYTEC_PROYECTO3_NEWIMAGE_H
#define GALLERYTEC_PROYECTO3_NEWIMAGE_H

#include "local/ReadWrite.h"

using namespace std;

class NewImage {
public:
    string frecuencyList(string path, string characters);
    string characterList(string path);
private:
    string readImage(string path);
};


#endif //GALLERYTEC_PROYECTO3_NEWIMAGE_H
