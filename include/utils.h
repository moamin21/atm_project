#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <cstdlib> 

std::vector<std::string> split_string(const std::string& s1, const std::string& delim);
void clear_screen();
void pause_screen(); 

#endif