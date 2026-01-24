#include "utils.hpp"
#include "tasks.hpp"
#include <iostream>
#include <algorithm>
#include <string>


void log_error(std::string error){
    std::cout<<RED<<"[ERROR] "<<RESET<<error<<std::endl;
}
void logg(std::string msg){
    std::cout<<YELLOW<<"[INFO]"<<RESET<<msg<<std::endl;
}

bool start_with(const std::string& str,const std::string& prefix){
    return str.rfind(prefix,0)==0;
}

std::string to_lower(std::string data) {
    std::transform(data.begin(), data.end(), data.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return data;
}
std::string _info_block(std::string title,std::string info){//organize title and info for readabiliny in code
   return '\t'+(YELLOW+title+":"+RESET+info);
}
void print_info(){//helps debugging
    std::cout<<BLUE<<"[DEBUGGING INFOs]\n"<<RESET
        <<_info_block("[Tasks.length()]",std::to_string(tasks.size()))
        <<std::endl;
}
void clear_console(){
    std::cout<<"\ec"<<std::endl;
    print_banner();
}

void print_banner(){
    std::cout
<<"\033[36;40m"
"___________              __       \n"
"\\__    ___/____    _____|  | __  \n"
"  |    |  \\__  \\  /  ___/  |/ / \n"
"  |    |   / __ \\_\\___ \\|    < \n"
"  |____|  (____  /____  >__|_ \\  \n"
"               \\/     \\/     \\/\n"
"\033[33;40m"
"\t\t\t    _____                                             \n"
"\t\t\t   /     \\ _____    ____ _____     ____   ___________ \n"
"\t\t\t  /  \\ /  \\\\__  \\  /    \\\\__  \\   / ___\\_/ __ \\_  __ \\\n"
"\t\t\t /    Y    \\/ __ \\|   |  \\/ __ \\_/ /_/  >  ___/|  | \\/\n"
"\t\t\t \\____|__  (____  /___|  (____  /\\___  / \\___  >__|   \n"
"\t\t\t         \\/     \\/     \\/     \\//_____/      \\/       \n"
<<RESET;
}


void show_help_message(){
    std::cout
        <<"command structure:\n"
        "\t "
        "\n";
}
