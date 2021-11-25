#ifndef GALLERYTEC_PROYECTO3_FILEHANDLER_H
#define GALLERYTEC_PROYECTO3_FILEHANDLER_H


#include "string"
#include "fstream"
#include "map"
#include "vector"

using namespace std;

class FileHandler{
private:
    int Discoparidad=5;
    int memoryblock=1;
    map<string, int> filemap;

    int getbloqueparidad();

    string fileReader(string ID, int Parity);

    string calculateXOR(string Part1, string Part2);

    string XORHelper(string ID, int missingdisc);

    string pathbuilder(string ID, int disc);

    string calculoparidad(string one, string two, string three);

public:
    void imageallocator(string image, string ID);

    string getimage(string ID);

};


#endif //GALLERYTEC_PROYECTO3_FILEHANDLER_H
