#include "task_manager.h"
#include <algorithm>  
#include <sstream>    

TaskManager::TaskManager() : nextId(1) {}

void TaskManager::addTask(const std::string& title) {
    tasks.emplace_back(nextId++, title);
}

void TaskManager::markTaskComplete(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            return;
        }
    }
}

void TaskManager::removeCompletedTasks() {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [](const Task& task) { return task.isCompleted(); }), tasks.end());
}

void TaskManager::displayTasks() const {
    for (const auto& task : tasks) {
        std::cout << task.toString() << std::endl;
    }
}

void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.getId() << "," << task.toString() << "," << task.isCompleted() << "\n";
    }
    file.close();
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    tasks.clear();
    while (getline(file, line)) {
        std::stringstream ss(line); 
        std::string title;
        int id, completedInt;
        getline(ss, title, ','); 
        ss >> id >> completedInt; 
        bool completed = (completedInt == 1); 
        tasks.emplace_back(id, title, completed);
        nextId = id + 1;
    }
    file.close();
}
