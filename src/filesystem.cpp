#include "filesystem.hpp"
#include "utils.hpp"
#include "tasks.hpp"
#include <fstream>
#include <string>
#include <tasks.hpp>
#include <filesystem>

#define SEPRATOR '\x1F'

bool _saved;
bool _file_exist=false;

bool file_exist(){
    //to avoid checking the disp multiple times
    if(_file_exist)  return true;
    else{
        _file_exist=std::filesystem::exists(".tasks.txt");
    }
    return _file_exist;
}
void load(){
    std::ifstream fs(".tasks.txt");

    if(!fs.is_open()){
        log_error("Failed opening .tasks.tst");
        return;
    }
    //saved in file as
    //ID [\x1F] priority [\x1F] category [\x1F] task [\x1F]
    std::string line;
    while(std::getline(fs,line)){
        load_line(line);
    }
    _saved=true;
}

//TODO use two pointer method instead [Done]
//pass original string by reference
void load_line(std::string &line){
    int length=line.length();
    int i=0;
    int last_seprator=0;
    int seprators=0;

    Task task;
    while(i<length && seprators<4){
        if(line[i]==SEPRATOR){
            seprators++;
            std::string part=line.substr(last_seprator,i - last_seprator);
            last_seprator=i+1;
            if(part=="")  return;
            
            //saved in file as
            //ID [\x1F] priority [\x1F] category [\x1F] task [\x1F]
            if(seprators==1){//parsing first part (ID)
                try{
                    int id=std::stoi(part);
                    task.ID=id;
                }catch(const std::exception& e){
                    log_error("Coundnt parse task:"+std::string(e.what()));
                    break;
                }
            }else if(seprators==2){//second part (priority)
                if(part=="Low") task.priorite=Low;
                else if (part=="Medium") task.priorite=Medium;
                else if (part=="High") task.priorite=High;
                else if (part=="Done") task.priorite=Done;
                else {
                    log_error("Unnknown priority found in part:"+std::to_string(seprators));
                    return;
                }
            }else if(seprators==3){//third part (category)
                //pass
            }else if(seprators==4){//fourth part (task)//TODO might remove the condition from here
                task.description=part;
            }
        }
            
        i++;
    }
    tasks.push_back(task);
}

//saved in file as
//ID [\x1F] priority [\x1F] category [\x1F] task [\x1F]
void pack_tasks(std::vector<Task> tasks,std::string& res){
    for(auto task:tasks){
        res+=std::to_string(task.ID)+SEPRATOR;
        res+=priorite_strings[task.priorite]+SEPRATOR;
        res+="category";res+=SEPRATOR;//no category yet
        res+=task.description+SEPRATOR;
        res+='\n';
    }
}

void save(){
    std::string res;
    //saved in file as
    //ID [\x1F] priority [\x1F] category [\x1F] task [\x1F]
    std::ofstream f(".tasks.txt",std::ios::out|std::ios::trunc);
    if(f.is_open()){
        pack_tasks(tasks,res);//put tasks in a string
        f<<res;
        f.close();
    }else{
        log_error("Couldn't open the file (.tasks.txt)");
    }

    _saved=true;
}

bool should_save(){
    return !_saved;
}
