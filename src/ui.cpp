#include "C:\C++ Files\atm_project\include\ui.h"
#include "C:\C++ Files\atm_project\include\client.h"
#include "C:\C++ Files\atm_project\include\atm_operations.h"
#include "C:\C++ Files\atm_project\include\utils.h"
#include <iostream>
#include <iomanip>
#include <limits>

void show_login_screen(bool login_failed) {
    clear_screen();
    std::cout << "\n---------------------------------\n";
    std::cout << "\tLogin Screen";
    std::cout << "\n---------------------------------\n";


    if (login_failed) {
        std::cout << "Invalid Account Number/Pin Code!\n";
    }

}

void show_quick_withdraw_screen() {
    clear_screen();
    std::cout << "===========================================\n";
    std::cout << "\t\tQuick Withdraw\n";
    std::cout << "===========================================\n";
    std::cout << "\t[1] 20\t\t[2] 50\n";
    std::cout << "\t[3] 100\t\t[4] 200\n";
    std::cout << "\t[5] 400\t\t[6] 600\n";
    std::cout << "\t[7] 800\t\t[8] 1000\n";
    std::cout << "\t[9] Exit to Main Menu\n";
    std::cout << "===========================================\n";
    std::cout << "Your Balance is " << std::fixed << std::setprecision(2) << current_client.account_balance << std::endl; // Format balance


    short choice = read_quick_withdraw_option();
    perform_quick_withdraw_option(choice);
}

void show_normal_withdraw_screen() {
    clear_screen();
    std::cout << "===========================================\n";
    std::cout << "\t\tNormal Withdraw Screen\n";
    std::cout << "===========================================\n";
    std::cout << "Your Balance is " << std::fixed << std::setprecision(2) << current_client.account_balance << std::endl;


    perform_normal_withdraw_option();

}

void show_deposit_screen() {
    clear_screen();
    std::cout << "===========================================\n";
    std::cout << "\t\tDeposit Screen\n";
    std::cout << "===========================================\n";
    std::cout << "Your Balance is " << std::fixed << std::setprecision(2) << current_client.account_balance << std::endl;


    perform_deposit_option();
}

void show_check_balance_screen() {
    clear_screen();
    std::cout << "===========================================\n";
    std::cout << "\t\tCheck Balance Screen\n";
    std::cout << "===========================================\n";
    std::cout << "Your Balance is " << std::fixed << std::setprecision(2) << current_client.account_balance << std::endl;
    std::cout << "===========================================\n";
    pause_screen();

}

void show_main_menu() {
    clear_screen();
    std::cout << "===========================================\n";
    std::cout << "\t\tATM Main Menu Screen\n";
    std::cout << "===========================================\n";
    std::cout << "\t[1] Quick Withdraw.\n";
    std::cout << "\t[2] Normal Withdraw.\n";
    std::cout << "\t[3] Deposit.\n";
    std::cout << "\t[4] Check Balance.\n";
    std::cout << "\t[5] Logout.\n";
    std::cout << "===========================================\n";
    std::cout << "Welcome, " << current_client.name << "!" << std::endl;
    std::cout << "Your Balance is " << std::fixed << std::setprecision(2) << current_client.account_balance << std::endl;

}

en_main_menu_options read_main_menu_option() {
    int choice = 0;
    while (true) {
        std::cout << "Choose what do you want to do? [1 to 5]? ";
        std::cin >> choice;


        if (std::cin.fail() || choice < 1 || choice > 5) {
            std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return static_cast<en_main_menu_options>(choice);
        }
    }
}