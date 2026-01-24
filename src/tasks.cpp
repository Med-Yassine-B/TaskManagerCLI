#include "tasks.hpp"
#include "utils.hpp"
#include <string>
#include <vector>
#include <iostream>

std::vector<Task> tasks;

void task_add(std::string desctiption,Priorite){//adding categories later
   int task_id=0;
   if(tasks.size()!=0){
        task_id=tasks[tasks.size()-1].ID+1;//last ID +1
   }
    Task task{
        task_id,
        desctiption
    };
    tasks.push_back(task);
}
void print_task(const Task &task){
    switch (task.priorite) {
        case Done:
            std::cout<<YELLOW<<"["<<task.ID<<"] "<<RESET<<task.description<<RED<<" ["+priorite_strings[task.priorite]+"]"<<RESET<<std::endl;
            break;
        default:
            std::cout<<YELLOW<<"["<<task.ID<<"] "<<RESET<<task.description<<BLUE<<" ["+priorite_strings[task.priorite]+"]"<<RESET<<std::endl;
            break;
    
    }
}

void task_shows(){
    if(tasks.size()==0){
        logg("Empty...");
        return;
    }
    for(auto task:tasks){
        if(task.ID==-1) continue;
        print_task(task);
    }
}

bool task_done(int id){
    Task* task=task_get(id);
    if(task!=nullptr){
        task->priorite=Done;
    }
    else{
        log_error("Couldnt find task within the ID("+std::to_string(id)+")");
    }
    return task!=nullptr;
}
Task* task_get(int id){
    int start=0,end=tasks.size()-1;
    int task_index=-1;
    int middle;
    while(start<=end){

        middle=start+(end-start)/2;
        if(tasks[middle].ID==id){
            task_index=middle;
            break;
        }

        if(id<tasks[middle].ID){
            end=middle-1;
        }else{
            start=middle+1;
        }
    }
    if(task_index!=-1)
        return &tasks[task_index];
    else    return nullptr;

}
int task_get_index(int id){
    int start=0,end=tasks.size()-1;
    int task_index=-1;
    int middle;
    while(start<=end){

        middle=start+(end-start)/2;
        if(tasks[middle].ID==id){
            task_index=middle;
            break;
        }

        if(id<tasks[middle].ID){
            end=middle-1;
        }else{
            start=middle+1;
        }
    }
    return task_index;

}

bool task_remove(int id){
    int task_index=task_get_index(id);
    if(task_index!=-1 && task_index<tasks.size()){
        tasks.erase(tasks.begin()+task_index);
        return true;
    }else{
        log_error("Couldn't find a task wi the specified ID("+std::to_string(id)+")");
        return false;
    }
}
