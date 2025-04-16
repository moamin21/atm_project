#include "C:\C++ Files\atm_project\include\client.h"
#include "C:\C++ Files\atm_project\include\utils.h"
#include <iostream>

const std::string CLIENTS_FILE_NAME = "C:\\C++ Files\\atm_project\\data\\Clients.txt";
s_client current_client;

s_client convert_line_to_record(const std::string& line, const std::string& separator) {
    s_client client;
    std::vector<std::string> v_client_data = split_string(line, separator);

    if (v_client_data.size() >= 5) {
        client.account_number = v_client_data[0];
        client.pin_code = v_client_data[1];
        client.name = v_client_data[2];
        client.phone = v_client_data[3];
        try {
            client.account_balance = std::stod(v_client_data[4]);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Error converting balance to double for line: " << line << std::endl;
            client.account_balance = 0.0;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Balance value out of range for line: " << line << std::endl;
            client.account_balance = 0.0;
        }
    }
    else {
        std::cerr << "Error: Not enough data fields in line: " << line << std::endl;
    }

    return client;
}

std::string convert_record_to_line(const s_client& client, const std::string& separator) {
    std::string st_client_record = "";
    st_client_record += client.account_number + separator;
    st_client_record += client.pin_code + separator;
    st_client_record += client.name + separator;
    st_client_record += client.phone + separator;
    st_client_record += std::to_string(client.account_balance);
    return st_client_record;
}

std::vector<s_client> load_clients_data_from_file(const std::string& file_name) {
    std::vector<s_client> v_clients;
    std::fstream my_file;
    my_file.open(file_name, std::ios::in);

    if (my_file.is_open()) {
        std::string line;
        while (getline(my_file, line)) {
            if (!line.empty()) {
                v_clients.push_back(convert_line_to_record(line));
            }
        }
        my_file.close();
    }
    else {
        std::cerr << "Error opening file for reading: " << file_name << std::endl;
    }
    return v_clients;
}

bool find_client_by_account_number_and_pin_code(const std::string& account_number, const std::string& pin_code, s_client& client_ref) {
    std::vector<s_client> v_clients = load_clients_data_from_file(CLIENTS_FILE_NAME);
    for (const s_client& c : v_clients) {
        if (c.account_number == account_number && c.pin_code == pin_code) {
            client_ref = c;
            return true;
        }
    }
    return false;
}

void save_clients_data_to_file(const std::string& file_name, std::vector<s_client>& v_clients) {
    std::fstream my_file;
    my_file.open(file_name, std::ios::out);

    if (my_file.is_open()) {
        std::string data_line;
        for (const s_client& c : v_clients) {
            if (!c.mark_for_delete) {
                data_line = convert_record_to_line(c);
                my_file << data_line << std::endl;
            }
        }
        my_file.close();
    }
    else {
        std::cerr << "Error opening file for writing: " << file_name << std::endl;
    }
}

bool deposit_balance_to_client_by_account_number(const std::string& account_number, double amount, std::vector<s_client>& v_clients) {

    bool client_found = false;
    for (s_client& c : v_clients) {
        if (c.account_number == account_number) {
            c.account_balance += amount;
            client_found = true;
            break;
        }
    }

    if (client_found) {
        save_clients_data_to_file(CLIENTS_FILE_NAME, v_clients);
        return true;
    }


    return false;
}

bool load_client_info(const std::string& account_number, const std::string& pin_code) {
    if (find_client_by_account_number_and_pin_code(account_number, pin_code, current_client)) {
        return true;
    }
    else {
        return false;
    }
}