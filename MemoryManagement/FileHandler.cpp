//
// Created by marcelo on 23/11/21.
//

#include "FileHandler.h"

//--------------Funciones recuperación archivos---------------

int FileHandler::getbloqueparidad() {
    if(this->Discoparidad != 1){//El bloque de paridad está entre 1-4
        this->Discoparidad--;
        return Discoparidad;
    }else{//El bloque de paridad se pasa del rango, se vuelve a colocar sobre el rango
        this->Discoparidad=4;
        return Discoparidad;
    }
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

//-----------------Funciones para lectura y escritura en los discos-----------------------
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

string FileHandler::pathbuilder(string ID, int disc) {
    string path = "../Disk";
    path.append(to_string(disc));
    path.append("/");
    path.append(ID);
    int MemoryBlock=this->getImgMemoryBlock(ID);
    path.append(to_string(MemoryBlock));
    path.append(".txt");
    return path;
}

string FileHandler::getimage(string ID) {
    int memoryBlock=this->getImgMemoryBlock(ID);
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


void FileHandler::imageallocator(string image,string gallery,string ID) {
    NewImage newImage;
    this->GIconnection(ID,gallery);
    this->ImageDirection(ID);
    vector<string> partitions;//Imagen partida en tres
    partitions.push_back("0010");
    partitions.push_back("0000");
    partitions.push_back("0110");

    int partitionindex=0;

    string compressed = newImage.compressImage(image);

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

//-----------------Funciones para aladir componentes y almacenar datos------------

void FileHandler::GIconnection(string ID, string Gallery) {
    vector<string> file;
    string filecompleted;
    file= this->GIdivider(Gallery);
    filecompleted.append(file[0]);
    filecompleted.append(ID);
    filecompleted.append("\n");
    filecompleted.append(file[1]);
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    myfile<<filecompleted;
    myfile.close();

}

void FileHandler::ImageDirection(string ID) {
    string file=this->ImageDirectionaux();
    file.append(ID);
    file.append("\n");
    file.append(to_string(this->memoryblock));
    this->memoryblock++;
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/ImageMemoryBlock.txt");
    myfile<<file;
    myfile.close();
}

void FileHandler::addusergalley(string user, string gallery) {
    vector<string> file;
    string filecompleted;
    file= this->UGdivider(user);
    filecompleted.append(file[0]);
    filecompleted.append(gallery);
    filecompleted.append("\n");
    filecompleted.append(file[1]);
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/Usuariogaleria.txt");
    myfile<<filecompleted;
    myfile.close();
}

int FileHandler::getImgMemoryBlock(string ID) {
    ifstream myfile;
    string line;
    bool Imgfoud=false;
    myfile.open("../MemoryManagementFiles/ImageMemoryBlock.txt");
    while(getline(myfile,line)){
        if(Imgfoud){
            break;
        }else if(line==ID){
            Imgfoud=true;
        }else{
            continue;
        }
    }
    myfile.close();
    return stoi(line);
}

void FileHandler::addgallery(string user, string gallery) {
    this->addusergalley(user,gallery);
    string file=this->addgalleryaux(gallery);
    file.append(gallery);
    file.append("\n[\n]");
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    myfile<<file;
    myfile.close();
}


vector<string> FileHandler::getgalleries(string user) {
    vector<string> galleries;
    string line;
    int i=0;
    bool userfound=false;
    ifstream myfile;
    myfile.open("../MemoryManagementFiles/Usuariogaleria.txt");
    while(getline(myfile,line)){
        if(userfound){
            if(line=="]"){
                return galleries;
            }else if(line=="["){
                continue;
            }else{
                galleries.push_back(line);
            }
        }else{
            if(line==user){
                userfound= true;
            }else{
                continue;
            }
        }
    }
}

void FileHandler::adduser(string user) {
    string file=this->adduseraux();
    file.append(user);
    file.append("\n[\n]");
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/Usuariogaleria.txt");
    myfile<<file;
    myfile.close();
}

vector<string> FileHandler::getimagesID(string Gallery) {
    ifstream myfile;
    string line;
    vector<string> Images;
    bool foundGallery=false;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    while(getline(myfile,line)){
        if(foundGallery){
            if(line=="]"){
                break;
            }else if (line=="["){
                continue;
            }else{
                Images.push_back(line);
            }
        }else{
            if(line==Gallery){
                foundGallery=true;
            }else{
                continue;
            }
        }
    }
    myfile.close();
    return Images;
}

//------------------Funciones secundarias para añadir datos-----------------------------

string FileHandler::ImageDirectionaux() {
    ifstream myfile;
    string line,txt;
    myfile.open("../MemoryManagementFiles/ImageMemoryBlock.txt");
    while(getline(myfile,line)){
        txt.append(line);
        txt.append("\n");
    }
    return txt;
}

vector<string> FileHandler::UGdivider(string user) {
    ifstream myfile("../MemoryManagementFiles/Usuariogaleria.txt");
    string line,txt1,txt2;
    vector<string> Division;
    bool userfound=false;
    bool halffound=false;
    while(getline(myfile,line)){
        if(userfound){
            if(halffound){
                txt2.append(line);
                txt2.append("\n");
            }else if(line=="]"){
                halffound=true;
                txt2.append(line);
                txt2.append("\n");
            }else{
                txt1.append(line);
                txt1.append("\n");
            }
        }else{
            txt1.append(line);
            txt1.append("\n");
            if(line==user){
                userfound=true;
            }
        }
    }
    myfile.close();
    Division.push_back(txt1);
    Division.push_back(txt2);
    return Division;
}

vector<string> FileHandler::GIdivider(string Gallery) {
    ifstream myfile("../MemoryManagementFiles/Galeriaimagen.txt");
    string line,txt1,txt2;
    vector<string> Division;
    bool Galleryfound=false;
    bool halffound=false;
    while(getline(myfile,line)){
        if(Galleryfound){
            if(halffound){
                txt2.append(line);
                txt2.append("\n");
            }else if(line=="]"){
                halffound=true;
                txt2.append(line);
                txt2.append("\n");
            }else{
                txt1.append(line);
                txt1.append("\n");
            }
        }else{
            txt1.append(line);
            txt1.append("\n");
            if(line==Gallery){
                Galleryfound=true;
            }
        }
    }
    myfile.close();
    Division.push_back(txt1);
    Division.push_back(txt2);
    return Division;
}

string FileHandler::addgalleryaux(string gallery) {
    ifstream myfile;
    string line;
    string answer;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    while(getline(myfile,line)){
        answer.append(line);
        answer.append("\n");
    }
    return answer;
}

string FileHandler::adduseraux() {
    ifstream myfile;
    string line;
    string answer;
    myfile.open("../MemoryManagementFiles/Usuariogaleria.txt");
    while(getline(myfile,line)){
        answer.append(line);
        answer.append("\n");
    }
    return answer;
}

//-------------------------Funciones principales de Borrado de datos------------------

void FileHandler::GIdeleter(string ID) {
    string txt=this->GIdeleterhelper(ID);
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    myfile<<txt;
    myfile.close();
}

void FileHandler::GIdeleter2(string Gallery) {
    string txt=this->GIdeleterhelper2(Gallery);
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    myfile<<txt;
    myfile.close();
}

void FileHandler::deleteimage(string ID){
    for(int i=1;i<5;i++){
        string path=pathbuilder(ID, i);
        remove(path.c_str());
    }
    this->GIdeleter(ID);
    this->MBdeleter(ID);

}

void FileHandler::deleteGalery(string Gallery) {
    vector<string> Images=this->getimagesID(Gallery);
    for(int i=0;i<Images.size();i++){
        this->deleteimage(Images[i]);
    }
    this->GIdeleter2(Gallery);
    this->UGdeleter(Gallery);
}

void FileHandler::MBdeleter(string ID) {
    string txt=this->MBdeleterhelper(ID);
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/ImageMemoryBlock.txt");
    myfile<<txt;
    myfile.close();
}

void FileHandler::UGdeleter(string Gallery) {
    string txt=this->UGdeleterhelprt(Gallery);
    ofstream myfile;
    myfile.open("../MemoryManagementFiles/Usuariogaleria.txt");
    myfile<<txt;
    myfile.close();

}

//-------------------------Funciones secundarias de Borrado de datos------------------


string FileHandler::GIdeleterhelper(string ID) {
    ifstream myfile;
    string line,txt;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    while(getline(myfile,line)){
        if(line==ID){
            continue;
        }else{
            txt.append(line);
            txt.append("\n");
        }
    }
    myfile.close();
    return txt;
}


string FileHandler::MBdeleterhelper(string ID) {
    ifstream myfile;
    string line,txt;
    int i=0;
    myfile.open("../MemoryManagementFiles/ImageMemoryBlock.txt");
    while(getline(myfile,line)){
        if(line==ID||i==1){
            i++;
            continue;
        }else{
            txt.append(line);
            txt.append("\n");
        }
    }
    myfile.close();
    return txt;
}


string FileHandler::UGdeleterhelprt(string Gallery) {
    ifstream myfile;
    string line,txt;
    myfile.open("../MemoryManagementFiles/Usuariogaleria.txt");
    while(getline(myfile,line)){
        if(line==Gallery){
            continue;
        }else{
            txt.append(line);
            txt.append("\n");
        }
    }
    myfile.close();
    return txt;
}

string FileHandler::GIdeleterhelper2(string Gallery) {
    bool Galleryfound=false;
    string txt,line;
    ifstream myfile;
    myfile.open("../MemoryManagementFiles/Galeriaimagen.txt");
    while(getline(myfile,line)){
        if(Galleryfound){
            if(line=="]"){
                Galleryfound=false;
            }else{
                continue;
            }
        }else{
            if(line==Gallery){
                Galleryfound= true;
            }else{
                txt.append(line);
                txt.append("\n");
            }
        }
    }
    return txt;
}