# Question 1 – Command-Line Word Counter

## Overview

This project is a command-line application developed using C++ and the Qt Framework. It processes one or more text files supplied as command-line arguments and analyses the contents using regular expressions.

The application supports multiple command-line flags that enable different types of word analysis.

---

## Features

- Processes one or more text files
- Supports multiple command-line arguments
- Uses regular expressions to identify word patterns
- Counts words based on selected criteria
- Supports multiple flags in a single execution
- Processes text after removing punctuation

---

## Command-Line Flags

| Flag | Description |
|------|-------------|
| -a | Count words longer than four characters that begin with a capital letter |
| -b | Count hyphenated words |
| -c | Count words that start and end with the same character |
| -d | Count words that do not start with a vowel |

If no flags are supplied, all counts are performed.

---
## How to Run

1. Open the project in Qt Creator.
2. Build the application.
3. Configure the required command-line arguments.
4. Run the application.

Example:

```text
count -ab file1.txt fileTwo.txt
```

---

