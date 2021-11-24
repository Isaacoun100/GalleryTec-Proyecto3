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
    DBhandler.getUserDataFromDB("usuarionuevo");


    return 0;
}
