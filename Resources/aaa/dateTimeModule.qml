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
    property var saveTimeZone: ""

    signal updateMonth(string text)
    signal updateDay(string text)
    signal updateHour(string text)
    signal updateMinute(string text)
    signal updateTimezone(string text)

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
                    font.family: "Serif"
                    color: tumblerSettings.tumblerColor
                }
            }

            //Contain each tumbler column
            Row {
                id: row

                Tumbler {
                    id: monthTumbler
                    height: tumblerSettings.tumblerHeight
                    width: tumblerSettings.tumblerWidth + 60
                    font.pixelSize: tumblerSettings.tumblerFontSize
                    model: ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
                    currentIndex: Scripts.getMonth() //get current month
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
                    currentIndex: Scripts.getDay()-1 //get current day
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
                    currentIndex: Scripts.getHour() //get current hour
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
                    currentIndex: Scripts.getMinute() //get current minute
                    delegate: tumblerDelegate

                    onCurrentIndexChanged: {
                        tumblerSettings.saveMin = minuteTumbler.model[minuteTumbler.currentIndex]
                        //console.log(tumblerSettings.saveMin)
                        updateMinute(tumblerSettings.saveMin)
                    }
                }

                Tumbler {
                    id: timezoneTumbler
                    height: tumblerSettings.tumblerHeight
                    width: tumblerSettings.tumblerWidth +40
                    font.pixelSize: tumblerSettings.tumblerFontSize
                    //model: ["PDT", "MDT", "CDT", "EDT", "GMT"]
                    model: ["AST","EST","CST","MST","PST","AKST","HST","UTC-11","UTC+10"]
                    visibleItemCount: 4 //show this many items at once
                    delegate: tumblerDelegate

                    onCurrentIndexChanged: {
                        tumblerSettings.saveTimeZone = timezoneTumbler.model[timezoneTumbler.currentIndex]
                        //console.log(tumblerSettings.saveTimeZone)
                        updateTimezone(tumblerSettings.saveTimeZone)
                    }
                }
            } //End Row
        } //End Rectangle
    } //End Rectangle
}


