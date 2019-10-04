#include "setadminpasscode.h"

extern QString ConfigFilePath;
extern QString DateTimeFormat;
extern QString AdminPasscode;

SetAdminPasscode::SetAdminPasscode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetAdminPasscode)
{
    ui->setupUi(this);

    passcodeFirstEntry = "";
    passcodeSecondEntry = "";
    ui->lineEditPasscode->setText("");
    ui->labelAdminPasscode->setText("Enter Admin Passcode");
    ui->EnteredPassCode->setVisible(false);
}

SetAdminPasscode::~SetAdminPasscode()
{
    delete ui;
}

void SetAdminPasscode::on_button1_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "1");
}

void SetAdminPasscode::on_button2_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "2");
}

void SetAdminPasscode::on_button3_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "3");
}

void SetAdminPasscode::on_button4_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "4");
}

void SetAdminPasscode::on_button5_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "5");
}

void SetAdminPasscode::on_button6_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "6");
}

void SetAdminPasscode::on_button7_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "7");
}

void SetAdminPasscode::on_button8_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "8");
}

void SetAdminPasscode::on_button9_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "9");
}

void SetAdminPasscode::on_button0_clicked()
{
    ui->lineEditPasscode->setText(ui->lineEditPasscode->text() + "0");
}

void SetAdminPasscode::on_buttonBack_clicked()
{
    if(ui->buttonEnter->text() == "Settings")
    {
        passcodeFirstEntry = "";
        passcodeSecondEntry = "";
        ui->lineEditPasscode->setText("");
        ui->labelAdminPasscode->setText("Enter Admin Passcode");

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
        changeFont->setPixelSize(60);
        ui->buttonEnter->setFont(*changeFont);
    }
    else
    {
        passcodeFirstEntry = "";
        passcodeSecondEntry = "";
        ui->lineEditPasscode->setText("");
        ui->labelAdminPasscode->setText("Enter Admin Passcode");

        emit SettingsOptionsClicked();

    }

}

void SetAdminPasscode::on_buttonEnter_clicked()
{
    // per 11114-0016_01 ClotChip Software Requirements Specification.docx
    // The software shall require the user to change the passcode during setup.

    if(ui->buttonEnter->text() == "Settings")
    {
        passcodeFirstEntry = "";
        passcodeSecondEntry = "";
        ui->lineEditPasscode->setText("");
        ui->labelAdminPasscode->setText("Enter Admin Passcode");

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
        changeFont->setPixelSize(60);
        ui->buttonEnter->setFont(*changeFont);

        emit SettingsOptionsClicked();
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

        // reset variables
        passcodeFirstEntry = "";
        passcodeSecondEntry = "";
        ui->lineEditPasscode->setText("");
        ui->labelAdminPasscode->setText("Enter Admin Passcode");

    }
    else
    {
        if (passcodeFirstEntry == "")
        {
            passcodeFirstEntry = ui->lineEditPasscode->text();
            ui->lineEditPasscode->setText("");
            ui->labelAdminPasscode->setText("Reenter Admin Passcode");
        }
        else
        {
            passcodeSecondEntry = ui->lineEditPasscode->text();

            if(passcodeFirstEntry == passcodeSecondEntry)
            {
                // set the new user passcode
                QByteArray hashedInput(ui->lineEditPasscode->text().toStdString().c_str());
                AdminPasscode = QCryptographicHash::hash(hashedInput,QCryptographicHash::Algorithm::Sha256).toHex();
                //qDebug() << "Admin PC: " << AdminPasscode;
                UpdateAdminPasscode();

                ui->labelAdminPasscode->setText("Your New Admin Passcode is:");
                ui->buttonEnter->setText("Settings");
                QFont *changeFont = new QFont();
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

                // return to the Setting Screen
                //emit SettingsOptionsClicked();
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
                ui->labelAdminPasscode->setText("Enter Admin Passcode");

            }
        }
    }
}

void SetAdminPasscode::UpdateAdminPasscode()
{
    // update XaTekConfig.xml file
    QFile xmlFile (ConfigFilePath);
    xmlFile.open(QIODevice::ReadWrite);

    QByteArray xmlData(xmlFile.readAll());
    QDomDocument doc;
    doc.setContent(xmlData);

    // Get element in question
    QDomElement root = doc.documentElement();
    QDomElement nodeTag = root.firstChildElement("Admin_Passcode");

    // create a new node with a QDomText child
    QDomElement newNodeTag = doc.createElement(QString("Admin_Passcode"));
    QDomText newNodeText = doc.createTextNode(QString(AdminPasscode));
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
