#ifndef TASK_H
#define TASK_H

#include <iostream>

class Task{
    private:
        int id;
        std::string title;
        bool completed;

    public:
        Task(int id, std::string title, bool completed = false);

        void markCompleted();
        std::string toString() const;

        int getId() const;
        bool isCompleted() const;
};

#endif