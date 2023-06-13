#include "date.h"
#include <string>

Date::Date(int d, int m, int y)
    :day{d}
    ,month{m}
    ,year{y}
{}
int Date::getDay() {return day;}
int Date::getMonth() {return month;}
int Date::getYear() {return year;}
void Date::setDay(int d) {day = d;}
void Date::setMonth(int m) {month = m;}
void Date::setYear(int y) {year = y;}
std::string Date::getDateStr() {
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}