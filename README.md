# Budget Tracker

C++ console-based budget tracking application that lets users load transaction data, add new transactions, view transaction history, and print spending summaries by category.

## Project Overview

This project demonstrates basic C++ application development using a class-based design, file input, transaction storage, menu-driven user interaction, and category-based summary reporting.

The program loads transaction data from a `.dat` file so budget information can persist across program sessions. Users can then add transactions, display transaction history, print summaries, or exit the program through a console menu.

## Repository Contents

- `Budget_Tracker.cpp`: Main C++ budget tracking program
- `budget_data.dat`: Sample transaction data file
- `README.md`: Repository documentation

## Features

- Loads transaction data from a `.dat` file
- Adds new transactions through a console menu
- Stores transaction description, amount, category, and date
- Displays transaction history
- Prints spending summary by category
- Uses a `BudgetTracker` class to organize transaction logic
- Includes basic error handling for file access and invalid menu choices

## How It Works

1. The program starts and attempts to load existing transactions from `budget_data.dat`.
2. The user is shown a menu with options to add transactions, display history, print a summary, or quit.
3. When a transaction is added, the program records the description, amount, category, and current date.
4. Transactions are stored in memory while the program runs.
5. Category totals are tracked and displayed in the budget summary.

## Build and Run

### Requirements

- C++17 or newer
- Visual Studio, g++, or another C++ compiler

### Example Compile Command

```bash
g++ Budget_Tracker.cpp -o Budget_Tracker
```

### Example Run Command

```bash
./Budget_Tracker
```

On Windows, run:

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

Each line includes:

```text
description,amount,category,date
```

## Skills Demonstrated

- C++ programming
- Class-based design
- File input handling
- Transaction data modeling
- Console menu design
- Category-based aggregation
- Input handling
- Error handling
- Basic financial data organization
- Technical reflection and documentation

## Reflection

### Project Purpose

This budget tracker lets users record transactions, view financial history, create spending summaries, and gain insight into spending habits. The goal is to help users make more informed financial decisions, identify areas where they may overspend, and plan better.

Users are presented with a menu where they can choose options to add transactions, display transactions, print summaries, or quit the program.

### Data Persistence

I added file handling to load transaction data from a `.dat` file so budget data can persist across sessions. This feature ensures that financial transactions can be accessed and managed over time, making the program more useful and continuous.

A future improvement would be adding the ability to save newly entered transactions back to the file automatically. That would allow users to maintain a complete financial transaction history without re-entering data each time the program starts.

### Challenges and Problem Solving

One challenge in this project was handling file input and parsing transaction data correctly. Loading transaction data from a file requires attention to file access, formatting, missing data, and invalid input.

To address this, I approached the problem in smaller steps: opening the file, reading each line, parsing transaction fields, and handling errors when the file or data format was invalid. Debugging tools in Visual Studio are useful for stepping through file operations and checking variable values during execution.

### Version Control

In this project, I used GitHub and version control concepts to manage project files and track changes. Version control supports collaboration, code sharing, project history, and safer software development practices.

These skills are transferable to future individual projects, open-source contributions, and team-based development environments.

### Maintainability, Readability, and Adaptability

I prioritized maintainability, readability, and adaptability by using a class-based structure. The `BudgetTracker` class organizes transaction data and related behavior, making the program easier to understand and extend.

The code also uses meaningful variable names, comments, and error-handling logic to make the application easier to review and modify. This structure supports future improvements such as saving transactions, editing transactions, deleting transactions, and generating more detailed reports.

## Future Improvements

- Save newly added transactions back to `budget_data.dat`
- Improve parsing for descriptions with spaces
- Add transaction editing and deletion
- Add monthly or date-range summaries
- Add input validation for transaction amounts
- Add clearer formatting for currency output
- Add a `.gitignore` file for C++/Visual Studio build artifacts
