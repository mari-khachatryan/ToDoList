#include "toDoList.h"
#include <iostream>


ToDoList::ToDoList(const std::vector<Task>& t) : tasks{t} {}

void ToDoList::addTask(const Task& t) {
    tasks.push_back(t);
}

void ToDoList::delateTask(int number) {
    if(number < 0 || number > tasks.size()) {
        throw std::out_of_range("number is out of range");
    }
    tasks.erase(tasks.begin() + number);
}

void ToDoList::updateTask(int number, const std::string& desc, bool comp, Date d) {
    if(number < 0 || number > tasks.size()) {
        throw std::out_of_range("number is out of range");
    }
    Task& t = tasks[number];
    t.setCompleted(comp);
    t.setDescription(desc);
    t.setDate(d);
}

void ToDoList::updateTaskDesc(int number, const std::string& desc) {
    if(number < 0 || number > tasks.size()) {
        throw std::out_of_range("number is out of range");
    }
    Task& t = tasks[number];
    t.setDescription(desc);
   }

void ToDoList::updateTaskComp(int number, bool comp) {
    if(number < 0 || number > tasks.size()) {
        throw std::out_of_range("number is out of range");
    }
    Task& t = tasks[number];
    t.setCompleted(comp);
}

void ToDoList::updateTaskDate(int number, Date d) {
    if(number < 0 || number > tasks.size()) {
        throw std::out_of_range("number is out of range");
    }
    Task& t = tasks[number];
    t.setDate(d);
}

void ToDoList::viewTasks() {
    Date date;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date.setYear(1900 + ltm->tm_year);
    date.setMonth(1 + ltm->tm_mon);
    date.setDay(ltm->tm_mday);
    std::string res;
    std::cout << date.getDay()<< "-" << date.getMonth()<<"-"<<date.getYear();
    for(int i{0}; i < tasks.size(); ++i) {
        if(tasks[i].getCompleted()) {
            res = "Completed";
            std::cout << i + 1 << ". " << tasks[i].getDescription() << " | " << res 
            << " | " << tasks[i].getDate().getDateStr()  << std::endl;
        } else {
            res = "not completed";
            if(tasks[i].getDate().getDay() - date.getDay() == 1) {
                std::cout << i + 1 << ". " << tasks[i].getDescription() << " | " << res 
                << " | "  << tasks[i].getDate().getDateStr() << " | ";
                std::cout << "deadline ends in 1 day!!" << std::endl;
            }else if(tasks[i].getDate().getDay() - date.getDay() < 0) {
                std::cout << i + 1 << ". " << tasks[i].getDescription() << " | " << res 
                << " | " << tasks[i].getDate().getDateStr() << " | ";
                std::cout << "Deadlines are missed!!" << std::endl;
            } else {
                std::cout << i + 1 << ". " << tasks[i].getDescription() << " | " << res
                << " | " << tasks[i].getDate().getDateStr() << std::endl;
            }
        } 
    }
}

int ToDoList::getCountOfComp() {
    int count = 0;
    for(int i{0}; i < tasks.size(); ++i) {
        if(tasks[i].getCompleted()) {
            ++count;
        }
    }
    return count;
}

int ToDoList::getCountOfNotComp() {
    return tasks.size() - getCountOfComp();
}
