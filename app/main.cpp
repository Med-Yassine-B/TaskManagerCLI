#include "core.hpp"
#include "filesystem.hpp"
#include "input.hpp"
#include <utils.hpp>
#include <string>
#include <iostream>

int main(int argc,char** argv){

    bool running=true;
    clear_console();
    
    if(file_exist()){//if already there's tasks in the directory 
        logg("tasks file already exists");
        load();
    }


    std::string command;
    while(running){
        std::cout<<">>"<<std::flush;
        // std::getline(std::cin,command);
        command=input();
        running=next_command(command);
        if(should_save()){
            logg("Saving!");
            save();
        }
    }
    

}
