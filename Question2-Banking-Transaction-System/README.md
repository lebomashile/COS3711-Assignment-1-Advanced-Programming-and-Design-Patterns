# Question 2 – Banking Transaction System

## Overview

This project is a Qt-based graphical banking transaction application developed using C++. It allows users to perform deposit and withdrawal transactions, maintain a transaction history using the Singleton design pattern, and export all transactions to a human-readable text file.

The graphical user interface was created programmatically without using Qt Designer.

---

## Features

- Deposit money
- Withdraw money
- Display the current date
- Record transactions
- Save transactions to a text file
- User-friendly graphical interface

---

## Classes
### Gui

Handles the graphical user interface and user interactions.

---

### Transaction

Represents a banking transaction containing:

- Amount
- Date
- Time
- Transaction Type

---

### TransactionList

Maintains a single collection of transactions using the Singleton pattern.

---

### Writer

Exports all transactions to a human-readable text file.

---

## How to Run
### Steps

1. Open the project in Qt Creator.
2. Build the project.
3. Run the application.
4. Enter an amount.
5. Select Deposit or Withdrawal.
6. Click **To File** to save the transaction history.

---

## Key Learning Outcomes

Through this project I gained practical experience with:

- Designing graphical user interfaces manually using Qt Widgets.
- Applying the Singleton design pattern.
- Managing application data separately from the user interface.
- Writing application data to external files.
- Implementing reusable object-oriented classes.

---

## Future Improvements

- Transaction history table
- Balance calculation
- Input validation
- Account management
- Database storage
- Transaction filtering
