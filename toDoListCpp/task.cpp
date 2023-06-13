#include "task.h"


Task::Task() : description{" "}, completed{false}, date{Date()} {}

Task::Task(const std::string& d, bool c, Date data) 
    :description{d}
    ,completed{c}
    ,date{data}
{}

std::string  Task::getDescription() { return description; }
bool Task::getCompleted() { return completed; }
Date Task::getDate(){return date;}
void  Task::setDescription(const std::string& d) {description = d; }
void Task::setCompleted(bool b) { completed = b; }
void Task::setDate(Date d) {date = d;}