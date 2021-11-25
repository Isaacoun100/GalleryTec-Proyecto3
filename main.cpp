//
// Created by maxgm on 21/11/21.
//
#include <iostream>
#include <QtWidgets>
#include <vector>
#include "Database_Management/UsersDatabaseHandler.h"

using namespace std;

int main() {
    UsersDatabaseHandler DBhandler;
    //DBhandler.insertUserToDB("USUARIOTEC","passwordUsuarioNuevo");
    //DBhandler.deleteUserData("user_5");
    //DBhandler.getUserDataFromDB("NEW_USER__");
    //DBhandler.modifyUserData("usuarionuevo", "NEW_USER__");
    //DBhandler.addNewGallery("NEW_USER__", "newG4");
    //DBhandler.addNewImage("USUARIOTEC","Gallery02", "Image_00002__");
    //DBhandler.addNewGallery("USUARIOTEC","Gallery03");


    //vector<string> info;
    //info = DBhandler.getUsernameAndPassword("USUARIOTEC");
    //cout << info.at(0) << endl;
    //cout << info.at(1) << endl;

    //DBhandler.getGalleries("USUARIOTEC");
    //DBhandler.getImages("NEW_USER__","Gallery4");
    DBhandler.deleteImage("USUARIOTEC","Gallery02","Image_00002__");




    return 0;
}
