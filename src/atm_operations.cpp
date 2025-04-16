#include "C:\C++ Files\atm_project\include\atm_operations.h"
#include "C:\C++ Files\atm_project\include\client.h"
#include "C:\C++ Files\atm_project\include\ui.h"
#include "C:\C++ Files\atm_project\include\utils.h"
#include <iostream>
#include <vector>
#include <limits>

short read_quick_withdraw_option() {
    short choice = 0;
    while (true) {
        std::cout << "\nChoose what to do from [1] to [9] ? ";
        std::cin >> choice;


        if (std::cin.fail() || choice < 1 || choice > 9) {
            std::cout << "Invalid input. Please enter a number between 1 and 9." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

int get_quick_withdraw_amount(short quick_withdraw_option) {
    switch (quick_withdraw_option) {
    case 1: return 20;
    case 2: return 50;
    case 3: return 100;
    case 4: return 200;
    case 5: return 400;
    case 6: return 600;
    case 7: return 800;
    case 8: return 1000;
    default: return 0;
    }
}

void perform_quick_withdraw_option(short quick_withdraw_option) {
    if (quick_withdraw_option == 9) {
        return;
    }

    int withdraw_amount = get_quick_withdraw_amount(quick_withdraw_option);

    if (withdraw_amount > current_client.account_balance) {
        std::cout << "\nThe amount exceeds your balance, make another choice.\n";
        pause_screen();
        return;
    }

    char answer = 'n';
    std::cout << "\nAre you sure you want to perform this transaction? (y/n): ";
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    if (answer == 'y' || answer == 'Y') {
        std::vector<s_client> v_clients = load_clients_data_from_file(CLIENTS_FILE_NAME);
        if (deposit_balance_to_client_by_account_number(current_client.account_number, static_cast<double>(withdraw_amount) * -1.0, v_clients)) {
            current_client.account_balance -= withdraw_amount;
            std::cout << "\nTransaction successful. New balance is: " << current_client.account_balance << std::endl;


        }
        else {
            std::cout << "\nError processing transaction. Client data might be inconsistent." << std::endl;
        }
    }
    else {
        std::cout << "\nTransaction cancelled." << std::endl;
    }
    pause_screen();


}

double read_deposit_amount() {
    double amount = 0.0;
    while (true) {
        std::cout << "\nEnter a positive Deposit Amount? ";
        std::cin >> amount;


        if (std::cin.fail() || amount <= 0) {
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return amount;
        }
    }
}

void perform_deposit_option() {
    double deposit_amount = read_deposit_amount();

    char answer = 'n';
    std::cout << "\nAre you sure you want to perform this transaction? (y/n): ";
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (answer == 'y' || answer == 'Y') {
        std::vector<s_client> v_clients = load_clients_data_from_file(CLIENTS_FILE_NAME);
        if (deposit_balance_to_client_by_account_number(current_client.account_number, deposit_amount, v_clients)) {
            current_client.account_balance += deposit_amount;
            std::cout << "\nDeposit successful. New balance is: " << current_client.account_balance << std::endl;
        }
        else {
            std::cout << "\nError processing deposit. Client data might be inconsistent." << std::endl;
        }
    }
    else {
        std::cout << "\nDeposit cancelled." << std::endl;
    }
    pause_screen();
}

int read_withdraw_amount() {
    int amount = 0;
    while (true) {
        std::cout << "\nEnter an amount multiple of 5's? ";
        std::cin >> amount;


        if (std::cin.fail() || amount <= 0 || amount % 5 != 0) {
            std::cout << "Invalid input. Please enter a positive multiple of 5." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return amount;
        }
    }
}

void perform_normal_withdraw_option() {
    int withdraw_amount = read_withdraw_amount();

    if (withdraw_amount > current_client.account_balance) {
        std::cout << "\nThe amount exceeds your balance.\n";
        pause_screen();
        return;
    }

    char answer = 'n';
    std::cout << "\nAre you sure you want to perform this transaction? (y/n): ";
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    if (answer == 'y' || answer == 'Y') {
        std::vector<s_client> v_clients = load_clients_data_from_file(CLIENTS_FILE_NAME);
        if (deposit_balance_to_client_by_account_number(current_client.account_number, static_cast<double>(withdraw_amount) * -1.0, v_clients)) {
            current_client.account_balance -= withdraw_amount;
            std::cout << "\nWithdrawal successful. New balance is: " << current_client.account_balance << std::endl;

        }
        else {
            std::cout << "\nError processing withdrawal. Client data might be inconsistent." << std::endl;
        }
    }
    else {
        std::cout << "\nWithdrawal cancelled." << std::endl;
    }

    pause_screen();

}

void perform_main_menu_option(en_main_menu_options main_menu_option) {
    switch (main_menu_option) {
    case en_main_menu_options::QUICK_WITHDRAW:
        show_quick_withdraw_screen();
        break;
    case en_main_menu_options::NORMAL_WITHDRAW:
        show_normal_withdraw_screen();
        break;
    case en_main_menu_options::DEPOSIT:
        show_deposit_screen();
        break;
    case en_main_menu_options::CHECK_BALANCE:
        show_check_balance_screen();
        break;
    case en_main_menu_options::EXIT:
        break;
    default:
        std::cout << "Invalid option selected." << std::endl;
        pause_screen();
        break;
    }

}