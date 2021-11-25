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
    collImages = db["images"];
    cout << "Database Connected!" << endl;

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

    insertImageToCollection(newImage,gallery);
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
    string imagesToDelete;
    imagesToDelete = getRawImages(username,gallery);
    coll.delete_one(document{} << gallery << imagesToDelete << finalize);

    bsoncxx::stdx::optional<mongocxx::result::delete_result> result = collImages.delete_many(
            document{} << "galeria" << open_document <<
            "$gte" << gallery << close_document << finalize);

    cout << "Images deleted from collection " << endl;

}

void UsersDatabaseHandler::deleteImage(string username, string gallery, string image) {
    string images;
    image = image+",";
    images = getRawImages(username,gallery);
    images.replace(images.find(image),image.size(),"");
    cout << "after replace " << images << endl;

    insertImagesModified(username,images,gallery);

}

void UsersDatabaseHandler::insertImageToCollection(string newImage, string gallery) {
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::view_or_value<bsoncxx::document::view, bsoncxx::document::value> doc_value = builder
            << "imagen" << newImage
            << "galeria" << gallery
            << "autor" << ""
            << "año creacion" << ""
            << "tamaño" << ""
            << "descripcion" << ""
            << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = collImages.insert_one(doc_value);
    cout << "Image inserted in collection" << endl;

}

void UsersDatabaseHandler::insertImagesModified(string username,string images, string gallery) {

    coll.update_one(document{} << "usuario" << username  << finalize,
                    document{} << "$set" << open_document <<
                               gallery << images << close_document << finalize);



}

vector<string> UsersDatabaseHandler::getMetadata(string image) {
    vector<string> metadata;
    Json::Reader reader;
    Json::Value root;

    bsoncxx::stdx::optional<bsoncxx::document::value> result = collImages.find_one(document{} << "imagen" << image << finalize);
    if(result){
        string json = bsoncxx::to_json(*result);
        reader.parse(json.c_str(),root);

        //cout << bsoncxx::to_json(*result) << endl;

        metadata.push_back(root["imagen"].asString());
        metadata.push_back(root["autor"].asString());
        metadata.push_back(root["año creacion"].asString());
        metadata.push_back(root["tamaño"].asString());
        metadata.push_back(root["descripcion"].asString());
    }

    //for(int i = 0; i< metadata.size(); i++){
        //cout << metadata[i] << endl;
    //}

    return metadata;
}

void UsersDatabaseHandler::modifyMetadata(string image, string infoAuthor, string infoYear, string infoSize, string infoDesc) {
    collImages.update_one(document{} << "imagen" << image << finalize,
                    document{} << "$set" << open_document <<
                               "autor" << infoAuthor << "año creacion" << infoYear << "tamaño" << infoSize << "descripcion" << infoDesc <<close_document << finalize);
    cout << "done updating metadata" << endl;



}
