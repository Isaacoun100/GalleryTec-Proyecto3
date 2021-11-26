#ifndef GALLERYTEC_PROYECTO3_FILEHANDLER_H
#define GALLERYTEC_PROYECTO3_FILEHANDLER_H


#include "string"
#include "fstream"
#include "vector"
#include "iostream"
#include "stdio.h"
#include "ImageManagement/NewImage.h"

using namespace std;

class FileHandler{
private:
//-------------------------------------Variables------------------------------------
    int Discoparidad=5;
    int memoryblock=1;
//-----------------Funciones Recuperación archivos----------------------------------
    /**
     * Manejo del bloque de paridad distribuido
     * Maneja en caso de que se deba de volver a distribuir desde el primer disco
     * @return Bloque en que se debe colocar la paridad
     */
    int getbloqueparidad();

    /**
     * Cálculo del XOR entre dos cadenas de string
     * @param Part1
     * @param Part2
     * @return String de las resultante de aplicar XOR
     */
    string calculateXOR(string Part1, string Part2);

    /**
    * Maneja los archivos a los cuales se les debe aplicar XOR y utiliza XOR para el cálculos
    * @param ID
    * @param missingdisc
    * @return
    */
    string XORHelper(string ID, int missingdisc);

/**
 * Calculo de bloque de paridad
 * @param one
 * @param two
 * @param three
 * @return Equivalente de la paridad
 */
    string calculoparidad(string one, string two, string three);

    //----------------Funciones para lectura y escritura en los discos-------------------
    /**
     * Lee un archivo y mantiene control de si el archivo está incompleto o no
     * ignora el bloque de paridad
     * @param ID
     * @param Parity
     * @return
     */
    string fileReader(string ID, int Parity);

/**
 * Encuentra el path a buscar para un determinado archivo en un determinado disco
 * @param ID
 * @param disc
 * @return Path del archivo
 */
    string pathbuilder(string ID, int disc);

//-------------Funciones principales añadir componentes--------------------

/**
 * Le relaciona a un determinado usuario con una galería y lo almacena
 * @param user
 * @param gallery
 */
    void addusergalley(string user, string gallery);

    /**
     * Le relaciona a una determinada galería con una imagen y lo almacena
     * @param ID
     * @param Gallery
     */
    void GIconnection(string ID,string Gallery);

/**
 * Le asigna a una determinada imagen un bloque de memoria y lo almacena
 * @param ID
 */
    void ImageDirection(string ID);
/**
 * Busca en qué bloque de memoria se encuentra una determinada imagen
 * @param ID
 * @return
 */
    int getImgMemoryBlock(string ID);
//------------------Funciones secundarias para añadir datos-----------------------------

/**
 * Ajusta los datos para abrir espacio a un usuario para una galeria más
 * @param user
 * @return
 */
    vector<string> UGdivider(string user);
/**
 * Ajusta el espacio de una Galería para que pueda almacenar una imagen más
 * @param Gallery
 * @return
 */
    vector<string> GIdivider(string Gallery);

/**
 * Ajusta el espacio del disco de modo que pueda almacenarse la dirección de la imagen
 * @return
 */
    string ImageDirectionaux();

/**
 * Ajusta el espacio de las galerías de modo que esta tenga espacio para una galería nueva
 * @param gallery
 * @return
 */
    string addgalleryaux(string gallery);

    /**
     * Ajusta los usuarios de modo que tenga espacio para almacenar uno nuevo
     * @return
     */
    string adduseraux();

    //-------------------------Funciones principales de Borrado de datos------------------
/**
 * Borra una imagen en específico de las galerías que están memoria
 * @param ID
 */
    void GIdeleter(string ID);

    /**
     * Borra a una galería completa y todas las imagenes que se contengan en almacenamiento
     * @param Gallery
     */
    void GIdeleter2(string Gallery);

    /**
     * Borra El bloque de memoria de una imagen en específico
     * @param ID
     */
    void MBdeleter(string ID);
/**
 * Elimina a una gelería relacionada con un determinado usuario
 * @param Gallery
 */
    void UGdeleter(string Gallery);

//-------------------------Fuinciones secundarias eliminación datos-------------

/**
 * Elimina una imagen y el espacio que ocupaba en una galería
 * @param ID
 * @return Nuevo bloque de imagenes dentro de una galería sin la imagen dada
 */
    string GIdeleterhelper(string ID);

/**
 * Elimina el bloque que una galería y sus imagenes estaban ocupando
 * @param Gallery
 * @return Nuevo bloque de galerías sin la galería dada
 */
    string GIdeleterhelper2(string Gallery);

    /**
     * Elimina El bloque de memoria registrado que una imagen estaba ocupando
     * @param ID
     * @return Nuevo bloque de memoria sin la imagen
     */
    string MBdeleterhelper(string ID);

    /**
     * Elimina el la galería relacionada en memoria con un determinado usuario
     * @param Gallery
     * @return loque de galerías de un usuario sin la galería dada
     */
    string UGdeleterhelprt(string Gallery);

public:
    /**
     * Recibe una imagen, registra en memoria la galería a la que pertenece la parte la comprime y
     * la alamcena en los discos virtuales
     * @param image
     * @param gallery
     * @param ID
     */
    void imageallocator(string image,string gallery, string ID);

    /**
     * Añadir usuarios al registro de usuarios
     * @param user
     */
    void adduser(string user);

    /**
     * Añadir galerías al registro de galerías
     * @param user
     * @param gallery
     */
    void addgallery(string user, string gallery);

    /**
     * Obtener las galerías de un determinado usuario
     * @param user
     * @return Vector con los nombres de las galerías de un usuario
     */
    vector<string> getgalleries(string user);

    /**
     * Obtener una imagen en específico
     * @param ID
     * @return Imagen que se solicitó
     */
    string getimage(string ID);

    /**
     * Obtener el ID de las imagenes pertenecientes a una galería
     * @param Gallery
     * @return vector con los nombres de las imagenes que pertenecen a una galería
     */
    vector<string>getimagesID(string Gallery);

/**
 * Borrar una imagen en especifico
 * @param ID
 */
    void deleteimage(string ID);

    /**
     * Borrar una galería en específico
     * @param Gallery
     */
    void deleteGalery(string Gallery);
};

#endif //GALLERYTEC_PROYECTO3_FILEHANDLER_H
