#include "task.h"

Task::Task(int id, std::string title, bool completed) 
    : id(id), title(title), completed(completed) {}

void Task::markCompleted() {
    completed = true;
}

std::string Task::toString() const {
    return "[" + std::to_string(id) + "] " + title + " - " + (completed ? "Done ✅" : "Pending ❌");
}

int Task::getId() const { return id; }
bool Task::isCompleted() const { return completed; }
