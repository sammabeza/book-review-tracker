# Book Review Tracker (C)

This is my first time programming my own small project! 

This is a simple terminal-based application that allows users to enter and view book reviews, including star ratings and written feedback. Reviews are automatically saved to a text file for future reference.

## Features

- Add multiple book reviews:
  - Title
  - Author
  - Written review
  - Star rating (0–5)
- Display all submitted reviews
- Identify and print the highest-rated book(s)
- **Save reviews to file**: All reviews are automatically saved to `bookreview.txt`
- **Error handling**: Robust input validation and error recovery

## Recent Updates (v2.0)

### New Features
- **File output**: Reviews are now saved to `bookreview.txt` for permanent storage
- **Comprehensive error handling**: 
  - Memory allocation failure protection
  - File operation error checking
  - Input validation for all user entries
  - Graceful recovery from invalid inputs

### Code Improvements
- **Modular design**: Code organized into logical functions for better maintainability
- **Memory safety**: Proper dynamic memory allocation and cleanup
- **Input validation**: All user inputs are validated with appropriate error messages
- **Better user feedback**: Clear error messages and confirmation when operations succeed

### Bug Fixes
- Fixed pointer validation in `review_amount()` function
- Removed unused function declarations
- Improved star rating validation logic

## How to Compile and Run

```bash
gcc -o book_review book_review.c
./book_review
```

## Concepts Used

- C structs and arrays
- Dynamic memory allocation (`malloc`, `free`)
- File I/O operations
- Error handling and input validation
- Loops and conditionals
- User input with `scanf()` and `fgets()`
- String manipulation and validation
- Modular programming with functions

## Example Usage

```
How many books would you like to review? 2

Book 1:
Book name: The Great Gatsby
Author: F. Scott Fitzgerald
Review: A timeless classic about the American Dream
How many stars out of five? 5

Book 2:
Book name: 1984
Author: George Orwell
Review: Dystopian masterpiece that feels eerily relevant
How many stars out of five? 4

ALL BOOKS REVIEWED:

STARS: * * * * * 
BOOK NAME: The Great Gatsby
AUTHOR: F. Scott Fitzgerald
REVIEW: A timeless classic about the American Dream

STARS: * * * * 
BOOK NAME: 1984
AUTHOR: George Orwell
REVIEW: Dystopian masterpiece that feels eerily relevant

=====================
Highest Rated Book(s):

The Great Gatsby by F. Scott Fitzgerald
Stars: * * * * * 
=====================

Reviews saved to bookreview.txt
```

## Output File

The program creates a `bookreview.txt` file containing all your reviews in a formatted layout that you can reference later or share with others.

## Things I Will Improve/Add In The Future

- **Interactive menus**: Navigate between different options
- **Edit/delete functionality**: Modify existing reviews
- **Search feature**: Find books by title or author
- **Statistics**: Average ratings, review counts
- **CSV export**: Export reviews in spreadsheet format
- **Reading list**: Track books you want to read
- **Rating categories**: Separate ratings for plot, characters, writing style

## Learning Journey

This project helped me understand:
- The importance of error handling in real applications
- How to structure larger C programs with multiple functions
- Memory management and avoiding memory leaks
- File I/O operations and data persistence
- User experience considerations in command-line applications

---

*This is a learning project created to practice C programming fundamentals and software development best practices.*