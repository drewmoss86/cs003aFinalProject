/***************************************************************************
 * AUTHOR          : Andrew Moss
 * Final Project   : GUI Linked Lists
 * CLASS           : CS 003 A
 * SECTION         : MW: 1:00 - 2:25 pm
 *                   TR: 1:00 - 3:05 pm
 * Due Date        : 06/11/18
 **************************************************************************/
#include "GUILinkedList.h"
//#include "graphwidget.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    GraphWidget *widget = new GraphWidget;


    GUILinkedList GUIList;
//    GUIList.setCentralWidget(widget);

    GUIList.show();
    return app.exec();
}
