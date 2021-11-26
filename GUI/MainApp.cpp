//
// Created by maxgm on 21/11/21.
//

#include "MainApp.h"

MainApp::MainApp(string username, string password) {
    windowApp.resize(1000,550);
    windowApp.setWindowTitle(QApplication::translate("toplevel","MainApp"));
    windowApp.setFixedSize(windowApp.size().width(),windowApp.size().height());
    windowApp.show();
    this->username = username;
    this->password = password;

    setUpWidgets();

}

MainApp::~MainApp() {

}

void MainApp::setUpBotones() {
    anteriorButton = new QPushButton(QApplication::translate("childwidget","Anterior"), &windowApp);
    anteriorButton->setMinimumSize(BUTTON_SIZE);
    anteriorButton->move(315,475);
    anteriorButton->show();

    verMetadataButton = new QPushButton(QApplication::translate("childwidget","Ver Metadata"), &windowApp);
    verMetadataButton->setMinimumSize(BUTTON_SIZE);
    verMetadataButton->move(455,475);
    verMetadataButton->show();

    siguienteButton = new QPushButton(QApplication::translate("childwidget","Siguiente"), &windowApp);
    siguienteButton->setMinimumSize(BUTTON_SIZE);
    siguienteButton->move(595,475);
    siguienteButton->show();

    eliminarImagenButton = new QPushButton(QApplication::translate("childwidget","Eliminar Imagen"), &windowApp);
    eliminarImagenButton->setMinimumSize(BUTTON_SIZE);
    eliminarImagenButton->move(175,475);
    eliminarImagenButton->show();

    agregarGaleriaButton = new QPushButton(QApplication::translate("childwidget","Agregar Galeria"), &windowApp);
    agregarGaleriaButton->setMinimumSize(BUTTON_SIZE);
    agregarGaleriaButton->move(175,25);
    agregarGaleriaButton->show();

    agregarImagenButton = new QPushButton(QApplication::translate("childwidget","Agregar imagen"), &windowApp);
    agregarImagenButton->setMinimumSize(BUTTON_SIZE);
    agregarImagenButton->move(300,25);
    agregarImagenButton->show();

    confirmarGaleria = new QPushButton(QApplication::translate("childwidget","Confirmar galeria"), &windowApp);
    confirmarGaleria->setMinimumSize(BUTTON_SIZE2);
    confirmarGaleria->move(425,25);
    confirmarGaleria->show();

    modificarMetadataButton = new QPushButton(QApplication::translate("childwidget","Modificar Metadata"), &windowApp);
    modificarMetadataButton->move(25,485);
    modificarMetadataButton->setMinimumSize(BUTTON_SIZE2);
    modificarMetadataButton->show();

    QObject::connect(modificarMetadataButton,SIGNAL(clicked()),this,SLOT(clickedModificarMetadata()));


    QObject::connect(verMetadataButton,SIGNAL(clicked()),this,SLOT(clickedVerMetadata()));
    QObject::connect(anteriorButton,SIGNAL(clicked()),this,SLOT(clickedAnterior()));
    QObject::connect(siguienteButton,SIGNAL(clicked()),this,SLOT(clickedSiguiente()));
    QObject::connect(eliminarImagenButton,SIGNAL(clicked()),this,SLOT(clickedEliminarImagen()));
    QObject::connect(agregarGaleriaButton,SIGNAL(clicked()),this,SLOT(clickedAgregarGaleria()));
    QObject::connect(agregarImagenButton,SIGNAL(clicked()),this,SLOT(clickedAgregarImagen()));
    QObject::connect(confirmarGaleria,SIGNAL(clicked()),this,SLOT(clickedConfirmarGaleria()));


}

void MainApp::setUpLabels() {
    agregarGaleria = new QLineEdit(QApplication::translate("childwidget",""),&windowApp);
    agregarGaleria->move(25,25);
    agregarGaleria->show();
}


void MainApp::setUpCombobox() {
    verGalerias = new QComboBox(&windowApp);
    verGalerias->move(25, 50);
    verGalerias->clear();
    this->currentGalleries = fileHandler.getgalleries(username);

    for(int i = 0; i < currentGalleries.size(); i++){
        verGalerias->addItem(QString::fromStdString(currentGalleries[i]));
    }

    verGalerias->show();

}

void MainApp::mostrarImagen() {
    QImage image;
    image.load(fileChooser);
    image = image.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation);
    labelImage->setPixmap(QPixmap::fromImage(image));

}

void MainApp::setUpWidgets() {
    setUpBotones();
    setUpLabels();
    setUpCombobox();

}

void MainApp::clickedVerMetadata() {
    metadataWindow = new QMainWindow;
    metadataWindow->resize(450,350);
    metadataWindow->setWindowTitle(QApplication::translate("toplevel","Ver-Metadata"));
    metadataWindow->setFixedSize(metadataWindow->size().width(),metadataWindow->size().height());

    imagenData2 = new QLabel(QApplication::translate("childwidget", "Imagen: "), metadataWindow);
    imagenData2->move(50, 20);
    imagenData2->show();

    autorData2 = new QLabel(QApplication::translate("childwidget", "Autor: "), metadataWindow);
    autorData2->move(50, 70);
    autorData2->show();

    fechaData2 = new QLabel(QApplication::translate("childwidget", "Fecha: "), metadataWindow);
    fechaData2->move(50, 120);
    fechaData2->show();

    tamanoData2 = new QLabel(QApplication::translate("childwidget", "Tamano: "), metadataWindow);
    tamanoData2->move(50, 170);
    tamanoData2->show();

    descripcionData2 = new QLabel(QApplication::translate("childwidget", "Descripcion: "), metadataWindow);
    descripcionData2->move(50, 220);
    descripcionData2->show();

}

void MainApp::clickedEliminarImagen() {


}

void MainApp::clickedAgregarGaleria() {
    fileHandler.addgallery(username, agregarGaleria->text().toStdString());
    this->currentGalleries = fileHandler.getgalleries(username);

    verGalerias->clear();
    for(int i = 0; i < currentGalleries.size(); i++){
        verGalerias->addItem(QString::fromStdString(currentGalleries[i]));
    }
    verGalerias->show();

}

void MainApp::clickedAnterior() {

}

void MainApp::clickedSiguiente() {


}

void MainApp::clickedAgregarImagen() {
    string ID = username, imageText;
    fileChooser = QFileDialog::getOpenFileName(&windowApp, tr("Open Image"), ".../GalleryTEC/imagenes", tr("mage Files (*.*)"));
    string imageName = pathTranslate(fileChooser.toStdString());
    ID.append(imageName);
    ReadWrite readWrite;
    imageText = readWrite.readFile(fileChooser.toStdString());
    fileHandler.imageallocator(imageText, currentGallery, ID);


}

string MainApp::pathTranslate(string path) {
    vector<string> v;
    stringstream ss(path);

    while (ss.good()) {
        string substr;
        getline(ss, substr, '/');
        v.push_back(substr);
    }
    return v[v.size()-1];

}

void MainApp::clickedConfirmarGaleria() {
    vector<string> nombresImg = fileHandler.getimagesID(currentGallery);
    string currentImageID = nombresImg[0];

}

void MainApp::clickedModificarMetadata() {
    ModificarMetada = new QMainWindow;
    ModificarMetada->resize(450,350);
    ModificarMetada->setWindowTitle(QApplication::translate("toplevel","Modificar-Metadata"));
    ModificarMetada->setFixedSize(ModificarMetada->size().width(),ModificarMetada->size().height());

    imagenData = new QLabel(QApplication::translate("childwidget", "Imagen: "), ModificarMetada);
    imagenData->move(50, 20);
    imagenData->show();

    autorData = new QLabel(QApplication::translate("childwidget", "Autor: "), ModificarMetada);
    autorData->move(50, 70);
    autorData->show();

    fechaData = new QLabel(QApplication::translate("childwidget", "Fecha: "), ModificarMetada);
    fechaData->move(50, 120);
    fechaData->show();

    tamanoData = new QLabel(QApplication::translate("childwidget", "Tamano: "), ModificarMetada);
    tamanoData->move(50, 170);
    tamanoData->show();

    descripcionData = new QLabel(QApplication::translate("childwidget", "Descripcion: "), ModificarMetada);
    descripcionData->move(50, 220);
    descripcionData->show();

    imagenEntry = new QLineEdit(QApplication::translate("childwidget",""),ModificarMetada);
    autorEntry = new QLineEdit(QApplication::translate("childwidget",""),ModificarMetada);
    fechaEntry = new QLineEdit(QApplication::translate("childwidget",""),ModificarMetada);
    tamanoEntry = new QLineEdit(QApplication::translate("childwidget",""),ModificarMetada);
    descripcionEntry = new QLineEdit(QApplication::translate("childwidget",""),ModificarMetada);

    imagenEntry->move(150,20);
    autorEntry->move(150,70);
    fechaEntry->move(150, 120);
    tamanoEntry->move(150, 170);
    descripcionEntry->move(150,220);

    imagenEntry->show();
    autorEntry->show();
    fechaEntry->show();
    tamanoEntry->show();
    descripcionEntry->show();

    ModificarMetada->show();
}

void MainApp::clickActualizar() {

}




