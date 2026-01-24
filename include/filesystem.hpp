#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP
#include <string>

extern bool _saved;
extern bool _file_exist;
void save();
void load();

bool file_exist();
void load_line(std::string &task);

bool should_save();

#endif 
