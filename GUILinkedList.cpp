/***************************************************************************
 * AUTHOR          : Andrew Moss
 * Final Project   : GUI Linked Lists
 * CLASS           : CS 003 A
 * SECTION         : MW: 1:00 - 2:25 pm
 *                   TR: 1:00 - 3:05 pm
 * Due Date        : 06/11/18
 **************************************************************************/
#include "GUILinkedList.h"
#include "ui_GUILinkedList.h"
//#include "LinkedList.h"

//#include <iostream>
#include <cstdlib>
#include <string>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
using namespace std;

GUILinkedList::GUILinkedList(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::GUILinkedList)
{
    ui->setupUi(this);
    intCounter = 0;
    dblCounter = 0;
    strCounter = 0;

    ui->label->setText("<b>Select type: </b>");
    ui->label_2->setText("<b>Original List: </b>");
    ui->label_3->setText("<b>Copied List: </b>");
    ui->label_4->setText("<b>Andrew Moss</b>");
    ui->label_5->setText("<b>CS 003 A</b>");

//    scene = new QGraphicsScene(this);
//    ui->listView->setScene(scene);

//    QBrush redBrush(Qt::red);
//    QPen blackPen(Qt::black);
//    blackPen.setWidth(5);

//    rectangle = scene->addRect(10,10,100,100,blackPen,redBrush);
//    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}

GUILinkedList::~GUILinkedList()
{
    delete ui;
}

void GUILinkedList::on_push_backButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        L1.push_back(ui->textLine->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        D1.push_back(ui->textLine->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        S1.push_back(ui->textLine->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_displayButton_clicked()
{
    string var;
//    scene = new QGraphicsScene(this);
//    ui->listView->setScene(scene);

//    QPen blackPen(Qt::black);
//    blackPen.setWidth(5);

    if(ui->IntList->isChecked())
    {
        var = "IntList: ";
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList empty");
        }

        else
        {
            for(it = L1.begin(); it != L1.end(); ++it)
            {
                var += to_string(*it);
                var += " ";
    //                rectangle = scene->addRect(10,10,100,50,blackPen);
    //                QString::fromStdString(var)
            }
            ui->textEdit->setText(QString::fromStdString(var));
        }
    }

    else if(ui->DoubleList->isChecked())
    {
        var = "DblList: ";
        if(D1.isEmpty())
        {
            ui->textEdit->setText("DblList empty");
        }

        else
        {
            for(dt = D1.begin(); dt != D1.end(); ++dt)
            {
                var += to_string(*dt);
                var += " ";
            }
            ui->textEdit->setText(QString::fromStdString(var));
        }
    }

    else if(ui->StringList->isChecked())
    {
        var = "StrList: ";
        if(S1.isEmpty())
        {
            ui->textEdit->setText("StrList empty");
        }

        else
        {
            for(st = S1.begin(); st != S1.end(); ++st)
            {
                var += *st;
                var += " ";
            }
            ui->textEdit->setText(QString::fromStdString(var));
        }
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_push_frontButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        L1.push_front(ui->textLine->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        D1.push_front(ui->textLine->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        S1.push_front(ui->textLine->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_pop_frontButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList Empty");
        }

        L1.pop_front();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(D1.isEmpty())
        {
            ui->textEdit->setText("DblList Empty");
        }
        D1.pop_front();
    }

    else if(ui->StringList->isChecked())
    {
        if(S1.isEmpty())
        {
            ui->textEdit->setText("StrList Empty");
        }
        S1.pop_front();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }

}

void GUILinkedList::on_selectSortButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList Empty");
        }

        L1.select_sort();

    }

    else if(ui->DoubleList->isChecked())
    {
        if(D1.isEmpty())
        {
            ui->textEdit->setText("DblList Empty");
        }
        D1.select_sort();
    }

    else if(ui->StringList->isChecked())
    {
        if(S1.isEmpty())
        {
            ui->textEdit->setText("StrList Empty");
        }
        S1.select_sort();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_insert_sortedButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        L1.insert_sorted(ui->textLine->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        D1.insert_sorted(ui->textLine->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        S1.insert_sorted(ui->textLine->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_remove_dupeButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList Empty");
        }
        L1.remove_duplicates();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(D1.isEmpty())
        {
            ui->textEdit->setText("DblList Empty");
        }
        D1.remove_duplicates();
    }

    else if(ui->StringList->isChecked())
    {
        if(S1.isEmpty())
        {
            ui->textEdit->setText("StrList Empty");
        }
        S1.remove_duplicates();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_copyListButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        intCounter++;
        LinkedList<int> L2;
        L2 = L1;
        vIntList.push_back(L2);
        ui->comboBox->addItem("IntList" + QString::number(intCounter));

    }

    else if(ui->DoubleList->isChecked())
    {
        dblCounter++;
        LinkedList<double> D2;
        D2 = D1;
        vDblList.push_back(D2);
        ui->comboBox->addItem("DblList" + QString::number(dblCounter));
    }

    else if(ui->StringList->isChecked())
    {
        strCounter++;
        LinkedList<string> S2;
        S2 = S1;
        vStrList.push_back(S2);
        ui->comboBox->addItem("StrList" + QString::number(strCounter));
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_displayCopy_2_clicked()
{
    string var;
    index = 0;

    if((ui->comboBox->currentIndex() == -1) && (ui->IntList->isChecked() ||
        ui->DoubleList->isChecked() || ui->StringList->isChecked()))
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please copy a list"),0);
    }

    else if(ui->IntList->isChecked() && ui->comboBox->currentIndex() >= 0)
    {
        var = "IntList Copy: ";
        if(vIntList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("IntList empty");
        }

        else
        {
            for(it = vIntList[ui->comboBox->currentIndex()].begin();
                it != vIntList[ui->comboBox->currentIndex()].end(); ++it)
            {
                var += to_string(*it);
                var += " ";
            }
            ui->textEdit_2->setText(QString::fromStdString(var));
        }
    }

    else if(ui->DoubleList->isChecked() && ui->comboBox->currentIndex() >= 0)
    {
        var = "DblList Copy: ";
        if(vDblList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("DblList empty");
        }

        else
        {
            for(dt = vDblList[ui->comboBox->currentIndex()].begin();
                dt != vDblList[ui->comboBox->currentIndex()].end(); ++dt)
            {
                var += to_string(*dt);
                var += " ";
            }
            ui->textEdit_2->setText(QString::fromStdString(var));

        }
    }

    else if(ui->StringList->isChecked() && ui->comboBox->currentIndex() >= 0)
    {
        var = "StrList Copy: ";
        if(vStrList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("StrList empty");
        }

        else
        {
            for(st = vStrList[ui->comboBox->currentIndex()].begin();
                st != vStrList[ui->comboBox->currentIndex()].end(); ++st)
            {
                var += *st;
                var += " ";
            }
            ui->textEdit_2->setText(QString::fromStdString(var));
        }
    }

//    else if(ui->IntList->isChecked())
//    {
//        var = "IntList Copy: ";
//        if(vIntList[ui->comboBox->currentIndex()].isEmpty())
//        {
//            ui->textEdit_2->setText("IntList empty");
//        }

//        else
//        {
//            for(it = vIntList[ui->comboBox->currentIndex()].begin();
//                it != vIntList[ui->comboBox->currentIndex()].end(); ++it)
//            {
//                var += to_string(*it);
//                var += " ";
//                ui->textEdit_2->setText(QString::fromStdString(var));
//            }
//        }
//    }

//    else if(ui->DoubleList->isChecked())
//    {
//        var = "DblList Copy: ";
//        if(vDblList[ui->comboBox->currentIndex()].isEmpty())
//        {
//            ui->textEdit_2->setText("DblList empty");
//        }

//        else
//        {
//            for(dt = vDblList[ui->comboBox->currentIndex()].begin();
//                dt != vDblList[ui->comboBox->currentIndex()].end(); ++dt)
//            {
//                var += to_string(*dt);
//                var += " ";
//                ui->textEdit_2->setText(QString::fromStdString(var));
//            }
//        }
//    }

//    else if(ui->StringList->isChecked())
//    {
//        var = "StrList Copy: ";
//        if(vStrList[ui->comboBox->currentIndex()].isEmpty())
//        {
//            ui->textEdit_2->setText("StrList empty");
//        }

//        else
//        {
//            for(st = vStrList[ui->comboBox->currentIndex()].begin();
//                st != vStrList[ui->comboBox->currentIndex()].end(); ++st)
//            {
//                var += *st;
//                var += " ";
//                ui->textEdit_2->setText(QString::fromStdString(var));
//            }
//        }
//    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_pop_frontButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(vIntList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit->setText("IntList Empty");
        }

        vIntList[ui->comboBox->currentIndex()].pop_front();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(vDblList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit->setText("DblList Empty");
        }
        vDblList[ui->comboBox->currentIndex()].pop_front();
    }

    else if(ui->StringList->isChecked())
    {
        if(vStrList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit->setText("StrList Empty");
        }
        vStrList[ui->comboBox->currentIndex()].pop_front();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }

}

void GUILinkedList::on_remove_dupeButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(vIntList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("IntList Empty");
        }
        vIntList[ui->comboBox->currentIndex()].remove_duplicates();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(vDblList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("DblList Empty");
        }
        vDblList[ui->comboBox->currentIndex()].remove_duplicates();
    }

    else if(ui->StringList->isChecked())
    {
        if(vStrList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("StrList Empty");
        }
        vStrList[ui->comboBox->currentIndex()].remove_duplicates();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_selectSortButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(vIntList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("IntList Empty");
        }
        vIntList[ui->comboBox->currentIndex()].select_sort();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(vDblList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("DblList Empty");
        }
        vDblList[ui->comboBox->currentIndex()].select_sort();
    }

    else if(ui->StringList->isChecked())
    {
        if(vStrList[ui->comboBox->currentIndex()].isEmpty())
        {
            ui->textEdit_2->setText("StrList Empty");
        }
        vStrList[ui->comboBox->currentIndex()].select_sort();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_push_backButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        vIntList[ui->comboBox->currentIndex()].
                push_back(ui->textLine_2->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        vDblList[ui->comboBox->currentIndex()].
                push_back(ui->textLine_2->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        vStrList[ui->comboBox->currentIndex()].
                push_back(ui->textLine_2->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_push_frontButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        vIntList[ui->comboBox->currentIndex()].
                push_front(ui->textLine_2->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        vDblList[ui->comboBox->currentIndex()].
                push_front(ui->textLine_2->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        vStrList[ui->comboBox->currentIndex()].
                push_front(ui->textLine_2->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_insert_sortedButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        vIntList[ui->comboBox->currentIndex()].
                insert_sorted(ui->textLine_2->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        vDblList[ui->comboBox->currentIndex()].
                insert_sorted(ui->textLine_2->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        vStrList[ui->comboBox->currentIndex()].
                insert_sorted(ui->textLine_2->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_clearList_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        vIntList[ui->comboBox->currentIndex()].clear();
        ui->textEdit_2->setText("IntList cleared");

    }

    else if(ui->DoubleList->isChecked())
    {
        vDblList[ui->comboBox->currentIndex()].clear();
        ui->textEdit_2->setText("DblList cleared");
    }

    else if(ui->StringList->isChecked())
    {
        vStrList[ui->comboBox->currentIndex()].clear();
        ui->textEdit->setText("DblList cleared");
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}

void GUILinkedList::on_clearList_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList Empty");
        }
        L1.clear();
        ui->textEdit->setText("IntList cleared");
    }

    else if(ui->DoubleList->isChecked())
    {
        if(D1.isEmpty())
        {
            ui->textEdit->setText("DblList Empty");
        }
        D1.clear();
        ui->textEdit->setText("DblList cleared");

    }

    else if(ui->StringList->isChecked())
    {
        if(S1.isEmpty())
        {
            ui->textEdit->setText("StrList Empty");
        }
        S1.clear();
        ui->textEdit->setText("StrList cleared");
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
