.pragma library

//Function to get a list of years starting from 1900
function getYears(){
    var currYear = new Date;
    currYear = currYear.getFullYear();
    var listYears = [];
    for (var i = 1900; i <= currYear; i++){
        listYears.push(i);
    }

    return listYears
}
//Get current month
function getMonth(){
    var newDate = new Date;
    var currMonth = newDate.getMonth();

    return currMonth;
}
//Get list of days in a month [1,31]
function getDays(){
    var listDays = [];
    for( var i = 1; i < 32; i++){
        listDays.push(i)
    }
    return listDays;

}
//Get current day
function getDay(){
    var newDate = new Date;
    var currDay = newDate.getDate();

    return currDay;
}
//Get current year
function getYear(){
    var newDate = new Date;
    var currYear = newDate.getYear();

    return currYear;
}
//Get current hour
function getHour(){
    var newDate = new Date;
    var currHour = newDate.getHours();

    return currHour;
}
//Pad all single digits with leading zero
function padDigits(x){
    var minuteList = [];
    for (var i = 0; i < x; i++){
        if (i < 10){
            minuteList.push("0"+i)
        }
        else{
            minuteList.push(i)
        }
    }
    return minuteList
}
//Get current month
function getMinute(){
    var newDate = new Date;
    var currMinute = newDate.getMinutes();

    return currMinute;
}
