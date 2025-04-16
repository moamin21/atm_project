# Simple C++ ATM Project

## Description

This project implements a basic command-line ATM (Automated Teller Machine) interface in C++. It allows users to log in using an account number and PIN, and then perform standard banking operations like checking balance, depositing funds, and withdrawing cash. Client data is stored in a plain text file. [cite: 2]

## Features

* **User Authentication:** Clients log in using their account number and PIN.
* **Check Balance:** Displays the current account balance.
* **Deposit:** Allows users to deposit funds into their account.
* **Quick Withdraw:** Provides predefined withdrawal amount options (e.g., 20, 50, 100).
* **Normal Withdraw:** Allows users to withdraw specific amounts (multiples of 5).
* **Data Persistence:** Client information and balances are loaded from and saved to `Clients.txt`. [cite: 2]
* **Basic Input Validation:** Includes checks for valid menu choices and numeric inputs.

## File Structure

```
atm_project/
│
├── data/
│   └── Clients.txt         # Stores client account data [cite: 2]
│
├── include/
│   ├── atm_operations.h    # Header for ATM transaction functions
│   ├── client.h            # Header for client data structure and functions
│   ├── ui.h                # Header for user interface functions
│   └── utils.h             # Header for utility functions
│
├── src/
│   ├── atm_operations.cpp  # Implementation of ATM transaction logic
│   ├── client.cpp          # Implementation of client data handling
│   ├── main.cpp            # Main application entry point and logic flow
│   ├── ui.cpp              # Implementation of user interface screens
│   └── utils.cpp           # Implementation of utility functions
│
└── x64/
    └── Debug/
        ├── atm_project.exe   # Compiled executable (example location)
        └── atm_project.log   # Build log (example location) [cite: 1]
```

## Getting Started

### Prerequisites

* A C++ compiler that supports C++11 or later (like g++ or the Visual Studio C++ compiler).
* Basic knowledge of compiling and running C++ programs.

### Data File Setup

1.  Ensure the `data` directory exists in the same parent directory as your source (`src`) and include (`include`) folders.
2.  Create a file named `Clients.txt` inside the `data` directory. [cite: 2]
3.  Populate `Clients.txt` with client data, using the format:
    `AccountNumber#//#PinCode#//#ClientName#//#PhoneNumber#//#Balance`
    *Example:* `A557#//#1234#//#admin#//#01114567#//#5000.00` [cite: 2]

**Important:** The code currently uses a hardcoded *absolute path* `C:\\C++ Files\\atm_project\\data\\Clients.txt` to access the data file. You **must** either:
    * Place the `data` folder exactly at `C:\C++ Files\atm_project\data\` on your system.
    * **OR (Recommended)** Modify the `CLIENTS_FILE_NAME` constant in `src/client.cpp` to use a relative path (e.g., `"../data/Clients.txt"`) or a path appropriate for your system before compiling.

### Building

You can compile the project using a C++ compiler. For example, using g++:

```bash
# Navigate to the src directory
cd path/to/atm_project/src

# Compile the source files, linking them together
g++ main.cpp atm_operations.cpp client.cpp ui.cpp utils.cpp -I../include -o ../atm_app -std=c++11

# (Adjust include path -I../include if your structure differs)
```

Alternatively, if you are using an IDE like Visual Studio, open the project/solution file (if available) or create a new project and add the `.cpp` and `.h` files, then build it. The provided `x64/Debug` folder suggests it might have been built with Visual Studio. [cite: 1]

### Running

1.  Compile the project as described above.
2.  Run the generated executable (e.g., `atm_app` or `atm_project.exe`).

```bash
# If compiled with g++ example above, from the src directory:
../atm_app

# Or navigate to the executable's location and run it
./atm_app # on Linux/macOS
.\atm_app.exe # on Windows
```

3.  Follow the on-screen prompts to log in and use the ATM features.

## Notes

* The project uses basic console input/output for the user interface.
* Error handling is basic; improvements could include more robust input validation and file I/O error checking.
* PIN codes are stored in plain text in `Clients.txt`, which is insecure for a real-world application. [cite: 2]
* The dependency on absolute file paths should be refactored for better portability.
* The use of `system("cls")` and `system("pause")` might not be portable across all operating systems.
