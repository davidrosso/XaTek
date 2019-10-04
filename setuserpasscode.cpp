#include "setuserpasscode.h"

extern QString DateTimeFormat;
extern QString ConfigFilePath;
extern QString UserPasscode;

SetUserPasscode::SetUserPasscode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetUserPasscode)
{
    ui->setupUi(this);

    passcodeFirstEntry = "";
    passcodeSecondEntry = "";
    ui->lineEditPasscode->setText("");
    ui->labelTitle->setText("Enter User Passcode");
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
    ui->labelTitle->setText("Enter Admin Passcode");

    // return to the Setting Screen
    emit SettingsOptionsClicked();
}

void SetUserPasscode::on_buttonEnter_clicked()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software shall require the user to change the passcode during setup.

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
        if (passcodeFirstEntry == "")
        {
            passcodeFirstEntry = ui->lineEditPasscode->text();
            ui->lineEditPasscode->setText("");
            ui->labelTitle->setText("Reenter Admin Passcode");
        }
        else
        {
            passcodeSecondEntry = ui->lineEditPasscode->text();

            if(passcodeFirstEntry == passcodeSecondEntry)
            {
                QMessageBox::information(
                  this,
                  tr("Admin Passcode Created"),
                  tr("The Admin passcode was successfully created.") );

                // set the new user passcode
                QByteArray hashedInput(ui->lineEditPasscode->text().toStdString().c_str());
                UserPasscode = QCryptographicHash::hash(hashedInput,QCryptographicHash::Algorithm::Sha256).toHex();
                UpdateUserPasscode();

                ui->lineEditPasscode->setText("");

                // return to the Setting Screen
                emit SettingsOptionsClicked();
            }
            else
            {
                // per 11114-0016_01 ClotChip Software Requirements Specification.docx
                // Software will display error codes and appropriate messages to the user when errors occur.

                QMessageBox::information(
                  this,
                  tr("Passcodes do not match"),
                  tr("The passcodes entered do not match. Please start again.") );

                passcodeFirstEntry = "";
                passcodeSecondEntry = "";
                ui->lineEditPasscode->setText("");
                ui->labelTitle->setText("Enter Admin Passcode");

            }
        }
    }
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
