# Book Review Tracker

A terminal-based application for managing personal book reviews with persistent storage. Built in C as a learning project to explore file I/O, memory management, modular programming, and user input validation.

## Features

**Core Functionality**
- Add book reviews with title, author, written review, and star rating (0-5)
- Display all submitted reviews in formatted output
- Identify and highlight highest-rated books
- Automatic file persistence to `bookreview.txt`

**Technical Implementation**
- Comprehensive error handling and input validation
- Dynamic memory allocation with proper cleanup
- Modular function-based architecture with separate utility files
- Robust file I/O operations

## Project Structure

```
book-review-tracker/
├── book_review2.c      # Main program logic
├── input_utils.h       # Input utility function declarations
├── input_utils.c       # Input utility function implementations
└── bookreview.txt      # Generated output file
```

## Installation & Usage

```bash
gcc -o book_review book_review2.c input_utils.c
./book_review
```

## Technical Concepts

- C structs and dynamic arrays
- Memory management (`malloc`, `free`)
- File I/O operations and data persistence
- Input validation and error recovery
- String manipulation and formatting
- **Modular programming with header files**
- **Separation of concerns and code organization**

## Sample Output

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
STARS: ★★★★★
BOOK NAME: The Great Gatsby
AUTHOR: F. Scott Fitzgerald
REVIEW: A timeless classic about the American Dream

STARS: ★★★★
BOOK NAME: 1984
AUTHOR: George Orwell
REVIEW: Dystopian masterpiece that feels eerily relevant

=====================
Highest Rated Book(s):
The Great Gatsby by F. Scott Fitzgerald
Stars: ★★★★★
=====================

Reviews saved to bookreview.txt
```

## Version History

**v2.1 - Current**
- **NEW**: Modular code structure with separate utility files
- **NEW**: Reusable input handling functions (`input_utils.h/c`)
- Improved code organization and maintainability
- Enhanced separation of concerns

**v2.0**
- Added persistent file storage
- Implemented comprehensive error handling
- Improved modular code structure
- Enhanced input validation and user feedback

## Utility Functions

The project includes reusable utility functions for input handling:

- `clear_input_buffer()` - Clears leftover input after scanf operations
- `trim_newline()` - Removes trailing newlines from fgets input

These utilities can be reused in other C projects for robust input handling.

## Future Enhancements

- Interactive menu system for navigation
- Edit and delete functionality for existing reviews
- Search capabilities by title or author
- Export options (CSV, JSON)
- Reading list and wishlist features
- Enhanced rating system with multiple categories

## Learning Outcomes

This project provided hands-on experience with:
- Memory management and leak prevention
- File I/O and data persistence patterns
- Error handling strategies in C
- **Modular programming and code organization**
- **Header file creation and management**
- User interface design for command-line applications
- Software versioning and iterative development

---

*Learning project focused on C programming fundamentals and software development practices.*