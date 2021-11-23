//
// Created by marcelo on 23/11/21.
//

#include "FileHandler.h"



int FileHandler::getbloqueparidad() {
    if(this->Discoparidad != 1){//El bloque de paridad está entre 1-4
        this->Discoparidad--;
        return Discoparidad;
    }else{//El bloque de paridad se pasa del rango, se vuelve a colocar sobre el rango
        this->Discoparidad=4;
        return Discoparidad;
    }
}

void FileHandler::imageallocator(string image, string ID) {
    this->filemap[ID]=this->memoryblock;//Conexion Imagen-Bloque de memoria
    this->memoryblock++;//Registro de bloqued e memoria ocupado
    vector<string> partitions;//Imagen partida en tres

    partitions.push_back("0010");
    partitions.push_back("0000");
    partitions.push_back("0110");

    int partitionindex=0;
    //10" 00" 101
    //aquí se hace la partición

    int paridad=this->getbloqueparidad();//En que disco ira el bloque de paridad

    for(int i=1;i<5;i++){
        string path=this->pathbuilder(ID,i);
        if(i==paridad){//Guardado en memoria de la paridad
            string Paritystring=this->calculoparidad(partitions[0],partitions[1],partitions[2]);
            ofstream myfile;
            myfile.open(path);
            myfile<<Paritystring;
            myfile.close();
        }else{//Guardado en memoria fragmentado
            ofstream myfile;
            myfile.open(path);
            myfile<<partitions[partitionindex];
            partitionindex++;
            myfile.close();
        }
    }
}

string FileHandler::getimage(string ID) {
    int memoryBlock=this->filemap[ID];
    int memoryBlockaux=memoryBlock;
    int parityblock=1;
    string compressedimage;
    string decompressedimage;
    //encontrar bloque que contiene la paridad para ignorarlo (no es parte de la imagen)
    while((4*(memoryBlockaux/4))-(4*((memoryBlock/4)+1))!=0){
        memoryBlockaux++;
        parityblock++;
    }
    if(parityblock==5){//Ajuste bloque paridad 1
        parityblock=1;
    }

    compressedimage=this->fileReader(ID,parityblock);
    //Decompressing

    return compressedimage;
}

string FileHandler::fileReader(string ID, int Parity) {
    string image;
    for(int i=1;i<5;i++) {
        if (i == Parity) {
            continue;
        }else{
            string path=this->pathbuilder(ID,i);
            ifstream file;
            file.open(path);
            if (file.good()) {//File Found
                string imagepart;
                getline(file,imagepart);
                image.append(imagepart);
            } else {//File lost XOR
                image.append(this->XORHelper(ID,i));
            }
            file.close();
        }
    }
    return image;
}

string FileHandler::calculateXOR(string Part1, string Part2) {
    string XOR;
    for(int i=0;i<Part1.size();i++){
        if(Part1[i]==Part2[i]){
            XOR.append("0");
        }else{
            XOR.append("1");
        }
    }
    return XOR;
}

string FileHandler::XORHelper(string ID, int missingdisc) {
    vector<string> strings;
    //Busqueda de los tres archivos restantes
    for(int i=1;i<5;i++){
        string part;
        if(i==missingdisc){
            continue;
        }else{
            string path =this->pathbuilder(ID,i);
            ifstream myfile;
            myfile.open(path);
            getline(myfile,part);
            strings.push_back(part);
            myfile.close();
        }
    }
    //Reconstruccion del archivo
    string first=this->calculateXOR(strings[0],strings[1]);
    string second=this->calculateXOR(first,strings[2]);
    return second;
}

string FileHandler::pathbuilder(string ID, int disc) {
    string path = "../Disk";
    path.append(to_string(disc));
    path.append("/");
    path.append(ID);
    path.append(to_string(this->filemap[ID]));
    path.append(".txt");
    return path;
}

string FileHandler::calculoparidad(string one, string two, string three) {
    string answer;
    string uno ="1";
    for(int i=0;i<4;i++){
        int par=0;
        if(one[i]==uno[0]){
            if(par==0){
                par++;
            }else{
                par--;
            }
        }if(two[i]==uno[0]){
            if(par==0){
                par++;
            }else{
                par--;
            }
        }if(three[i]==uno[0]){
            if(par==0){
                par++;
            }else{
                par--;
            }
        }
        answer.append(to_string(par));
    }
    return answer;
}
