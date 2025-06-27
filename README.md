# Book Review Tracker

A terminal-based application for managing personal book reviews with persistent storage. Built in C as a learning project to explore file I/O, memory management, and user input validation.

## Features

**Core Functionality**
- Add book reviews with title, author, written review, and star rating (0-5)
- Display all submitted reviews in formatted output
- Identify and highlight highest-rated books
- Automatic file persistence to `bookreview.txt`

**Technical Implementation**
- Comprehensive error handling and input validation
- Dynamic memory allocation with proper cleanup
- Modular function-based architecture
- Robust file I/O operations

## Installation & Usage

```bash
gcc -o book_review book_review2.c
./book_review
```

## Technical Concepts

- C structs and dynamic arrays
- Memory management (`malloc`, `free`)
- File I/O operations and data persistence
- Input validation and error recovery
- String manipulation and formatting
- Modular programming design

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

**v2.0 - Current**
- Added persistent file storage
- Implemented comprehensive error handling
- Improved modular code structure
- Enhanced input validation and user feedback
- Fixed memory allocation and pointer validation issues

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
- User interface design for command-line applications
- Software versioning and iterative development

---

*Learning project focused on C programming fundamentals and software development practices.*
