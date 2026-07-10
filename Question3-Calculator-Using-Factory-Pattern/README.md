# Question 3 – Calculator Using Factory Pattern

## Overview

This project is a Qt-based graphical calculator developed using C++. The application performs the four basic arithmetic operations while demonstrating modern object-oriented software design through the use of the Factory Method and Singleton design patterns.

The graphical user interface was created programmatically without using Qt Designer.

---

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Clear button
- Overflow handling
- Division-by-zero validation
- Dynamic creation of operation objects

---

## Programming Concepts

- Object-Oriented Programming
- Factory Method Pattern
- Singleton Pattern
- Polymorphism
- Abstract Classes
- Event-Driven Programming
- GUI Development
- Error Handling

---

## Classes

### GUI

Provides the graphical calculator interface and handles user interaction.

---

### Operation

Abstract base class defining the compute() interface.

---

### Addition

Implements addition.

---

### Subtraction

Implements subtraction.

---

### Multiplication

Implements multiplication.

---

### Division

Implements division.

---

### OperationFactory

Implements the Factory Method pattern and is responsible for creating the correct operation object.

---

## Design Patterns Used

### Factory Method

The calculator creates mathematical operation objects dynamically based on the button selected by the user.

### Singleton

Only one instance of the `OperationFactory` exists throughout the application.

---



## How to Run
### Steps

1. Open the project in Qt Creator.
2. Build the project.
3. Run the application.
4. Enter two values.
5. Select the required mathematical operation.

---

## Skills Demonstrated

- Factory Method Pattern
- Singleton Pattern
- Object-Oriented Programming
- Polymorphism
- GUI Programming
- Event Handling
- Error Handling
- Software Architecture
- Qt Widgets

---

## Key Learning Outcomes

Through this project I gained practical experience with:

- Applying the Factory Method design pattern.
- Implementing the Singleton pattern.
- Designing reusable object-oriented software.
- Separating business logic from the graphical user interface.
- Handling mathematical exceptions and user input validation.

---

## Future Improvements

- Scientific calculator functions
- Keyboard shortcuts
- Calculation history
- Memory functions
- Dark mode
- Unit testing
