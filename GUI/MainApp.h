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
#include "GUI/MetadataWindow.h"
#include "MemoryManagement/FileHandler.h"

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
    MetadataWindow *mtw;
    FileHandler fileHandler;
    QPushButton *anteriorButton;
    QPushButton *verMetadataButton;
    QPushButton *siguienteButton;
    QPushButton *eliminarImagenButton;
    QPushButton *agregarGaleriaButton;
    QPushButton *agregarImagenButton;
    const QSize BUTTON_SIZE = QSize(50, 50);

    QLabel *nombreGaleria;
    QLabel *nombreImagen;
    QLabel *labelImage;

    QString nombreCombobox;
    QString fileChooser;

    QComboBox *verGalerias;
    QLineEdit *agregarGaleria;

    string username;
    string password;

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

    void mostrarImagen();

public slots:

    /**
     * @brief este metodo se llama cuando se le da click al boton "Ver Metadata" y abre una nueva ventana hecha por la clase MetadataWindow.h
     */
    void clickedVerMetadata();

    /**
     * @brief este metodo se llama cuando se le da click "Eliminar Imagen" y se encarga de borrar la imagen de la pantalla.
     */
    void clickedEliminarImagen();

    void clickedAgregarGaleria();

    void clickedAnterior();

    void clickedSiguiente();

    void clickedAgregarImagen();

};


#endif //GALLERYTEC_PROYECTO3_MAINAPP_H
