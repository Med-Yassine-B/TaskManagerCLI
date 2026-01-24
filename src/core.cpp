#include "core.hpp"
#include "tasks.hpp"
#include "utils.hpp"
#include "filesystem.hpp"
#include <sstream>
#include <string>

bool next_command(std::string command){
    if(command=="exit"){
        logg("Exiting...");
        return false;
    } 

    std::stringstream ss(command);
    std::string mode;
    ss>>mode;
    
    if(to_lower(mode)=="todo"){
        parse_todo_command(ss);
    }else if (to_lower(mode)=="info") {
        print_info();
    }else if(command=="clear"){
        clear_console();
    }else if(command=="help"){

    }else{
        log_error("{"+mode+"} isnt a valid mode");
    }
    return true;
}

void parse_todo_command(std::stringstream &ss){
    std::string task;
    std::string option;
    ss>>option;
    if(option=="add"){
        std::getline(ss>>std::ws,task);
        if(task.length()>0){
            task_add(task,Low);   
            _saved=false;//should save
        }else{
            log_error("Cant register an empty task");
        }
    }else if(option== "show"){
        task_shows();
    }else if(option=="done" || option=="remove"){
        int id;
        if(ss>>id){
            if(option=="done"){
                task_done(id);
                _saved=false;//should save
            }else{
                bool succes=task_remove(id);
                if(succes)
                    _saved=false;//should save
            }
        }else{
            log_error("Pleasr enter a valid task ID");
        }
    }else{
        log_error("{"+option+"} isnt a valid option in todo");
    }
}


