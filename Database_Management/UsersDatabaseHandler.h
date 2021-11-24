//
// Created by michael on 22/11/21.
//
#include <iostream>
#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>


using namespace std;

#ifndef GALLERYTEC_PROYECTO3_USERSDATABASEHANDLER_H
#define GALLERYTEC_PROYECTO3_USERSDATABASEHANDLER_H

class UsersDatabaseHandler{
public:
    string userName;
    string password;
    mongocxx::instance inst{};
    const mongocxx::uri uri = mongocxx::uri{"mongodb+srv://michael-admin:webapp13@cluster0.7s2vm.mongodb.net/users_DB?retryWrites=true&w=majority"};
    mongocxx::client conn{uri};
    mongocxx::database db;
    mongocxx::collection coll;


public:
    UsersDatabaseHandler();
    void insertUserToDB(string userName, string userPassword);
    void modifyUserData();
    void deleteUserData(string username);
    void getUserDataFromDB(string username);


};




#endif //GALLERYTEC_PROYECTO3_USERSDATABASEHANDLER_H
