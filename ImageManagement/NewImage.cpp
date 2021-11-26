#include "NewImage.h"

struct page{
    char data;
    string compressed;
};

struct CompressedImage{

    string compressedBinary;
    vector<page> dictionary;

};

string NewImage::readImage(string path) {
    ReadWrite readWrite;
    return readWrite.readFile(path);
}

string NewImage::frecuencyList(string path, string characters){

    string result, imageText =path;

    for(int i=0; i<characters.size();i++){
        int repeat=0;
        for(int j=0; j<imageText.size();j++){
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

    string result,imageText = path, tmp=imageText;

    while(imageText.size()>0){
        result+=imageText[0];
        imageText.erase(remove(imageText.begin(), imageText.end(), imageText[0] ), imageText.end());
    }

    return result;

}

string NewImage::createDictionary(string path) {

    CompressedImage newCompressedImage;

    string content = characterList(path);
    string times = frecuencyList(path,content);

    char elements[content.size()];
    int frecuency[content.size()], k=0;

    for(int i=0; i<content.size(); i++){ elements[i]=content[i];}

    for(int i=0; i<content.size(); i++){
        string number;

        for(int j=k; j<times.size(); j++){
            if(times[j]!=',' && j!=times.size()){
                number+=times[j];
            }
            else{
                k=j+1;
                j=times.size();
            }
        }

        stringstream degree(number);
        int x = 0;
        degree >> x;
        frecuency[i]=x;

    }

    int size = sizeof(elements) / sizeof(elements[0]);

    HuffmanCompresion huffmanCompresion;
    return huffmanCompresion.HuffmanCodes(elements,frecuency, size );

}

string NewImage::compressImage(string path){
    string dictionary = createDictionary(path);
    string image = path;
    string final;

    for(int i=0; i<image.size(); i++){
        string compression;

        for(int j=0; j<dictionary.size(); j++){
            if(image[i]==dictionary[j]){
                while(dictionary[j]!='/'){
                    if(dictionary[j]=='0' || dictionary[j]=='1'){ final+=dictionary[j];}
                    j++;
                }
                j=dictionary.size();
            }
        }

    }

    return final;
}

