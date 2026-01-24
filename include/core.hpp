#ifndef CORE_HPP
#define CORE_HPP
#include <sstream>
#include <string>

bool next_command(std::string command);//returns false when should close
                                       
void parse_todo_command(std::stringstream &ss);
#endif
