//
// Created by maxgm on 25/11/21.
//

#include "MetadataWindow.h"

MetadataWindow::MetadataWindow() {
    windowMetadata.resize(450,300);
    windowMetadata.setWindowTitle(QApplication::translate("toplevel","Metadata"));
    windowMetadata.setFixedSize(windowMetadata.size().width(),windowMetadata.size().height());
    windowMetadata.show();

    setUpWidgets();
}

MetadataWindow::~MetadataWindow() {

}

void MetadataWindow::setUpLabels() {
    imagenData = new QLabel(QApplication::translate("childwidget", "Imagen: "), &windowMetadata);
    imagenData->move(50, 20);
    imagenData->show();

    autorData = new QLabel(QApplication::translate("childwidget", "Autor: "), &windowMetadata);
    autorData->move(50, 70);
    autorData->show();

    fechaData = new QLabel(QApplication::translate("childwidget", "Fecha: "), &windowMetadata);
    fechaData->move(50, 120);
    fechaData->show();

    tamanoData = new QLabel(QApplication::translate("childwidget", "Tamano: "), &windowMetadata);
    tamanoData->move(50, 170);
    tamanoData->show();

    descripcionData = new QLabel(QApplication::translate("childwidget", "Descripcion: "), &windowMetadata);
    descripcionData->move(50, 220);
    descripcionData->show();


}

void MetadataWindow::setUpBotones() {
    modificarMetadataButton = new QPushButton(QApplication::translate("childwidget","Modificar Metadata"), &windowMetadata);
    modificarMetadataButton->move(100,250);
    modificarMetadataButton->show();

    QObject::connect(modificarMetadataButton,SIGNAL(clicked()),this,SLOT(clickedModificarMetadata()));
}

void MetadataWindow::setUpWidgets() {
    setUpLabels();
    setUpBotones();

}

void MetadataWindow::clickedModificarMetadata() {
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

    actualizarinfoButton = new QPushButton(QApplication::translate("childwidget","Metadata"), ModificarMetada);
    actualizarinfoButton->setMinimumSize(BUTTON_SIZE);
    actualizarinfoButton->move(130,270);
    actualizarinfoButton->show();

    QObject::connect(actualizarinfoButton,SIGNAL(clicked()),this,SLOT(clickActualizar()));

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

void MetadataWindow::clickActualizar() {
    ModificarMetada->hide();

}


