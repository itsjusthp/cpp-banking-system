#include <iostream>
using namespace std;

// 1. DECLARATIONS (Arrays of size 3 for 3 users)
char names[3] = {"Marina", "Teddy", "Alex"};
int accountNumbers[3] = {1001, 1002, 1003};
int pins[3] = {1234, 2345, 3456};
double balances[3] = {5000.00, 3500.00, 2000.00};

// 2. DEPOSIT FUNCTION
void deposit(int userIndex) {
    double amount;
    cout << "Enter amount to deposit: R";
    cin >> amount;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    } else if (amount > 0) {
        balances[userIndex] = balances[userIndex] + amount;
        cout << "Deposit successful! New balance: R" << balances[userIndex] << "\n";
    } else {
        cout << "Error: Deposit amount must be greater than R0.\n";
    }
}

// 3. WITHDRAW FUNCTION
void withdraw(int userIndex) {
    double amount;
    cout << "Enter amount to withdraw: R";
    cin >> amount;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    } else if (amount <= 0) {
        cout << "Error: Withdrawal amount must be greater than R0.\n";
    } else if (amount > balances[userIndex]) {
        cout << "Error: Insufficient funds. Your balance is R" << balances[userIndex] << "\n";
    } else {
        balances[userIndex] = balances[userIndex] - amount;
        cout << "Withdrawal successful! Remaining balance: R" << balances[userIndex] << "\n";
    }
}

// 4. SEND CASH FUNCTION
void sendCash(int userIndex) {
    int recipientAccount;
    double amount;
    int recipientIndex = -1;

    cout << "Enter recipient account number: ";
    cin >> recipientAccount;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid account number format.\n";
        return;
    }

    // Search for the recipient account in the array of 3 users
    for (int i = 0; i < 3; i++) {
        if (accountNumbers[i] == recipientAccount) {
            recipientIndex = i;
            break;
        }
    }

    if (recipientIndex == -1) {
        cout << "Error: Recipient account does not exist.\n";
        return;
    }

    if (recipientIndex == userIndex) {
        cout << "Error: You cannot send cash to your own account.\n";
        return;
    }

    cout << "Enter amount to send to " << names[recipientIndex] << ": R";
    cin >> amount;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid amount entered.\n";
    } else if (amount <= 0) {
        cout << "Error: Transfer amount must be greater than R0.\n";
    } else if (amount > balances[userIndex]) {
        cout << "Error: Insufficient balance to complete transfer.\n";
    } else {
        balances[userIndex] = balances[userIndex] - amount;
        balances[recipientIndex] = balances[recipientIndex] + amount;
        cout << "Transfer of R" << amount << " to " << names[recipientIndex] << " successful!\n";
        cout << "Your new balance: R" << balances[userIndex] << "\n";
    }
}

// 5. CHECK BALANCE FUNCTION
void checkBalance(int userIndex) {
    cout << "\n--- ACCOUNT DETAILS ---\n";
    cout << "Account Holder : " << names[userIndex] << "\n";
    cout << "Account Number : " << accountNumbers[userIndex] << "\n";
    cout << "Current Balance: R" << balances[userIndex] << "\n";
}

// 6. MENU FUNCTION
void menu() {
    cout << "\n===== GCC BANK =====\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Send Cash\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

// 7. MAIN FUNCTION
int main() {
    int enteredAccount;
    int enteredPin;
    int loggedInUser = -1;
    int choice = 0;

    cout << "Welcome to Gauteng City College (GCC) Bank\n";

    // Login loop to verify user account number and PIN
    while (loggedInUser == -1) {
        cout << "\nEnter your Account Number: ";
        cin >> enteredAccount;
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Numbers only.\n";
            continue;
        }

        for (int i = 0; i < 3; i++) {
            if (accountNumbers[i] == enteredAccount && pins[i] == enteredPin) {
                loggedInUser = i;
                break;
            }
        }

        if (loggedInUser == -1) {
            cout << "Invalid account number or PIN. Please try again.\n";
        }
    }

    cout << "\nLogin successful! Welcome, " << names[loggedInUser] << ".\n";

    // Main banking menu loop
    do {
        menu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                deposit(loggedInUser);
                break;
            case 2:
                withdraw(loggedInUser);
                break;
            case 3:
                sendCash(loggedInUser);
                break;
            case 4:
                checkBalance(loggedInUser);
                break;
            case 5:
                cout << "Thank you for banking with GCC Bank. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}




