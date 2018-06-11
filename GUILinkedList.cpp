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


    intCount = 0; //initialize int counter
    dblCount = 0; //initialize double counter
    strCount = 0; //initialize string counter
    intVar = "";  //initialize int variable holding list
    dblVar = "";  //initialize double variable holding list
    strVar = "";  //initialize string variable holding list

    //labels
    ui->label->setText("<b>Select type: </b>");
    ui->label_2->setText("<b>Original List: </b>");
    ui->label_3->setText("<b>Copied List: </b>");
    ui->label_4->setText("<b>Andrew Moss</b>");
    ui->label_5->setText("<b>CS 003 A</b>");

    //initialize combobox
    ui->comboBox->addItem("Empty");

    //graphical representation of node
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPen blackPen(Qt::black);
    blackPen.setWidth(5);

    rectangle = scene->addRect(10,10,0,0,blackPen);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}
/**********************************************************
*
*  Method ~GUILinkedList(): Class GUILinkedList
*  _________________________________________________________
*  This destructor deallocates memory of GUI LinkedList
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function deallocates memory of GUI LinkedList
***********************************************************/
GUILinkedList::~GUILinkedList()
{
    delete ui;
}
/**********************************************************
*
*  Method on_push_backButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method pushes back node in list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
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
/**********************************************************
*
*  Method on_displayButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays values stored in node of linked list
*    when pushed
***********************************************************/
void GUILinkedList::on_displayButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        intVar = "IntList: ";
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList empty");
        }

        else
        {
            for(it = L1.begin(); it != L1.end(); ++it)
            {
                intVar += to_string(*it);
                intVar += " ";
            }
            ui->textEdit->setText(QString::fromStdString(intVar));
        }
    }

    else if(ui->DoubleList->isChecked())
    {
        dblVar = "DblList: ";
        if(D1.isEmpty())
        {
            ui->textEdit->setText("DblList empty");
        }

        else
        {
            for(dt = D1.begin(); dt != D1.end(); ++dt)
            {
                dblVar += to_string(*dt);
                dblVar += " ";
            }
            ui->textEdit->setText(QString::fromStdString(dblVar));
        }
    }

    else if(ui->StringList->isChecked())
    {
        strVar = "StrList: ";
        if(S1.isEmpty())
        {
            ui->textEdit->setText("StrList empty");
        }

        else
        {
            for(st = S1.begin(); st != S1.end(); ++st)
            {
                strVar += *st;
                strVar += " ";
            }
            ui->textEdit->setText(QString::fromStdString(strVar));
        }
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_push_frontButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
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
/**********************************************************
*
*  Method on_pop_frontButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
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
/**********************************************************
*
*  Method on_selectSortButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
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
/**********************************************************
*
*  Method on_insert_sortedButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
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
/**********************************************************
*
*  Method on_remove_dupeButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
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
/**********************************************************
*
*  Method on_copyListButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_copyListButton_clicked()
{
    if(ui->IntList->isChecked())
    {
        strCount++;
        LinkedList<int> L2;
        L2 = L1;
        vIntList.push_back(L2);
        ui->comboBox->addItem("CopiedList");
    }

    else if(ui->DoubleList->isChecked())
    {
        dblCount++;
        LinkedList<double> D2;
        D2 = D1;
        vDblList.push_back(D2);
        ui->comboBox->addItem("CopiedList");
    }

    else if(ui->StringList->isChecked())
    {
        strCount++;
        LinkedList<string> S2;
        S2 = S1;
        vStrList.push_back(S2);
        ui->comboBox->addItem("CopiedList");
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_displayCopy_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_displayCopy_2_clicked()
{
    if((ui->comboBox->currentIndex() == 0) && (ui->IntList->isChecked() ||
        ui->DoubleList->isChecked() || ui->StringList->isChecked()))
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please copy a list"),0);
    }

    else if(ui->IntList->isChecked() && ui->comboBox->currentIndex() > 0)
    {
        intCount++;
        intVar = "IntList Copy: ";
        if(vIntList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("IntList empty");
        }

        else
        {
            for(it = vIntList[ui->comboBox->currentIndex()-1].begin();
                it != vIntList[ui->comboBox->currentIndex()-1].end(); ++it)
            {
                intVar += to_string(*it);
                intVar += " ";
            }
            ui->textEdit_2->setText(QString::fromStdString(intVar));
            vIntList[ui->comboBox->currentIndex()+1];
        }
    }

    else if(ui->DoubleList->isChecked() && ui->comboBox->currentIndex() > 0)
    {
        dblCount++;
        dblVar = "DblList Copy: ";
        if(vDblList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("DblList empty");
        }

        else
        {
            for(dt = vDblList[ui->comboBox->currentIndex()-1].begin();
                dt != vDblList[ui->comboBox->currentIndex()-1].end(); ++dt)
            {
                dblVar += to_string(*dt);
                dblVar += " ";
            }
            ui->textEdit_2->setText(QString::fromStdString(dblVar));

        }
    }

    else if(ui->StringList->isChecked() && ui->comboBox->currentIndex() > 0)
    {
        strCount++;
        strVar = "StrList Copy: ";
        if(vStrList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("StrList empty");
        }

        else
        {
            for(st = vStrList[ui->comboBox->currentIndex()-1].begin();
                st != vStrList[ui->comboBox->currentIndex()-1].end(); ++st)
            {
                strVar += *st;
                strVar += " ";
            }
            ui->textEdit_2->setText(QString::fromStdString(strVar));
        }
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_pop_frontButton_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_pop_frontButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(vIntList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit->setText("IntList Empty");
        }

        vIntList[ui->comboBox->currentIndex()-1].pop_front();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(vDblList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit->setText("DblList Empty");
        }
        vDblList[ui->comboBox->currentIndex()-1].pop_front();
    }

    else if(ui->StringList->isChecked())
    {
        if(vStrList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit->setText("StrList Empty");
        }
        vStrList[ui->comboBox->currentIndex()-1].pop_front();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }

}
/**********************************************************
*
*  Method on_remove_dupeButton_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_remove_dupeButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(vIntList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("IntList Empty");
        }
        vIntList[ui->comboBox->currentIndex()-1].remove_duplicates();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(vDblList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("DblList Empty");
        }
        vDblList[ui->comboBox->currentIndex()-1].remove_duplicates();
    }

    else if(ui->StringList->isChecked())
    {
        if(vStrList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("StrList Empty");
        }
        vStrList[ui->comboBox->currentIndex()-1].remove_duplicates();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_selectSortButton_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_selectSortButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(vIntList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("IntList Empty");
        }
        vIntList[ui->comboBox->currentIndex()-1].select_sort();
    }

    else if(ui->DoubleList->isChecked())
    {
        if(vDblList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("DblList Empty");
        }
        vDblList[ui->comboBox->currentIndex()-1].select_sort();
    }

    else if(ui->StringList->isChecked())
    {
        if(vStrList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("StrList Empty");
        }
        vStrList[ui->comboBox->currentIndex()-1].select_sort();
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_push_backButton_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_push_backButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        vIntList[ui->comboBox->currentIndex()-1].
                push_back(ui->textLine_2->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        vDblList[ui->comboBox->currentIndex()-1].
                push_back(ui->textLine_2->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        vStrList[ui->comboBox->currentIndex()-1].
                push_back(ui->textLine_2->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_push_frontButton_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_push_frontButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        vIntList[ui->comboBox->currentIndex()-1].
                push_front(ui->textLine_2->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        vDblList[ui->comboBox->currentIndex()-1].
                push_front(ui->textLine_2->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        vStrList[ui->comboBox->currentIndex()-1].
                push_front(ui->textLine_2->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method operator=(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_insert_sortedButton_2_clicked()
{
    if(ui->IntList->isChecked())
    {
        vIntList[ui->comboBox->currentIndex()-1].
                insert_sorted(ui->textLine_2->text().toInt());
    }

    else if(ui->DoubleList->isChecked())
    {
        vDblList[ui->comboBox->currentIndex()-1].
                insert_sorted(ui->textLine_2->text().toDouble());
    }

    else if(ui->StringList->isChecked())
    {
        vStrList[ui->comboBox->currentIndex()-1].
                insert_sorted(ui->textLine_2->text().toStdString());
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_clearList_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_clearList_2_clicked()
{
    if(ui->IntList->isChecked() && ui->comboBox->currentIndex() > 0)
    {
        vIntList[ui->comboBox->currentIndex()-1].clear();
        ui->textEdit_2->setText("IntList cleared");

    }

    else if(ui->DoubleList->isChecked() && ui->comboBox->currentIndex() > 0)
    {
        vDblList[ui->comboBox->currentIndex()-1].clear();
        ui->textEdit_2->setText("DblList cleared");
    }

    else if(ui->StringList->isChecked() && ui->comboBox->currentIndex() > 0)
    {
        vStrList[ui->comboBox->currentIndex()-1].clear();
        ui->textEdit->setText("DblList cleared");
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_clearList_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_clearList_clicked()
{
    if(ui->IntList->isChecked())
    {
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList Empty");
        }
        L1.clear();
        ui->comboBox->removeItem(ui->comboBox->currentIndex());
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
/**********************************************************
*
*  Method on_displayPortionButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_displayPortionButton_clicked()
{
    int start;
    int end;
    int count;

    count = 1;
    start = ui->portionBegin->text().toInt();
    end = ui->portionEnd->text().toInt();

    if(ui->portionBegin->text() == "" || ui->portionEnd->text() == "")
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please enter some values"),0);
    }

    else if(start > end)
    {
        QMessageBox::information(this,tr("Invalid!"),
                                 tr("Invalid range"),0);
    }

    else if(ui->IntList->isChecked())
    {
        intVar = "IntList Portion: ";
        if(L1.isEmpty())
        {
            ui->textEdit->setText("IntList empty");
        }

        else
        {
            for(it = L1.begin(); it != L1.end(); ++it)
            {
                if(count >= start && count <= end)
                {
                    intVar += to_string(*it);
                    intVar += " ";
                }
                count++;
            }
            ui->textEdit->setText(QString::fromStdString(intVar));
        }
    }

    else if(ui->DoubleList->isChecked())
    {
        dblVar = "DblList Portion: ";
        if(D1.isEmpty())
        {
            ui->textEdit->setText("DblList empty");
        }

        else
        {
            for(dt = D1.begin(); dt != D1.end(); ++dt)
            {
                if(count >= start && count <= end)
                {
                    dblVar += to_string(*dt);
                    dblVar += " ";
                }
                count++;
            }
            ui->textEdit->setText(QString::fromStdString(dblVar));

        }
    }

    else if(ui->StringList->isChecked())
    {
        strVar = "StrList Portion: ";
        if(S1.isEmpty())
        {
            ui->textEdit->setText("StrList empty");
        }

        else
        {
            for(st = S1.begin(); st != S1.end(); ++st)
            {
                if(count >= start && count <= end)
                {
                    strVar += *st;
                    strVar += " ";
                }
                count++;
            }
            ui->textEdit->setText(QString::fromStdString(strVar));
        }
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_displayPortionButton_2_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_displayPortionButton_2_clicked()
{
    int start;
    int end;
    int count;

    count = 1;
    start = ui->portionBegin_2->text().toInt();
    end = ui->portionEnd_2->text().toInt();

    if(ui->portionBegin_2->text() == "" || ui->portionEnd_2->text() == "")
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please enter some values"),0);
    }

    else if(start > end)
    {
        QMessageBox::information(this,tr("Invalid!"),
                                 tr("Invalid range"),0);
    }

    else if(ui->IntList->isChecked())
    {
        intVar = "IntList Portion: ";
        if(vIntList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("IntList empty");
        }

        else
        {
            for(it = vIntList[ui->comboBox->currentIndex()-1].begin();
                it != vIntList[ui->comboBox->currentIndex()-1].end(); ++it)
            {
                if(count >= start && count <= end)
                {
                    intVar += to_string(*it);
                    intVar += " ";
                }
                count++;
            }
            ui->textEdit_2->setText(QString::fromStdString(intVar));
        }
    }

    else if(ui->DoubleList->isChecked())
    {
        dblVar = "DblList Portion: ";
        if(vDblList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("DblList empty");
        }

        else
        {
            for(dt = vDblList[ui->comboBox->currentIndex()-1].begin();
                dt != vDblList[ui->comboBox->currentIndex()-1].end(); ++dt)
            {
                if(count >= start && count <= end)
                {
                    dblVar += to_string(*dt);
                    dblVar += " ";
                }
                count++;
            }
            ui->textEdit_2->setText(QString::fromStdString(dblVar));

        }
    }

    else if(ui->StringList->isChecked())
    {
        strVar = "StrList Portion: ";
        if(vStrList[ui->comboBox->currentIndex()-1].isEmpty())
        {
            ui->textEdit_2->setText("StrList empty");
        }

        else
        {
            for(st = vStrList[ui->comboBox->currentIndex()-1].begin();
                st != vStrList[ui->comboBox->currentIndex()-1].end(); ++st)
            {
                if(count >= start && count <= end)
                {
                    strVar += *st;
                    strVar += " ";
                }
                count++;
            }
            ui->textEdit_2->setText(QString::fromStdString(strVar));
        }
    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
/**********************************************************
*
*  Method on_graphicsDisplayButton_clicked(): Class GUILinkedList
*  _________________________________________________________
*  This method prints values stored in node of linked list
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function displays to a single line all of the int values stored
*    in the list, each separated by a space. It should NOT output a newline
*    or space at the end.
***********************************************************/
void GUILinkedList::on_graphicsDisplayButton_clicked()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QPen blackPen(Qt::black);
    blackPen.setWidth(5);

    if(ui->IntList->isChecked())
    {
        if(L1.isEmpty())
        {

        }

        else
        {
            for(it = L1.begin(); it != L1.end(); ++it)
            {
                rectangle = scene->addRect(0,0,75,50,blackPen);
            }
        }

    }

    else if(ui->DoubleList->isChecked())
    {

    }

    else if(ui->StringList->isChecked())
    {

    }

    else
    {
        QMessageBox::information(this, tr("Invalid!"),
                                 tr("Please select a type"),0);
    }
}
