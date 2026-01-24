#ifndef TASKS_HPP
#define TASKS_HPP
#include <string>
#include <vector>

enum Priorite{
    Low,
    Medium,
    High,
    Done
};
const std::string priorite_strings[]={
    "Low",
    "Medium",
    "High",
    "Done"
};

//TODO
//remove default init (default init applied when failing to parse file instead)
typedef struct{
    int ID=-1;
    std::string description="";
    Priorite priorite=Low;
}Task;
extern std::vector<Task> tasks;

void task_add(std::string desctiption,Priorite);//adding categories later
void print_task(const Task &task);
void task_shows();
bool task_done(int id);
bool task_remove(int id);
Task* task_get(int id);
#endif
