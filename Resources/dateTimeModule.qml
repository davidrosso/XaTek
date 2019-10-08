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
    property var saveYear: ""
    property var saveMonth: ""
    property var saveDay: ""
    property var saveHour: ""
    property var saveMin: ""
    property var saveTimeZone: ""

    signal updateYear(string text)
    signal updateMonth(string text)
    signal updateDay(string text)
    signal updateHour(string text)
    signal updateMinute(string text)
    signal updateTimezone(string text)

    function setYear(year){
        saveYear = year;
        yearTumbler.currentIndex = year;
        return year;
    }

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
        minuteTumbler.currentIndex = minute;
        return minute;
    }
    function setTimezone(timezone){
        saveTimeZone = timezone;
        timezoneTumbler.currentIndex = timezone;
        return timezone;
    }

    //Main Window
    Rectangle {
        id: dateTimeWindow
        y: 0
        visible: true
        width: selectorWheel.width
        height: selectorWheel.height //Match dimensions of tumbler Module
        color: "#00000000" //Transparent background
        anchors.horizontalCenter: parent.horizontalCenter
        //anchors.verticalCenter: parent.verticalCenter

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
                x: -25
                height:selectorWheel.height/5 - 5
                width: selectorWheel.width + 50
                border.width: 2
                border.color: "light gray"
                opacity: 1
                color: "#00000000"
                anchors.verticalCenter: selectorWheel.verticalCenter
                anchors.verticalCenterOffset: 42
            }

            Rectangle {
                id: leftSelectorHider
                x: -30
                width: 20
                height:selectorWheel.height/5
                anchors.verticalCenter: selectorWheel.verticalCenter
                anchors.verticalCenterOffset: 42
                color: "#00000000"

                z: 1
                //color: "black"

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

            Column{
                spacing: 20
                //Contain each tumbler column
                Row {
                    id: headersRow
                    x: 62
                    //spacing: 80

                    Label {
                        leftPadding: 5
                        text: "Month"
                        font.pixelSize: tumblerSettings.tumblerFontSize - 10
                        color: tumblerSettings.tumblerColor
                    }
                    Label {
                        leftPadding: 90
                        text: "Day"
                        font.pixelSize: tumblerSettings.tumblerFontSize - 10
                        color: tumblerSettings.tumblerColor
                    }
                    Label {
                        leftPadding: 68
                        text: "Hr"
                        font.pixelSize: tumblerSettings.tumblerFontSize - 10
                        color: tumblerSettings.tumblerColor
                    }
                    Label {
                        leftPadding: 75
                        text: "Min"
                        font.pixelSize: tumblerSettings.tumblerFontSize - 10
                        color: tumblerSettings.tumblerColor
                    }
                    Label {
                        leftPadding: 60
                        text: "Year"
                        font.pixelSize: tumblerSettings.tumblerFontSize - 10
                        color: tumblerSettings.tumblerColor
                    }
                }

                Row {
                    id: row

                    Tumbler {
                        id: monthTumbler
                        height: tumblerSettings.tumblerHeight
                        width: tumblerSettings.tumblerWidth + 100
                        font.pixelSize: tumblerSettings.tumblerFontSize
                        model: ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
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
                        delegate: tumblerDelegate

                        onCurrentIndexChanged: {
                            tumblerSettings.saveHour = hourTumbler.model[hourTumbler.currentIndex]
                            //console.log(tumblerSettings.saveHour)
                            updateHour(tumblerSettings.saveHour)
                        }
                    }

                    Label {
                        text: ":"
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
                        model: Scripts.padDigits(60) //get numbers [0,59]
                        delegate: tumblerDelegate

                        onCurrentIndexChanged: {
                            tumblerSettings.saveMin = minuteTumbler.model[minuteTumbler.currentIndex]
                            //console.log(tumblerSettings.saveMin)
                            updateMinute(tumblerSettings.saveMin)
                        }
                    }

                    Tumbler{
                        id: yearTumbler
                        height: tumblerSettings.tumblerHeight
                        width: tumblerSettings.tumblerWidth
                        font.pixelSize: tumblerSettings.tumblerFontSize
                        model: Scripts.padDigits(99) //get numbers [0,59]
                        delegate: tumblerDelegate
                    }

                } //End Row

                Label {
                    topPadding: 50
                    text: "Time Zone"
                    font.pixelSize: tumblerSettings.tumblerFontSize - 10
                    color: tumblerSettings.tumblerColor
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Tumbler {
                    id: timezoneTumbler
                    height: tumblerSettings.tumblerHeight - 50
                    width: tumblerSettings.tumblerWidth + 40
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: tumblerSettings.tumblerFontSize - 10
                    //model: ["PDT", "MDT", "CDT", "EDT", "GMT"]
                    model: ["AST","EST","CST","MST","PST","AKST","HST","UTC-11","UTC+10"]
                    visibleItemCount: 3 //show this many items at once
                    delegate: tumblerDelegate

                    onCurrentIndexChanged: {
                        tumblerSettings.saveTimeZone = timezoneTumbler.model[timezoneTumbler.currentIndex]
                        //console.log(tumblerSettings.saveTimeZone)
                        updateTimezone(tumblerSettings.saveTimeZone)
                    }
                }
            }
        } //End Rectangle
    } //End Rectangle
}


