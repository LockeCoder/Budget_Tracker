# Budget Tracker

A C++ console-based budget tracking application that loads transaction data, lets users add new transactions, displays transaction history, and prints spending summaries by category.

## Project Overview

Budget Tracker is a menu-driven C++ application designed to help users organize basic financial transaction data. The program loads sample transaction records from a `.dat` file, stores transaction information in memory, and gives users options to add transactions, view transaction history, and print category-based summaries.

This project demonstrates C++ fundamentals, class-based program design, file input handling, transaction data modeling, console interaction, and basic financial data organization.

## Repository Contents

- `Budget_Tracker.cpp` - Main C++ budget tracking program
- `budget_data.dat` - Sample transaction data file
- `README.md` - Repository documentation

## Features

- Loads transaction data from a `.dat` file
- Adds new transactions through a console menu
- Stores transaction description, amount, category, and date
- Displays transaction history
- Prints spending summaries by category
- Uses a `BudgetTracker` class to organize transaction logic
- Includes basic error handling for file access and invalid menu choices

## How It Works

1. The program starts and attempts to load existing transactions from `budget_data.dat`.
2. The user is shown a console menu.
3. The user can add transactions, display transaction history, print a category summary, or quit.
4. Each transaction stores a description, amount, category, and date.
5. Transactions are stored in memory while the program runs.
6. Category totals are calculated and displayed in the budget summary.

## Build and Run

### Requirements

- C++17 or newer
- Visual Studio, g++, or another C++ compiler

### Compile with g++

```bash
g++ Budget_Tracker.cpp -o Budget_Tracker
```

### Run on macOS/Linux

```bash
./Budget_Tracker
```

### Run on Windows

```bash
Budget_Tracker.exe
```

## Sample Data Format

The sample data file uses comma-separated transaction records:

```text
Groceries,50.00,Food,2024-03-01
Dinner with friends,30.00,Entertainment,2024-03-02
Gasoline,40.00,Transportation,2024-03-03
```

Each line follows this format:

```text
description,amount,category,date
```

## Skills Demonstrated

- C++ programming
- Class-based design
- File input handling
- Console menu design
- Transaction data modeling
- Category-based aggregation
- Input handling
- Error handling
- Basic financial data organization
- Technical documentation

## Technical Reflection

### Project Purpose

The purpose of this project was to build a small but practical C++ application for tracking financial transactions. Users can view transaction history, enter new transaction records, and summarize spending by category.

The project is useful for demonstrating how structured data can be loaded, stored, processed, and displayed through a simple console interface.

### File Input and Data Persistence

The program loads transaction data from `budget_data.dat` when it starts. This allows the application to begin with existing transaction records instead of requiring users to enter all data manually each time.

A future improvement would be saving newly entered transactions back to the data file automatically. That would make the application more complete by preserving new records between program sessions.

### Program Structure

The project uses a `BudgetTracker` class to organize transaction-related behavior. This keeps the transaction storage, transaction display, summary reporting, and menu-driven logic easier to understand and maintain.

This structure also makes the program easier to expand in the future. Features such as editing transactions, deleting transactions, saving new records, and filtering by date could be added without rewriting the entire application.

### Challenges and Problem Solving

One challenge in this project was handling file input and parsing transaction data correctly. Loading data from a file requires attention to file access, line formatting, missing values, and invalid input.

To solve this, the program separates the process into smaller steps: opening the file, reading transaction records, parsing transaction fields, storing valid records, and handling file access problems when they occur.

### Version Control

This project also demonstrates the use of GitHub and version control to organize project files, document changes, and maintain a project history. These are transferable skills for individual projects, open-source work, and team-based software development.

## Project Value

Budget Tracker demonstrates the ability to build a small C++ console application that reads structured data, organizes records in memory, presents a menu-driven interface, and summarizes financial information by category.

It is strongest for showing C++ fundamentals, class-based design, file input handling, basic data modeling, and maintainable console application structure.

## Future Improvements

- Save newly added transactions back to `budget_data.dat`
- Add transaction editing and deletion
- Add monthly or date-range summaries
- Improve parsing for descriptions with commas or special characters
- Add stronger validation for transaction amounts and dates
- Add clearer currency formatting
- Add sorting by date, category, or amount
- Add a `.gitignore` file for C++ and Visual Studio build artifacts
