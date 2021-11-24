//
// Created by michael on 22/11/21.
//

#include "UsersDatabaseHandler.h"
#include <vector>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using namespace std;

vector<string> galleries;
vector<string> images;

UsersDatabaseHandler::UsersDatabaseHandler() {
    db = conn["users_DB"];
    coll = db["users"];
    cout << "Database Connected!" << endl;
    galleries.push_back("Gallery1");
    images.push_back("image_1");
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

void UsersDatabaseHandler::addNewGallery(string username,string newGallery) {

    galleries.push_back(newGallery);

    auto array_builder = bsoncxx::builder::basic::array{};
    for (const auto& gallery : galleries){
        array_builder.append(gallery);
    }

    coll.update_one(document{} << "usuario" << username << finalize,
                    document{} << "$set" << open_document <<
                               "galerias" << array_builder << close_document << finalize);

    cout << "done" << endl;


}

void UsersDatabaseHandler::modifyUserData(string userName, string newUserName) {
    coll.update_one(document{} << "usuario" << userName << finalize,
                    document{} << "$set" << open_document <<
                    "usuario" << newUserName << close_document << finalize);
    cout << "done" << endl;

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

void UsersDatabaseHandler::addNewImage(string username,string gallery, string newImage) {

    images.push_back(newImage);

    auto array_builder = bsoncxx::builder::basic::array{};
    for (const auto& image : images){
        array_builder.append(image);
    }

    coll.update_one(document{} << "usuario" << username << "galleries" << gallery << finalize,
                    document{} << "$set" << open_document <<
                               gallery << array_builder << close_document << finalize);

    cout << "done adding image" << endl;
}

void UsersDatabaseHandler::getUsernameAndPassword(string username) {

}

void UsersDatabaseHandler::getGalleries(string username) {

}

void UsersDatabaseHandler::getImages(string username) {

}

void UsersDatabaseHandler::emptyGallerySet() {
    galleries.clear();
}
