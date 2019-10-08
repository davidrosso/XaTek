#include "setuserpasscode.h"

extern QString DateTimeFormat;
extern QString ConfigFilePath;
extern QString UserPasscode;
extern QString AdminPasscode;

SetUserPasscode::SetUserPasscode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUserPasscode)
{
    ui->setupUi(this);

    ShowFirstScreen();
    screenCounter = 1;
}

SetUserPasscode::~SetUserPasscode()
{
    delete ui;
}

void SetUserPasscode::on_button1_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "1");
}

void SetUserPasscode::on_button2_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "2");
}

void SetUserPasscode::on_button3_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "3");
}

void SetUserPasscode::on_button4_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "4");
}

void SetUserPasscode::on_button5_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "5");
}

void SetUserPasscode::on_button6_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "6");
}

void SetUserPasscode::on_button7_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "7");
}

void SetUserPasscode::on_button8_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "8");
}

void SetUserPasscode::on_button9_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "9");
}

void SetUserPasscode::on_button0_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "0");
}

void SetUserPasscode::on_buttonBack_clicked()
{
    passcodeFirstEntry = "";
    passcodeSecondEntry = "";
    ui->lineEditPasscode->setText("");    

    if(ui->buttonEnter->text() == "Settings")
    {
        //Return to Set User Passcode Screen
        screenCounter = 2;
        ShowSecondScreen();
    }
    else
    {
        // return to the Setting Screen
        ShowFirstScreen();
        screenCounter = 1;
        emit SettingsOptionsClicked();
    }
}

void SetUserPasscode::on_buttonEnter_clicked()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software shall require the user to change the passcode during setup.
    if(ui->buttonEnter->text() == "Settings")
    {
        emit SettingsOptionsClicked();
        ShowFirstScreen();
        return;
    }

    if(ui->lineEditPasscode->text().length() < 4)
    {
        // per 11114-0016_01 ClotChip Software Requirements Specification.docx
        // Software will display error codes and appropriate messages to the user when errors occur.

        QMessageBox::information(
          this,
          tr("Invalid Admin Passcode"),
          tr("Passcodes must be a minumum or 4 digits.") );
    }
    else
    {
        switch(screenCounter)
        {
            case 1:
            {
                //Enter Admin Password First
                QByteArray hashedInput(ui->lineEditPasscode->text().toStdString().c_str());
                if(QCryptographicHash::hash(hashedInput,QCryptographicHash::Algorithm::Sha256).toHex() == AdminPasscode)
                {
                    screenCounter = 2;
                    ShowSecondScreen();
                }
                else
                {
                    ui->lineEditPasscode->setText("");
                    screenCounter = 1;
                    qDebug() << "Invalid Admin Password. Try again";
                }
                break;
            }
            case 2:
            {
                //Enter New User Passcode
                passcodeFirstEntry = ui->lineEditPasscode->text();
                ui->lineEditPasscode->setText("");
                ShowThirdScreen();
                screenCounter = 3;
                break;
            }
            case 3:
            {
                //Enter User Passcode again
                passcodeSecondEntry = ui->lineEditPasscode->text();
                if (passcodeFirstEntry == passcodeSecondEntry)
                {
                    // set the new user passcode
                    QByteArray hashedInput(ui->lineEditPasscode->text().toStdString().c_str());
                    UserPasscode = QCryptographicHash::hash(hashedInput,QCryptographicHash::Algorithm::Sha256).toHex();
                    UpdateUserPasscode();
                    ShowFourthScreen();
                    screenCounter = 1;
                }
                else
                {
                    //Reset fields
                    passcodeFirstEntry = "";
                    passcodeSecondEntry = "";
                    ui->lineEditPasscode->setText("");
                    ShowSecondScreen();
                    screenCounter = 2;
                    //Should alert an error message that passcodes did not match
                    qDebug() << "Passcodes did not match. Try again";
                }
                break;
            }
        }
    }

    /**
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // Software will display error codes and appropriate messages to the user when errors occur.

    QMessageBox::information(
      this,
      tr("Admin Passcode Created"),
      tr("The Admin passcode was successfully created.") );

    QMessageBox::information(
      this,
      tr("Passcodes do not match"),
      tr("The passcodes entered do not match. Please start again.") );
    **/

}

void SetUserPasscode::UpdateUserPasscode()
{
    // update XaTekConfig.xml file
    QFile xmlFile (ConfigFilePath);
    xmlFile.open(QIODevice::ReadWrite);

    QByteArray xmlData(xmlFile.readAll());
    QDomDocument doc;
    doc.setContent(xmlData);

    // Get element in question
    QDomElement root = doc.documentElement();
    QDomElement nodeTag = root.firstChildElement("User_Passcode");

    // create a new node with a QDomText child
    QDomElement newNodeTag = doc.createElement(QString("User_Passcode"));
    QDomText newNodeText = doc.createTextNode(QString(UserPasscode));
    newNodeTag.setAttribute("modified", QDateTime::currentDateTime().toString(DateTimeFormat));
    newNodeTag.appendChild(newNodeText);

    // replace existing node with new node
    root.replaceChild(newNodeTag, nodeTag);

    // Write changes to same file
    xmlFile.resize(0);
    QTextStream stream;
    stream.setDevice(&xmlFile);
    doc.save(stream, 4);

    xmlFile.close();
}

void SetUserPasscode::ShowFirstScreen()
{
    //passcodeFirstEntry = "";
    //passcodeSecondEntry = "";
    ui->lineEditPasscode->setText("");
    ui->labelTitle->setText("Enter Admin Passcode");

    ui->button0->setVisible(true);
    ui->button1->setVisible(true);
    ui->button2->setVisible(true);
    ui->button3->setVisible(true);
    ui->button4->setVisible(true);
    ui->button5->setVisible(true);
    ui->button6->setVisible(true);
    ui->button7->setVisible(true);
    ui->button8->setVisible(true);
    ui->button9->setVisible(true);
    ui->EnteredPassCode->setVisible(false);
    ui->buttonEnter->setText("Enter");
    QFont *changeFont = new QFont();
    changeFont->setFamily("Roboto");
    changeFont->setPixelSize(60);
    ui->buttonEnter->setFont(*changeFont);
}

void SetUserPasscode::ShowSecondScreen()
{
    ShowFirstScreen();
    ui->lineEditPasscode->setText("");
    ui->labelTitle->setText("Enter User Passcode");
}

void SetUserPasscode::ShowThirdScreen()
{
    ShowFirstScreen();
    ui->lineEditPasscode->setText("");
    ui->labelTitle->setText("Reenter User Passcode");
}

void SetUserPasscode::ShowFourthScreen()
{
    ui->labelTitle->setText("Your New User Passcode is:");
    ui->buttonEnter->setText("Settings");
    QFont *changeFont = new QFont();
    changeFont->setFamily("Roboto");
    changeFont->setPixelSize(55);
    ui->buttonEnter->setFont(*changeFont);
    ui->EnteredPassCode->setVisible(true);
    ui->EnteredPassCode->setText(passcodeFirstEntry);
    ui->button0->setVisible(false);
    ui->button1->setVisible(false);
    ui->button2->setVisible(false);
    ui->button3->setVisible(false);
    ui->button4->setVisible(false);
    ui->button5->setVisible(false);
    ui->button6->setVisible(false);
    ui->button7->setVisible(false);
    ui->button8->setVisible(false);
    ui->button9->setVisible(false);

    ui->lineEditPasscode->setText("");
}
