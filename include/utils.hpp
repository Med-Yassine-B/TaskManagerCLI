#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void log_error(std::string error);
bool start_with(const std::string& str,const std::string& prefix);
std::string to_lower(std::string data) ;
void logg(std::string msg);
std::string _info_block(std::string title,std::string info);
//triggered when typung "info"
//>>info
void print_info();
void clear_console();
void print_banner();
void show_help_message();
#endif
