#include "mainwindow14.h"
#include "mainwindow8.h"
#include "ui_mainwindow14.h"
#include "ui_mainwindow8.h"
MainWindow14::MainWindow14(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow14)
{
    ui->setupUi(this);
    QIcon icon("C:/Users/12234/Desktop/s.jpg");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("家电信息管理系统"));
    ui->pushButton->setText("按住说话");
}

MainWindow14::~MainWindow14()
{
    delete ui;
}
MainWindow14::MainWindow14(QMainWindow* parent) {
    this->parent = parent;
}

void MainWindow14::on_pushButton_pressed()
{
    ui->pushButton->setText("松开识别");
    //开始录音
    Audio=new audio;
    Audio->startAudio("D:\\1.pcm");

}


void MainWindow14::on_pushButton_released()
{
    Audio->stopAudio();
    //停止录音

    ui->pushButton->setText("开始识别");
    //开始识别
    Speach m_speech;
    QString text=m_speech.speechIdentify("D:\\1.pcm");
    ui->textEdit->setText(text);
    ui->pushButton->setText("按住说话");
}


void MainWindow14::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}


void MainWindow14::on_pushButton_3_clicked()
{
    this->hide();
    MainWindow8* getAudio = new MainWindow8();
    getAudio->show();
    getAudio->ui->lineEdit->setText(ui->textEdit->toPlainText());
}

