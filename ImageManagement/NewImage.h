#ifndef GALLERYTEC_PROYECTO3_NEWIMAGE_H
#define GALLERYTEC_PROYECTO3_NEWIMAGE_H

#include "local/ReadWrite.h"
#include "huffman/HuffmanCompresion.h"

using namespace std;

struct page;

class NewImage {
public:
    /**
     * This method will decompress the given image text usable text
     * @param image
     * @param id
     * @return
     */
    string decompressImage(string image, string id);

    /**
     * This method will create the dictionary that we need to compress and decompress
     * @param path
     * @return
     */
    string createDictionary(string path);

    /**
     * This method receives an image text and compress image to a binary huffman compressed image text
     * @param image
     * @param id
     * @return
     */
    string compressImage(string image, string id);
private:
    /**
     * Will return a string with the frecuency of the characters in the give string
     * @param path
     * @param characters
     * @return
     */
    string frecuencyList(string path, string characters);

    /**
     * Will delete duplicates and return the clean string
     * @param path
     * @return
     */
    string characterList(string path);

    /**
     * Reads a given image from a path
     * @param path
     * @return
     */
    string readImage(string path);
};


#endif //GALLERYTEC_PROYECTO3_NEWIMAGE_H
