#ifndef GALLERYTEC_PROYECTO3_NEWIMAGE_H
#define GALLERYTEC_PROYECTO3_NEWIMAGE_H

#include "local/ReadWrite.h"
#include "huffman/HuffmanCompresion.h"

using namespace std;

struct page;
struct CompressedImage;

class NewImage {
public:
    string createDictionary(string path);
    string compressImage(string path);
private:
    string frecuencyList(string path, string characters);
    string characterList(string path);
    string readImage(string path);
};


#endif //GALLERYTEC_PROYECTO3_NEWIMAGE_H
