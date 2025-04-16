#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include <fstream>

struct s_client {
    std::string account_number;
    std::string pin_code;
    std::string name;
    std::string phone;
    double account_balance;
    bool mark_for_delete = false;
};

extern const std::string CLIENTS_FILE_NAME;
extern s_client current_client;

s_client convert_line_to_record(const std::string& line, const std::string& separator = "#//#");
std::string convert_record_to_line(const s_client& client, const std::string& separator = "#//#");

std::vector<s_client> load_clients_data_from_file(const std::string& file_name);
bool find_client_by_account_number_and_pin_code(const std::string& account_number, const std::string& pin_code, s_client& client_ref);

void save_clients_data_to_file(const std::string& file_name, std::vector<s_client>& v_clients);
bool deposit_balance_to_client_by_account_number(const std::string& account_number, double amount, std::vector<s_client>& v_clients);

bool load_client_info(const std::string& account_number, const std::string& pin_code);

#endif