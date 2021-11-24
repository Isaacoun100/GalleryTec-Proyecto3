//
// Created by michael on 22/11/21.
//

#include "UsersDatabaseHandler.h"

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using namespace std;

UsersDatabaseHandler::UsersDatabaseHandler() {
    db = conn["users_DB"];
    coll = db["users"];
    cout << "Database Connected!" << endl;
}

void UsersDatabaseHandler::insertUserToDB(string userName, string userPassword) {


    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::view_or_value<bsoncxx::document::view, bsoncxx::document::value> doc_value = builder
            << "usuario" << userName
            << "contraseña" << userPassword
            << "galerias" << bsoncxx::builder::stream::open_array
            << bsoncxx::builder::stream::open_array
            << "gallery1"
            << close_array
            << "image1"
            << close_array
            << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(doc_value);
    cout << "user inserted" << endl;
}

void UsersDatabaseHandler::modifyUserData() {

}

void UsersDatabaseHandler::deleteUserData(string username) {
    coll.delete_one(document{} << "usuario" << username << finalize);
    cout << "User deleted" << endl;
}

void UsersDatabaseHandler::getUserDataFromDB(string username){
    bsoncxx::stdx::optional<bsoncxx::document::value> result = coll.find_one(document{} << "usuario" << username << finalize);
    if(result){
        cout << bsoncxx::to_json(*result) << endl;
    }
}
