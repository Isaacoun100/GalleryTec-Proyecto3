#include "NewImage.h"

struct page{
    char data;
    string compressed;
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

vector<page> createVector(string dictionary){
    string buffer;
    char value = 0;
    int size=0, k=0;

    for(int i=0; i<dictionary.size(); i++){
        if(dictionary[i]==':'){size++;}
    }

    vector<page> result;
    result.resize(size);


    for(int i=0; i<dictionary.size();i++){

        if(dictionary[i+1]==':'){
            value=dictionary[i];
            i++;
        }

        else if(dictionary[i]=='0' || dictionary[i]=='1'){
            buffer+=dictionary[i];
        }

        else if(dictionary[i]=='/'){
            page newPage;
            newPage.data=value;
            newPage.compressed=buffer;
            result.at(k)=newPage;
            buffer.clear();
            k++;
        }
    }

    return result;

}

string NewImage::compressImage(string image, string dictionary){
    string final;

    vector<page> reference = createVector(dictionary);

    for(int i=0; i<image.size();i++){
        for(int j=0; j<reference.size();j++){
            if(image[i]==reference.at(j).data){
                final+=reference.at(j).compressed;
            }
        }
    }

    return final;
}

string NewImage::decompressImage(string image, string dictionary) {

    string final, buffer;

    int k=0;

    vector<page> reference = createVector(dictionary) ;

    for(int i=0; i<image.size();i++){
        buffer+=image[i];
        for(int j=0;j<reference.size();j++){
            if(buffer==reference.at(j).compressed){
                final+=reference.at(j).data;
                buffer.clear();
            }
        }
    }

    return final;
}