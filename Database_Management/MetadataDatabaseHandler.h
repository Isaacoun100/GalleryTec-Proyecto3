//
// Created by michael on 26/11/21.
//

#include <iostream>
#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/v_noabi/bsoncxx/json.hpp>
#include <mongocxx/v_noabi/mongocxx/client.hpp>
#include <mongocxx/v_noabi/mongocxx/stdx.hpp>
#include <mongocxx/v_noabi/mongocxx/uri.hpp>
#include <mongocxx/v_noabi/mongocxx/instance.hpp>
#include <bsoncxx/v_noabi/bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/v_noabi/bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/v_noabi/bsoncxx/builder/stream/array.hpp>


using namespace std;

#ifndef GALLERYTEC_PROYECTO3_METADATADATABASEHANDLER_H
#define GALLERYTEC_PROYECTO3_METADATADATABASEHANDLER_H


class MetadataDatabaseHandler {
public:
    mongocxx::instance inst{};
    const mongocxx::uri uri = mongocxx::uri{"mongodb+srv://michael-admin:webapp13@cluster0.7s2vm.mongodb.net/users_DB?retryWrites=true&w=majority"};
    mongocxx::client conn{uri};
    mongocxx::database db;
    mongocxx::collection coll;


    MetadataDatabaseHandler();
    void addNewMetadata(string newImage, string gallery);
    void deleteMetadata(string image);
    void modifyMetadata(string image,string infoAuthor, string infoYear, string infoSize, string infoDesc);
    vector<string> getMetadata(string image);

};


#endif //GALLERYTEC_PROYECTO3_METADATADATABASEHANDLER_H
