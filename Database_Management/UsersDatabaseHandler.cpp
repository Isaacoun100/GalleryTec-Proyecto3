//
// Created by michael on 22/11/21.
//

#include "UsersDatabaseHandler.h"
#include <vector>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <bits/stdc++.h>


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
            << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(doc_value);
    cout << "user inserted" << endl;
}

void UsersDatabaseHandler::addNewGallery(string username,string newGallery) {

    coll.update_one(document{} << "usuario" << username << finalize,
                    document{} << "$set" << open_document <<
                               newGallery << "" << close_document << finalize);
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
    Json::Reader reader;
    Json::Value root;

    bsoncxx::stdx::optional<bsoncxx::document::value> result = coll.find_one(document{} << "usuario" << username << finalize);
    if(result){
        string json = bsoncxx::to_json(*result);
        reader.parse(json.c_str(),root);

        cout << bsoncxx::to_json(*result) << endl;
    }
}

void UsersDatabaseHandler::addNewImage(string username,string gallery, string newImage) {

    string images;
    images = getRawImages(username,gallery);

    images += newImage+",";
    cout << images << endl;


    coll.update_one(document{} << "usuario" << username  << finalize,
                    document{} << "$set" << open_document <<
                               gallery << images << close_document << finalize);



    cout << "done adding image" << endl;
}

vector<string> UsersDatabaseHandler::getUsernameAndPassword(string username) {
    Json::Reader reader;
    Json::Value root;
    vector<string> logInInfo;

    string json_result;

    bsoncxx::stdx::optional<bsoncxx::document::value> result = coll.find_one(document{} << "usuario" << username << finalize);
    if(result){
        json_result = bsoncxx::to_json(*result);
        reader.parse(json_result.c_str(),root);
        logInInfo.push_back(root["usuario"].asString());
        logInInfo.push_back(root["contraseña"].asString());

    }
    return logInInfo;
}

vector<string> UsersDatabaseHandler::getGalleries(string username) {
    Json::Reader reader;
    Json::Value root;
    vector<string> galleryList;

    string json_result;

    bsoncxx::stdx::optional<bsoncxx::document::value> result = coll.find_one(document{} << "usuario" << username << finalize);
    if(result){
        json_result = bsoncxx::to_json(*result);
        reader.parse(json_result.c_str(),root);

        for(string& memberName:root.getMemberNames()){
            if(memberName != "_id" and memberName != "usuario" and memberName != "contraseña"){
                galleryList.push_back(memberName);
            }
        }

    }
    return galleryList;
}

vector<string> UsersDatabaseHandler::getImages(string username, string gallery) {
    vector<string> imagesList;
    string images;
    images = getRawImages(username,gallery);

    stringstream ss(images);
    string segment;

    while(std::getline(ss,segment,',')){
        imagesList.push_back(segment);
    }


    return imagesList;
}

void UsersDatabaseHandler::emptyGallerySet() {
    galleries.clear();
}

string UsersDatabaseHandler::getRawImages(string username,string gallery) {
    Json::Reader reader;
    Json::Value root;
    string images;

    bsoncxx::stdx::optional<bsoncxx::document::value> result = coll.find_one(document{} << "usuario" << username << finalize);
    if(result){
        string json = bsoncxx::to_json(*result);
        reader.parse(json.c_str(),root);

        //cout << bsoncxx::to_json(*result) << endl;
        cout << root[gallery] << endl;
        images = root[gallery].asString();

        cout << images << endl;
        return images;
    }


}

void UsersDatabaseHandler::deleteGallery(string username, string gallery) {

}

void UsersDatabaseHandler::deleteImage(string username, string gallery, string image) {

}
