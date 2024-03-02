#include <iostream>
#include <map>
#include <string>
#include <fstream> // for file operations
#include <limits>

using namespace std;

class GroceryManager {
private:
    map<string, int> itemFrequency;

public:
    // Constructor to initialize data
    GroceryManager() {
        initializeData();
    }

    // Function to initialize item frequencies
    void initializeData() {
        // Data containing items
        string data = "Spinach Radishes Broccoli Peas Cranberries Cranberries Potatoes Cucumbers Radishes Cranberries Peaches Zucchini Potatoes Cranberries Cantaloupe Beets Cauliflower Cranberries Peas Zucchini Peas Onions Potatoes Cauliflower Spinach Radishes Onions Zucchini Cranberries Peaches Yams Zucchini Apples Apples Cucumbers Broccoli Cranberries Beets Peas Cauliflower Potatoes Cauliflower Celery Limes Cranberries Broccoli Spinach Broccoli Garlic Cauliflower Pumpkins Celery Peas Potatoes Yams Zucchini Cranberries Cantaloupe Zucchini Pumpkins Cauliflower Yams Pears Peaches Apples Zucchini Cranberries Zucchini Garlic Broccoli Garlic Onions Spinach Cucumbers Cucumbers Garlic Spinach Peaches Cucumbers Broccoli Zucchini Peas Celery Cucumbers Celery Yams Garlic Cucumbers Peas Beets Yams Peas Apples Peaches Garlic Celery Garlic Cucumbers Garlic Apples Celery Zucchini Cucumbers Onions";
        string item;
        size_t pos = 0;
        // Parsing the data string to extract items and count frequencies
        while ((pos = data.find(" ")) != string::npos) {
            item = data.substr(0, pos);
            itemFrequency[item]++;
            data.erase(0, pos + 1);
        }
        // Handle the last item after the loop
        if (!data.empty()) {
            itemFrequency[data]++;
        }
    }

    // Function to write item frequencies to a file
    void writeFrequencyToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& pair : itemFrequency) {
                outFile << pair.first << " " << pair.second << endl;
                cout << "adding " << pair.first << " " << pair.second << endl;
            }
            outFile.close();
            cout << "Frequency data written to " << filename << " successfully." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    // Function to get frequency of a specific item
    int getItemFrequency(const string& item) {
        return itemFrequency[item];
    }

    // Function to print item frequency list
    void printItemFrequencyList() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Function to print histogram of item frequencies
    void printHistogram() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a GroceryManager object
    GroceryManager manager;

    // Write item frequencies to a file
    manager.writeFrequencyToFile("frequency.dat");

    int choice = 0;
    // Main menu loop
    while (choice != 4) {
        cout << "\nMenu:\n";
        cout << "1. Search for item frequency\n";
        cout << "2. Print item frequency list\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Switch based on user choice
        switch (choice) {
        case 1: {
            string item;
            cout << "Enter item to search: ";
            cin >> item;
            cout << "Frequency: " << manager.getItemFrequency(item) << endl;
            break;
        }
        case 2:
            manager.printItemFrequencyList();
            break;
        case 3:
            manager.printHistogram();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}




















