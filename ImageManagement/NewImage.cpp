#include "NewImage.h"

string NewImage::readImage(string path) {
    ReadWrite readWrite;
    return readWrite.readFile(path);
}

string NewImage::frecuencyList(string path, string characters){

    string result, imageText = readImage(path);
    int size=0;

    //Need to find the actual size of the string

    for(int i=0; i<size;i++){
        int repeat=0;
        for(int j=0; j<characters.size();j++){
            if(characters[i]==imageText[j]){
                repeat++;
            }
        }
        if(i+1==characters.size()){ result+=to_string(repeat);}
        else{ result+=to_string(repeat)+","; }
    }

    return result;
}

string NewImage::characterList(string path){

    string result,imageText = readImage(path), tmp=imageText;

    while(imageText.size()>0){
        result+=imageText[0];
        imageText.erase(remove(imageText.begin(), imageText.end(), imageText[0] ), imageText.end());
    }

    return result;

}
