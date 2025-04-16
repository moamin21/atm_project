#ifndef ATM_OPERATIONS_H
#define ATM_OPERATIONS_H

enum class en_main_menu_options {
    QUICK_WITHDRAW = 1,
    NORMAL_WITHDRAW = 2,
    DEPOSIT = 3,
    CHECK_BALANCE = 4,
    EXIT = 5
};

short read_quick_withdraw_option();
int get_quick_withdraw_amount(short quick_withdraw_option);

void perform_quick_withdraw_option(short quick_withdraw_option);
double read_deposit_amount();

void perform_deposit_option();
int read_withdraw_amount();

void perform_normal_withdraw_option();
void perform_main_menu_option(en_main_menu_options main_menu_option);

#endif