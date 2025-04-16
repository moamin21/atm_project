#include "C:\C++ Files\atm_project\include\client.h"
#include "C:\C++ Files\atm_project\include\ui.h"
#include "C:\C++ Files\atm_project\include\atm_operations.h"
#include "C:\C++ Files\atm_project\include\utils.h"
#include <iostream>
#include <string>
#include <limits>

void perform_login() {
    bool login_failed = false;
    std::string account_number, pin_code;

    do {
        show_login_screen(login_failed);

        std::cout << "Enter Account Number? ";
        std::cin >> account_number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        std::cout << "Enter Pin? ";
        std::cin >> pin_code;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        if (!load_client_info(account_number, pin_code)) {
            login_failed = true;
            std::cout << "Login attempt failed. Press Enter to try again..." << std::endl;
            std::cin.get();

        }
        else {
            login_failed = false;
        }


    } while (login_failed);
}

int main() {
    while (true) {
        perform_login();

        en_main_menu_options choice;
        do {
            show_main_menu();
            choice = read_main_menu_option();

            if (choice != en_main_menu_options::EXIT) {
                perform_main_menu_option(choice);
            }


        } while (choice != en_main_menu_options::EXIT);


        std::cout << "\nLogging out... Thank you for using the ATM!" << std::endl;
        pause_screen();

    }


    return 0;
}