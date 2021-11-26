//
// Created by maxgm on 25/11/21.
//

#include <iostream>
#include <QtWidgets>
#include <QObject>
#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QString>

#ifndef GALLERYTEC_PROYECTO3_METADATAWINDOW_H
#define GALLERYTEC_PROYECTO3_METADATAWINDOW_H


class MetadataWindow:public QWindow {
    Q_OBJECT
public:
    MetadataWindow();

    virtual ~MetadataWindow();

private:
    QWidget windowMetadata;
    QMainWindow * ModificarMetada;
    QPushButton *modificarMetadataButton;
    QPushButton *actualizarinfoButton;
    const QSize BUTTON_SIZE = QSize(90, 50);
    QLabel *imagenData;
    QLabel *autorData;
    QLabel *fechaData;
    QLabel *tamanoData;
    QLabel *descripcionData;
    QLineEdit *imagenEntry;
    QLineEdit *autorEntry;
    QLineEdit *fechaEntry;
    QLineEdit *tamanoEntry;
    QLineEdit *descripcionEntry;

    void setUpLabels();

    void setUpBotones();

    void setUpWidgets();


public slots:
    void clickedModificarMetadata();

    void clickActualizar();

};


#endif //GALLERYTEC_PROYECTO3_METADATAWINDOW_H
