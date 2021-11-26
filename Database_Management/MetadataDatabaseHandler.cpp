//
// Created by michael on 26/11/21.
//

#include "MetadataDatabaseHandler.h"
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


MetadataDatabaseHandler::MetadataDatabaseHandler() {
    db = conn["users_images"];
    coll = db["images"];
    cout << "Database Connected!" << endl;

}

void MetadataDatabaseHandler::addNewMetadata(string newImage, string gallery) {
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::view_or_value<bsoncxx::document::view, bsoncxx::document::value> doc_value = builder
            << "imagen" << newImage
            << "galeria" << gallery
            << "autor" << ""
            << "año creacion" << ""
            << "tamaño" << ""
            << "descripcion" << ""
            << bsoncxx::builder::stream::finalize;

    bsoncxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(doc_value);
    cout << "Image inserted in collection" << endl;
}


void MetadataDatabaseHandler::deleteMetadata(string image) {
    coll.delete_one(document{} << "imagen" << image << finalize);
    cout << "image deleted" << endl;

}

void MetadataDatabaseHandler::modifyMetadata(string image,string infoAuthor, string infoYear, string infoSize, string infoDesc) {
    coll.update_one(document{} << "imagen" << image << finalize,
                          document{} << "$set" << open_document <<
                                     "autor" << infoAuthor << "año creacion" << infoYear << "tamaño" << infoSize << "descripcion" << infoDesc <<close_document << finalize);
    cout << "done updating metadata" << endl;

}

vector<string> MetadataDatabaseHandler::getMetadata(string image) {
    vector<string> metadata;
    Json::Reader reader;
    Json::Value root;

    bsoncxx::stdx::optional<bsoncxx::document::value> result = coll.find_one(document{} << "imagen" << image << finalize);
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
