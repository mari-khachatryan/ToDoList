#include <iostream>
#include <vector>
#include "date.h"

class Task {
public:
    Task();
    Task(const std::string& d, bool c, Date data);
    std::string  getDescription();
    bool getCompleted();
    Date getDate();
    void  setDescription(const std::string& d);
    void setCompleted(bool b);
    void setDate(Date d);
private:
    std::string  description;
    bool completed;
    Date date;
};
