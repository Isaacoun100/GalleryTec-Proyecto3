//
// Created by michael on 22/11/21.
//

/**
 * @file UserDatabaseHandler.h
 * @author Michael Valverde Navarro
 * @brief Clase que funciona para gestionar la base de datos y las colecciones donde se almacenan los usuarios, imagenes, galerias y detalles de metadata, entre otros
 * @version 1.0
 * @date 22/11/21
 */


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

    mongocxx::instance inst{};
    const mongocxx::uri uri = mongocxx::uri{"mongodb+srv://michael-admin:webapp13@cluster0.7s2vm.mongodb.net/users_DB?retryWrites=true&w=majority"};
    mongocxx::client conn{uri};
    mongocxx::database db;
    mongocxx::collection coll;
    mongocxx::collection collImages;


public:

    /**
     * @brief constructor de la clase, que inicializa la base de datos y las colecciones a las que se deben accesar
     */
    UsersDatabaseHandler();

    /**
     * @brief inserta un usuario y contraseña a la base
     * @param userName : nombre del usuario
     * @param userPassword : contraseña del usuario
     */
    void insertUserToDB(string userName, string userPassword);

    /**
     * @brief modifica el usuario por uno nuevo
     * @param userName : usuario a modificar
     * @param newUserName : usuario por el que se cambia
     */
    void modifyUserData(string userName, string newUserName);

    /**
     * @brief elimina datos de un usuario en especifico
     * @param username : usuario a eliminar
     */
    void deleteUserData(string username);

    /**
     * @brief obtiene datos del usuario
     * @param username : usuario al que se le obtienen los datos
     */
    void getUserDataFromDB(string username);

    /**
     * @brief almacena una nueva galeria en cierto usuario
     * @param username : usuario que crea la galeria nueva
     * @param newGallery : nombre de la galeria nueva
     */
    void addNewGallery(string username,string newGallery);

    /**
     * @bried almacena una nueva imagen en cierta galeria y en cierto usuario
     * @param username : usuario que guarda la nueva imagen
     * @param gallery : galeria en el que se va a almacenar la nueva imagen
     * @param newImage : nombre de la imagen o ID  a guardar
     */
    void addNewImage(string username, string gallery,string newImage);

    /**
     * @brief obtiene el usuario y contraseña de un usuario para comprobar si existe y si puede hacer log in
     * @param username : usuario a buscar
     * @return vector con los datos esperados, en el indice 0 se encuentra el usuario, en indice 1 se encuentra la contraseña
     */
    vector<string> getUsernameAndPassword(string username);

    /**
     * @brief obtiene las galerias de un usuario
     * @param username : usuario con las galerias
     * @return vector con las galerias que ha creado
     */
    vector<string> getGalleries(string username);

    /**
     * @brief obtiene las imagenes contenidas en una galeria
     * @param username : usuario al que le pertenece la galeria
     * @param gallery : galeria a buscar para obtener las imagenes
     * @return vector con las imagenes de la galeria buscada
     */
    vector<string> getImages(string username, string gallery);

    /**
     * @brief obtiene string con las imagenes de un usuario en una respectiva galeria
     * @param username : usuario al que buscar
     * @param gallery : galeria al que buscar
     * @return string con las imagenes o IDs de imagenes
     */
    string getRawImages(string username,string gallery);

    /**
     * @brief elimina una galeria de la base de datos
     * @param username : usuario a buscar para eliminar la galeria
     * @param gallery : galeria a eliminar
     */
    void deleteGallery(string username, string gallery);

    /**
     * @brief elimina una imagen de la base de datos
     * @param username : usuario a buscar
     * @param gallery : galeria a buscar
     * @param image : imagen que se elimina
     */
    void deleteImage(string username, string gallery, string image);

    /**
     * @brief inserta una imagen a la coleccion de imagenes creada en la base de datos
     * @param newImage : imagen que se inserta
     * @param gallery : galeria para ubicar a la imagen
     */
    void insertImageToCollection(string newImage, string gallery);

    /**
     * @brief modifica las imagenes cuando se elimina una
     * @param username : usuario a buscar
     * @param images : string de imagenes
     * @param gallery : galeria a buscar
     */
    void insertImagesModified(string username,string images,string gallery);

    /**
     * @brief obtiene la metadata de una imagen
     * @param image : imagen a buscar en la coleccion images
     * @return vector con la metadata de la imagen buscada
     */
    vector<string> getMetadata(string image);

    /**
     * @brief permite modificar la metadata de una imagen
     * @param image : imagen a modificar la metadata
     * @param infoAuthor : autor de la imagen
     * @param infoYear : año de creacion de la imagen
     * @param infoSize : tamaño de la imagen
     * @param infoDesc : descripcion de la imagen 
     */
    void modifyMetadata(string image, string infoAuthor, string infoYear, string infoSize, string infoDesc);


    void emptyGallerySet();



};




#endif //GALLERYTEC_PROYECTO3_USERSDATABASEHANDLER_H
