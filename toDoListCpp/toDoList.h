#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "task.h"
#include <stdexcept>
#include <stdlib.h>

class ToDoList {
public:
    ToDoList() = default;
    ToDoList(const std::vector<Task>& t);
    void addTask(const Task& t);
    void delateTask(int number);
    void updateTask(int number, const std::string& desc, bool comp, Date d);
    void updateTask(int number, const std::string& desc);
    void updateTask(int number, bool comp);
    void updateTask(int number, Date d);
    void viewTasks();
    int getCountOfComp();
    int getCountOfNotComp();
private:
    std::vector<Task> tasks;
};

#endif  //TODOLIST_H