#include "C:\C++ Files\atm_project\include\utils.h"
#include <iostream>

std::vector<std::string> split_string(const std::string& s1_in, const std::string& delim) {
    std::vector<std::string> v_string;
    std::string s1 = s1_in;
    size_t pos = 0;
    std::string s_word;

    while ((pos = s1.find(delim)) != std::string::npos) {
        s_word = s1.substr(0, pos);
        if (!s_word.empty()) {
            v_string.push_back(s_word);
        }
        s1.erase(0, pos + delim.length());
    }

    if (!s1.empty()) {
        v_string.push_back(s1);
    }

    return v_string;
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_screen() {
#ifdef _WIN32
    system("pause>0");
#else
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
#endif
}