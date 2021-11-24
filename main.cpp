//
// Created by maxgm on 21/11/21.
//
#include <iostream>
#include <QtWidgets>
#include "Database_Management/UsersDatabaseHandler.h"

using namespace std;

int main() {
    UsersDatabaseHandler DBhandler;
    //DBhandler.insertUserToDB("usuarionuevo","passwordUsuarioNuevo");
    //DBhandler.deleteUserData("user_5");
    //DBhandler.getUserDataFromDB("usuarionuevo");
    //DBhandler.modifyUserData("usuarionuevo", "NEW_USER__");
    //DBhandler.addNewGallery("NEW_USER__", "newG4");
    DBhandler.addNewImage("NEW_USER__","Gallery1", "Image_2");



    return 0;
}
