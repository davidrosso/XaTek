import QtQuick 2.2
import QtQuick.Controls 2.2
import "scripts.js" as Scripts

//Properties for each Tumbler Object stored here
Item{
    id: tumblerSettings

    //Base sizes
    property int tumblerHeight: 200
    property int tumblerWidth: 100
    property int tumblerFontSize: 32

    property string tumblerColor: "white"

    //Saved settings here
    property var saveMonth: ""
    property var saveDay: ""
    property var saveHour: ""
    property var saveMin: ""

    signal updateMonth(string text)
    signal updateDay(string text)
    signal updateHour(string text)
    signal updateMinute(string text)

    function setMonth(month){
       saveMonth = month;
       monthTumbler.currentIndex = month;
       //console.log(saveMonth)
       return month;
    }
    function setDay(day){
        saveDay = day;
        dayTumbler.currentIndex = day -1;
        return day -1;
    }
    function setHour(hour){
        saveHour = hour;
        hourTumbler.currentIndex = hour;
        return hour;
    }
    function setMinute(minute){
        saveMin = minute;
        if(minute < 15)
        {
            minuteTumbler.currentIndex = 0;
        }
        else if(minute >= 15 && minute < 30 )
        {
            minuteTumbler.currentIndex = 1;
        }
        else if(minute >= 30 && minute < 45 )
        {
            minuteTumbler.currentIndex = 2;
        }
        else if(minute >= 45)
        {
            minuteTumbler.currentIndex = 3;
        }
        //minuteTumbler.currentIndex = minute;
        return minute;
    }

    //Main Window
    Rectangle {
        id: dateTimeWindow
        visible: true
        width: selectorWheel.width
        height: selectorWheel.height //Match dimensions of tumbler Module
        color: "#00000000" //Transparent background
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        //Contain all tumbler features/objects
        Rectangle {
            id: selectorWheel
            width: row.implicitWidth + 10
            height: row.implicitHeight + 10
            anchors.horizontalCenter: parent.horizontalCenter //Set to horizontal center of window
            anchors.verticalCenter: parent.verticalCenter //Set to vertical center of window
            color: "#00000000" //Transparent background
            radius: 10 //Rounded edges

            //Rectangle that surrounds the selected options
            Rectangle {
                id: selectorIndicator
                x: 0
                border.width: 2
                border.color: "light gray"
                opacity: 1
                color: "#00000000"
                anchors.verticalCenter: selectorWheel.verticalCenter
                height:selectorWheel.height/5 - 10
                anchors.verticalCenterOffset: -5
                width: selectorWheel.width
            }

            //Consistent settings among all tumbler columns
            Component{
                id: tumblerDelegate
                Label{
                    text: modelData
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: tumblerSettings.tumblerFontSize
                    font.family: "Roboto"
                    color: tumblerSettings.tumblerColor
                }
            }

            //Contain each tumbler column
            Row {
                id: row

                Tumbler {
                    id: monthTumbler
                    height: tumblerSettings.tumblerHeight
                    width: tumblerSettings.tumblerWidth + 80
                    font.pixelSize: tumblerSettings.tumblerFontSize
                    model: ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
                    //currentIndex: parseInt(saveMonth, 10) //get current month

                    delegate: tumblerDelegate

                    onCurrentIndexChanged: {
                        tumblerSettings.saveMonth = monthTumbler.model[monthTumbler.currentIndex]
                        //console.log(tumblerSettings.saveMonth)
                        updateMonth(tumblerSettings.saveMonth)
                    }
                }

                Tumbler {
                    id: dayTumbler
                    height: tumblerSettings.tumblerHeight
                    width: tumblerSettings.tumblerWidth
                    model: Scripts.getDays() //get list of days [1,31]
                    //currentIndex: parseInt(saveDay, 10) -1 //get current day
                    delegate: tumblerDelegate

                    onCurrentIndexChanged: {
                        tumblerSettings.saveDay = dayTumbler.model[dayTumbler.currentIndex]
                        //console.log(tumblerSettings.saveDay)
                        updateDay(tumblerSettings.saveDay)
                    }
                }

                Tumbler {
                    id: hourTumbler
                    height: tumblerSettings.tumblerHeight
                    width: tumblerSettings.tumblerWidth
                    font.pixelSize: tumblerSettings.tumblerFontSize
                    model: Scripts.padDigits(24) //get list of hours with padded digits [00,23]
                    //currentIndex: parseInt(saveHour, 10) //get current hour
                    delegate: tumblerDelegate

                    onCurrentIndexChanged: {
                        tumblerSettings.saveHour = hourTumbler.model[hourTumbler.currentIndex]
                        //console.log(tumblerSettings.saveHour)
                        updateHour(tumblerSettings.saveHour)
                    }
                }

                Label {
                    text: ":"
                    width: 25
                    anchors.verticalCenterOffset: -2
                    font.pixelSize: tumblerSettings.tumblerFontSize
                    anchors.verticalCenter: parent.verticalCenter
                    color: tumblerSettings.tumblerColor
                }

                Tumbler{
                    id: minuteTumbler
                    height: tumblerSettings.tumblerHeight
                    width: tumblerSettings.tumblerWidth
                    font.pixelSize: tumblerSettings.tumblerFontSize
                    //model: Scripts.padDigits(60) //get numbers [0,59]
                    model: ["00","15","30","45"]
                    //currentIndex: parseInt(saveMin, 10) //get current minute
                    delegate: tumblerDelegate

                    onCurrentIndexChanged: {
                        tumblerSettings.saveMin = minuteTumbler.model[minuteTumbler.currentIndex]
                        //console.log(tumblerSettings.saveMin)
                        updateMinute(tumblerSettings.saveMin)
                    }
                }
            } //End Row
        } //End Rectangle
    } //End Rectangle
}


