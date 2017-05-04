#include <QIntValidator>
#include <QMessageBox>
#include <QString>
#include <time.h>
#include "MainUI.h"
#include "ui_MainUI.h"

MainUI::MainUI() : QMainWindow(), ui(new Ui::MainUI){
    ui->setupUi(this);
    qsrand(time(0));
}

MainUI::~MainUI(){
}


void MainUI::makePass() {
    int length = ui->lengthEdit->text().toInt(); //check length
    if (length <= 0) {
        QMessageBox::critical(this, tr("Error"), tr("You must enter value > 0."));
        return ;
    }
    QString lchars = "";
    char l; //make array of chars
    for (l=0x61;l<0x7b;l++) { //adds a-z
        lchars += l;}

    QString uchars = "";
    char u; //make array of chars
    for (u=0x41;u<0x5b;u++) { //adds A-Z
        uchars += u;}

    QString nchars ="";
    char n; //make array of chars
    for (n=0x30;n<0x3a;n++) { //adds 0-9
        nchars += n;}

    QString _chars ="";{
        _chars += "_";}

    QString additional_chars = ui->specialcharEdit->text();

    QString charsArray = "";{
        charsArray += lchars;  //make simple a-z array
    }
    if (ui->caseBox->isChecked()) { //adds A-Z
        charsArray += uchars;
    }
    if (ui->numBox->isChecked()) { //adds num
        charsArray += nchars;
    }    
    if (ui->underscoreBox->isChecked()) { //adds _
        charsArray += _chars;
    }
        charsArray += additional_chars; //adds special chars of user choice


    //makePass
    ui->pwdEdit->clear();
    ui->pwdEdit->setText(makePwd(charsArray, length));
}

void MainUI::copyPass() {
    //copying pass to clipboard
    ui->pwdEdit->selectAll();
    ui->pwdEdit->copy();
    ui->pwdEdit->deselect();
}


QString MainUI::makePwd(QString chars, int length) {
  char Value;
  int plength = chars.length();
QString result = "";
  int i;
  for (i=0;i<length;i++){
        Value = 0 + (qrand() % plength);	//make number in [0;plength-1]
        result += chars[Value];
  }
    return result;
}
