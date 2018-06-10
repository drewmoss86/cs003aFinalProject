/***************************************************************************
 * AUTHOR          : Andrew Moss
 * Final Project   : GUI Linked Lists
 * CLASS           : CS 003 A
 * SECTION         : MW: 1:00 - 2:25 pm
 *                   TR: 1:00 - 3:05 pm
 * Due Date        : 06/11/18
 **************************************************************************/
#ifndef GUILINKEDLIST_H
#define GUILINKEDLIST_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QWheelEvent>

#include "LinkedList.h"
//#include "mynode.h"

using namespace std;

namespace Ui {
class GUILinkedList;
}

class GUILinkedList : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUILinkedList(QWidget *parent = 0);
    ~GUILinkedList();


private slots:
    void on_displayButton_clicked();

    void on_push_backButton_clicked();

    void on_push_frontButton_clicked();

    void on_pop_frontButton_clicked();

    void on_selectSortButton_clicked();

    void on_insert_sortedButton_clicked();

    void on_copyListButton_clicked();

    void on_remove_dupeButton_clicked();

    void on_clearList_clicked();

    void on_displayCopy_2_clicked();

    void on_pop_frontButton_2_clicked();

    void on_remove_dupeButton_2_clicked();

    void on_selectSortButton_2_clicked();

    void on_push_backButton_2_clicked();

    void on_push_frontButton_2_clicked();

    void on_insert_sortedButton_2_clicked();

    void on_clearList_2_clicked();


private:
    Ui::GUILinkedList *ui;
//    QGraphicsScene *scene;
//    QGraphicsEllipseItem *ellipse;
//    QGraphicsRectItem *rectangle;

    LinkedList<int> L1;     //int list
    LinkedList<double> D1;  //double list
    LinkedList<string> S1;  //string list

    vector< LinkedList<int> > vIntList;
    vector< LinkedList<double> > vDblList;
    vector< LinkedList<string> > vStrList;

    LinkedList<int> L2;     //int copy list
    LinkedList<double> D2;  //double copy list
    LinkedList<string> S2;  //string copy list

    Iterator<int> it;       //int list iterator
    Iterator<double> dt;    //double list iterator
    Iterator<string> st;    //string list iterator

    int intCounter;
    int dblCounter;
    int strCounter;
    int index;

};


#endif // GUILINKEDLIST_H
