//
// Created by maxgm on 21/11/21.
//
#include <iostream>
#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QString>
#include <vector>
#include "MemoryManagement/FileHandler.h"
#include "local/ReadWrite.h"
#include "Database_Management/MetadataDatabaseHandler.h"

using namespace std;

#ifndef GALLERYTEC_PROYECTO3_MAINAPP_H
#define GALLERYTEC_PROYECTO3_MAINAPP_H

/**
 * @file MainApp.h
 * @authors Max Garro Mora
 * @brief Clase que contiene toda la aplicacion principal.
 * @version 2.0
 * @date 21/11/2021
 */

class MainApp:public QWindow {
    Q_OBJECT
public:
    MetadataDatabaseHandler metadataDatabaseHandler;

    /**
     * @brief constructor de la clase MainApp.
     */
    MainApp(string username, string password);

    /**
     * @brief destructor de la clase MainApp.
     */
    virtual ~MainApp();

private:
    QWidget windowApp;
    QMainWindow * metadataWindow;
    QMainWindow * ModificarMetada;
    FileHandler fileHandler;
    QPushButton *anteriorButton;
    QPushButton *verMetadataButton;
    QPushButton *siguienteButton;
    QPushButton *eliminarImagenButton;
    QPushButton *eliminarGaleriaButton;
    QPushButton *agregarGaleriaButton;
    QPushButton *agregarImagenButton;
    QPushButton *confirmarGaleria;
    const QSize BUTTON_SIZE = QSize(50, 50);

    QPushButton *modificarMetadataButton;
    QPushButton *actualizarMetadataInfoButton;
    const QSize BUTTON_SIZE2 = QSize(90, 50);
    const QSize BUTTON_SIZE3 = QSize(150, 50);
    QLabel *imagenData;
    QLabel *autorData;
    QLabel *fechaData;
    QLabel *tamanoData;
    QLabel *descripcionData;

    QLabel *imagenData2;
    QLabel *autorData2;
    QLabel *fechaData2;
    QLabel *tamanoData2;
    QLabel *descripcionData2;

    QLineEdit *imagenEntry;
    QLineEdit *autorEntry;
    QLineEdit *fechaEntry;
    QLineEdit *tamanoEntry;
    QLineEdit *descripcionEntry;

    QString nombreGaleria;
    QLabel *nombreImagen;
    QLabel *labelImage;

    QString nombreCombobox;
    QString fileChooser;


    QComboBox *verGalerias;
    QLineEdit *agregarGaleria;

    string username;
    string password;
    vector<string> currentGalleries;
    string currentGallery;
    vector<string> currentImages;
    string currentImage;
    int imagePos;


    /**
     * @brief metodo encargado de crear los botones y mostrarlos en pantalla.
     */
    void setUpBotones();

    /**
     * @brief metodo encargado de crear y mostrar los labels en pantalla.
     */
    void setUpLabels();

    /**
     * @brief metodo encargado de crear y mostrar el combobox en pantalla.
     */
    void setUpCombobox();

    /**
     * @brief metodo encargado de correr todos los demas metodos, este se llama en el constructor de la clase.
     */
    void setUpWidgets();

    /**
     * @brief metodo encargado de mostrar las imagenes seleccionadas una por una en pantalla.
     */
    void mostrarImagen();

    /**
     * @brief metodo encargado de dividir el path de una imagen seleccionada.
     */
    string pathTranslate(string path);

public slots:

    /**
     * @brief este metodo se llama cuando se le da click al boton "Ver Metadata" y abre una nueva ventana hecha por la clase MetadataWindow.h
     */
    void clickedVerMetadata();

    /**
     * @brief este metodo se llama cuando se le da click "Eliminar Imagen" y se encarga de borrar la imagen de la pantalla.
     */
    void clickedEliminarImagen();

    /**
     * @brief este metodo se encarga de agregar una galeria al usuario que la hizo.
     */
    void clickedAgregarGaleria();

    /**
     * @brief este metodo se encarga de devolverse a la imagen anterior mediante un boton.
     */
    void clickedAnterior();

    /**
     * @brief este metodo se encarga de mostrar la siguiente imagen mediante un boton.
     */
    void clickedSiguiente();

    /**
     * @brief este metodo se encarga de agregar una imagen a la galeria.
     */
    void clickedAgregarImagen();

    /**
     * @brief este metodo se encarga de agregar dichas imagenes a una galeria.
     */
    void clickedConfirmarGaleria();

    /**
     * @brief este metodo se encarga de modificar la metada.
     */
    void clickedModificarMetadata();

    /**
     * @brief este metodo se actualizar los cambios en la metadata.
     */
    void clickActualizar();

    /**
     * @brief este metodo se encarga de eliminar la galeria.
     */
    void clickedEliminarGaleria();

};


#endif //GALLERYTEC_PROYECTO3_MAINAPP_H
