#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <ctime>

using namespace std;

struct Transaction {
    string description;
    double amount;
    string category;
    string date;
};

class BudgetTracker {
private:
    map<string, double> categories;
    vector<Transaction> transactions;

public:
    void addTransaction(const Transaction& transaction) {
        transactions.push_back(transaction);
        categories[transaction.category] += transaction.amount;
    }

    void loadTransactionsFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string description, category;
            double amount;
            char delimiter;

            if (!(iss >> description >> delimiter >> amount >> delimiter >> category)) {
                cerr << "Error reading line: " << line << endl;
                continue;
            }

            // Get current date and time
            time_t now = time(0);
            tm* localTime = localtime(&now);
            char date[11]; // Buffer for date in the format YYYY-MM-DD
            strftime(date, sizeof(date), "%Y-%m-%d", localTime);

            addTransaction({ description, amount, category, date });
        }

        file.close();
    }

    void printSummary() {
        cout << "------ Budget Summary ------" << endl;
        cout << "Category\t\tAmount" << endl;
        for (const auto& pair : categories) {
            cout << pair.first << "\t\t" << pair.second << endl;
        }
        cout << "----------------------------" << endl;
    }

    void printTransactions() {
        cout << "------ Transaction History ------" << endl;
        for (const auto& transaction : transactions) {
            cout << "Date: " << transaction.date << ", Description: " << transaction.description << ", Amount: " << transaction.amount << ", Category: " << transaction.category << endl;
        }
        cout << "--------------------------------" << endl;
    }
};

int main() {
    BudgetTracker budgetTracker;
    budgetTracker.loadTransactionsFromFile("budget_data.dat");

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1- Add transaction" << endl;
        cout << "2- Display transaction history" << endl;
        cout << "3- Print summary" << endl;
        cout << "4- Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Transaction transaction;
            cout << "Enter transaction description: ";
            cin.ignore();
            getline(cin, transaction.description);
            cout << "Enter transaction amount: ";
            cin >> transaction.amount;
            cout << "Enter transaction category: ";
            cin.ignore();
            getline(cin, transaction.category);

            // Get current date and time
            time_t now = time(0);
            tm* localTime = localtime(&now);
            char date[11]; // Buffer for date in the format YYYY-MM-DD
            strftime(date, sizeof(date), "%Y-%m-%d", localTime);

            transaction.date = date;

            budgetTracker.addTransaction(transaction);
            cout << "Transaction added successfully." << endl;
            break;
        }
        case 2:
            budgetTracker.printTransactions();
            break;
        case 3:
            budgetTracker.printSummary();
            break;
        case 4:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}




















