#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <vector>
#include <fstream>

class TaskManager{
    private:
        std::vector<Task> tasks;
        int nextId;

    public:
        TaskManager();

        void addTask(const std::string& title);
        void markTaskComplete(int id);
        void removeCompletedTasks();
        void displayTasks() const;
        void saveToFile(const std::string& filename) const;
        void loadFromFile(const std::string& filename);
    };

#endif