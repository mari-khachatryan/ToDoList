#include "display.h"
#include "toDoList.h"

void Display::display() {
    int choice;
    do {
        std::cout << "===== TO-DO LIST PROGRAM =====" << std::endl;
        std::cout << "1. Add task" << std::endl;
        std::cout << "2. Complete task" << std::endl;
        std::cout << "3. Display tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;
        ToDoList toDo;

        switch(choice) {
            case 1: {
                std::cin.ignore();
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                Date date(15, 06, 2023);
                Task t(description, false, date);
                toDo.addTask(t);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                toDo.updateTask(index, "task name new");
                break;
            }
            case 3: {
                toDo.viewTasks();
                break;
            }
            case 4: {
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;

        }
        std::cout << std::endl;
    } while (choice != 4);
        
}