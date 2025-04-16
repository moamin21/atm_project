#ifndef UI_H
#define UI_H

#include "C:\C++ Files\atm_project\include\atm_operations.h"

void show_main_menu();
en_main_menu_options read_main_menu_option();

void show_quick_withdraw_screen();
void show_normal_withdraw_screen();

void show_deposit_screen();
void show_check_balance_screen();

void show_login_screen(bool login_failed);

#endif