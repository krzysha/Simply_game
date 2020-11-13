#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
int tablica[15];
int juz_bylo[15];
bool button_color[15];
int sekundy;

void losuj()
{
    QMessageBox msgBOX;
    int j = 0;
    for(int k=0;k<15;k++)
    {
        tablica[k] = 0;
    }
    for(int i=1;i<16;i++)
    {
        //powrot:
        int c = rand() % 15;
        if(tablica[c] == 0)
        {
            tablica[c] = i;
        }
        else{
            int n = c;
            while(1)
            {
                n = n + 1;
                if (n == 15)
                {
                    n = 0;
                }
                if (tablica[n] == 0)
                {
                    tablica[n] = i;
                    break;
                }
            }
        }
    }
}

void Zamien(int &tab1,int &tab2)
{
        int do_zmiany;
        do_zmiany = tab1;
        tab1 = tab2;
        tab2 = do_zmiany;
}

void Porownaj()
{
    bool wynik = true;
    QMessageBox Dobry_Wynik;
    for(int i=0;i<15;i++)
    {
        if(tablica[i] != (i+1))
        {
            wynik = false;
        }

    }
    if(wynik == true)
    {
        QString wynik = "Dobrze :)\nTwój czas: " + QString::number(sekundy);
        Dobry_Wynik.setText(wynik);
        Dobry_Wynik.exec();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QMessageBox start;
    start.setText("Ułóż jak najszybciej\nwe właciwej koljności");
    start.exec();
    ui->setupUi(this);
    on_Wymieszaj_clicked();
    sekundy = 0;
    //ui->label->setText(QString::number(sekundy));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(licz_czas()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::licz_czas()
{
    sekundy = sekundy + 1;
    //ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->label->setText(QString::number(sekundy));
}


void MainWindow::on_Wymieszaj_clicked()
{

    losuj();
    for(int i=0;i<15;i++)
    {
        button_color[i] = false;
    }
    ui->pushButton->setText(QString::number(tablica[0]));
    ui->pushButton->setStyleSheet("background-color:grey;");
    ui->pushButton_2->setText(QString::number(tablica[1]));
    ui->pushButton_2->setStyleSheet("background-color:grey;");
    ui->pushButton_3->setText(QString::number(tablica[2]));
    ui->pushButton_3->setStyleSheet("background-color:grey;");
    ui->pushButton_4->setText(QString::number(tablica[3]));
    ui->pushButton_4->setStyleSheet("background-color:grey;");
    ui->pushButton_5->setText(QString::number(tablica[4]));
    ui->pushButton_5->setStyleSheet("background-color:grey;");
    ui->pushButton_6->setText(QString::number(tablica[5]));
    ui->pushButton_6->setStyleSheet("background-color:grey;");
    ui->pushButton_7->setText(QString::number(tablica[6]));
    ui->pushButton_7->setStyleSheet("background-color:grey;");
    ui->pushButton_8->setText(QString::number(tablica[7]));
    ui->pushButton_8->setStyleSheet("background-color:grey;");
    ui->pushButton_9->setText(QString::number((tablica[8])));
    ui->pushButton_9->setStyleSheet("background-color:grey;");
    ui->pushButton_10->setText(QString::number((tablica[9])));
    ui->pushButton_10->setStyleSheet("background-color:grey;");
    ui->pushButton_11->setText(QString::number(tablica[10]));
    ui->pushButton_11->setStyleSheet("background-color:grey;");
    ui->pushButton_13->setText(QString::number(tablica[11]));
    ui->pushButton_13->setStyleSheet("background-color:grey;");
    ui->pushButton_14->setText(QString::number(tablica[12]));
    ui->pushButton_14->setStyleSheet("background-color:grey;");
    ui->pushButton_15->setText(QString::number(tablica[13]));
    ui->pushButton_15->setStyleSheet("background-color:grey;");
    ui->pushButton_16->setText(QString::number(tablica[14]));
    ui->pushButton_16->setStyleSheet("background-color:grey;");
    sekundy = 0;
    ui->label->setText(QString::number(sekundy));
}

void MainWindow::on_pushButton_clicked()
{
    bool stan = false;
    int this_number = 0;
    int zmienna;

    QMessageBox msgBOX;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 1:
                Zamien(tablica[this_number],tablica[1]);
                ui->pushButton_2->setText(QString::number(tablica[1]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_2->setStyleSheet("background-color:grey;");
                button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;

        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

    Porownaj();

}

void MainWindow::on_pushButton_2_clicked()
{
    bool stan = false;
    int this_number = 1;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_2->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_2->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_2->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();

}

void MainWindow::on_pushButton_3_clicked()
{
    bool stan = false;
    int this_number = 2;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_3->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_3->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_3->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_3->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_4_clicked()
{
    bool stan = false;
    int this_number = 3;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_4->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_4->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_4->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_4->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_5_clicked()
{
    bool stan = false;
    int this_number = 4;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_5->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_5->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_5->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_5->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_6_clicked()
{
    bool stan = false;
    int this_number = 5;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_6->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_6->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_6->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_6->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_7_clicked()
{
    bool stan = false;
    int this_number = 6;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_7->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_7->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_7->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_7->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_8_clicked()
{
    bool stan = false;
    int this_number = 7;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_8->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_8->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_8->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_8->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}


void MainWindow::on_pushButton_9_clicked()
{
    bool stan = false;
    int this_number = 8;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_9->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_9->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_9->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_9->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_10_clicked()
{
    bool stan = false;
    int this_number = 9;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_10->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_10->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_10->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_10->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_11_clicked()
{
    bool stan = false;
    int this_number = 10;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_11->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_11->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_11->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_11->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_13_clicked()
{
    bool stan = false;
    int this_number = 11;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_13->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_13->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_13->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_13->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_14_clicked()
{
    bool stan = false;
    int this_number = 12;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_14->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_14->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_14->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_14->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_15_clicked()
{
    bool stan = false;
    int this_number = 13;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_15->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 14:
                Zamien(tablica[this_number],tablica[14]);
                ui->pushButton_16->setText(QString::number(tablica[14]));
                ui->pushButton_15->setText(QString::number(tablica[this_number]));
                ui->pushButton_16->setStyleSheet("background-color:grey;");
                button_color[14] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_15->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_15->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}

void MainWindow::on_pushButton_16_clicked()
{
    bool stan = false;
    int this_number = 14;
    int zmienna;
    for(int i=0;i<15;i++)
    {
       if( button_color[i] == true)
       {
           if(i != this_number)
           {
               stan = true;
               zmienna = i;
           }
       }
    }
    if(stan == true)
    {
        switch(zmienna)
        {
            case 0:
                Zamien(tablica[this_number],tablica[0]);
                ui->pushButton->setText(QString::number(tablica[0]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton->setStyleSheet("background-color:grey;");
                button_color[0] = false;
            break;

            case 1:
                    Zamien(tablica[this_number],tablica[1]);
                    ui->pushButton_2->setText(QString::number(tablica[1]));
                    ui->pushButton_16->setText(QString::number(tablica[this_number]));
                    ui->pushButton_2->setStyleSheet("background-color:grey;");
                    button_color[1] = false;
            break;

            case 2:
                Zamien(tablica[this_number],tablica[2]);
                ui->pushButton_3->setText(QString::number(tablica[2]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_3->setStyleSheet("background-color:grey;");
                button_color[2] = false;
            break;

            case 3:
                Zamien(tablica[this_number],tablica[3]);
                ui->pushButton_4->setText(QString::number(tablica[3]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_4->setStyleSheet("background-color:grey;");
                button_color[3] = false;
            break;

            case 4:
                Zamien(tablica[this_number],tablica[4]);
                ui->pushButton_5->setText(QString::number(tablica[4]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_5->setStyleSheet("background-color:grey;");
                button_color[4] = false;
            break;

            case 5:
                Zamien(tablica[this_number],tablica[5]);
                ui->pushButton_6->setText(QString::number(tablica[5]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_6->setStyleSheet("background-color:grey;");
                button_color[5] = false;
            break;

            case 6:
                Zamien(tablica[this_number],tablica[6]);
                ui->pushButton_7->setText(QString::number(tablica[6]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_7->setStyleSheet("background-color:grey;");
                button_color[6] = false;
            break;

            case 7:
                Zamien(tablica[this_number],tablica[7]);
                ui->pushButton_8->setText(QString::number(tablica[7]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_8->setStyleSheet("background-color:grey;");
                button_color[7] = false;
            break;

            case 8:
                Zamien(tablica[this_number],tablica[8]);
                ui->pushButton_9->setText(QString::number(tablica[8]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_9->setStyleSheet("background-color:grey;");
                button_color[8] = false;
            break;

            case 9:
                Zamien(tablica[this_number],tablica[9]);
                ui->pushButton_10->setText(QString::number(tablica[9]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_10->setStyleSheet("background-color:grey;");
                button_color[9] = false;
            break;

            case 10:
                Zamien(tablica[this_number],tablica[10]);
                ui->pushButton_11->setText(QString::number(tablica[10]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_11->setStyleSheet("background-color:grey;");
                button_color[10] = false;
            break;

            case 11:
                Zamien(tablica[this_number],tablica[11]);
                ui->pushButton_13->setText(QString::number(tablica[11]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_13->setStyleSheet("background-color:grey;");
                button_color[11] = false;
            break;

            case 12:
                Zamien(tablica[this_number],tablica[12]);
                ui->pushButton_14->setText(QString::number(tablica[12]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_14->setStyleSheet("background-color:grey;");
                button_color[12] = false;
            break;

            case 13:
                Zamien(tablica[this_number],tablica[13]);
                ui->pushButton_15->setText(QString::number(tablica[13]));
                ui->pushButton_16->setText(QString::number(tablica[this_number]));
                ui->pushButton_15->setStyleSheet("background-color:grey;");
                button_color[13] = false;
            break;
        }
        stan = false;
    }
    else
    {
        if(button_color[this_number] == false)
        {
            ui->pushButton_16->setStyleSheet("background-color:blue;");
            button_color[this_number] = true;
        }else
        {
            ui->pushButton_16->setStyleSheet("background-color:grey;");
            button_color[this_number] = false;
        }

    }

     Porownaj();
}
