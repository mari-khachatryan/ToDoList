#ifndef DATA_H
#define DATA_H

#include <iostream>

class Date {
public:
    Date() = default;
    Date(int d, int m, int y);
    int getDay();
    int getMonth();
    int getYear();
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
    std::string getDateStr();
private:
    int day;
    int month;
    int year;
};

#endif //DATA_H