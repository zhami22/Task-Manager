#include "task_manager.h"
#include <iostream>

int main() {
    TaskManager manager;
    manager.loadFromFile("tasks.txt");

    while (true) {
        std::cout << "\nTask Manager CLI\n";
        std::cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Remove Completed Tasks\n5. Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title;
            std::cout << "Enter task title: ";
            std::getline(std::cin, title);
            manager.addTask(title);
        } 
        else if (choice == 2) {
            manager.displayTasks();
        } 
        else if (choice == 3) {
            int id;
            std::cout << "Enter task ID to mark complete: ";
            std::cin >> id;
            manager.markTaskComplete(id);
        } 
        else if (choice == 4) {
            manager.removeCompletedTasks();
        } 
        else if (choice == 5) {
            manager.saveToFile("tasks.txt");
            break;
        }
    }

    return 0;
}
