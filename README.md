# Book Review Tracker
A terminal-based application for managing personal book reviews with persistent storage. Built in C as a learning project to explore file I/O, memory management, modular programming, and user input validation.

## Features
**Core Functionality**
- Add book reviews with title, author, written review, and star rating (1-5)
- Display all submitted reviews in professionally formatted output
- Identify and highlight highest-rated books with visual ratings
- Automatic file persistence to `bookreview.txt`
- Review summary statistics including average ratings

**Technical Implementation**
- Comprehensive error handling and input validation
- Dynamic memory allocation with proper cleanup
- Modular function-based architecture with separate utility files
- Robust file I/O operations with formatted output
- Enhanced user interface with progress indicators and visual separators

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
- **Professional output formatting and user interface design**

## Sample Output
```
==========================================
  BOOK REVIEW MANAGER
==========================================

How many books would you like to review? 2

------------------------
  ENTERING BOOK DETAILS
------------------------

[Book 1 of 2]
Book Title: The Great Gatsby
Author: F. Scott Fitzgerald
Review: A timeless classic about the American Dream
Rating (1-5 stars): 5

------------------------

[Book 2 of 2]
Book Title: 1984
Author: George Orwell
Review: Dystopian masterpiece that feels eerily relevant
Rating (1-5 stars): 4

==========================================
  SUCCESS! Reviews saved to bookreview.txt
==========================================
```

**Generated File Output:**
```
==========================================
  COMPLETE BOOK REVIEW COLLECTION
==========================================

[Review #1]
Title: The Great Gatsby
Author: F. Scott Fitzgerald
Rating: ****- (5/5)
Review: A timeless classic about the American Dream

------------------------

[Review #2]
Title: 1984
Author: George Orwell
Rating: ****- (4/5)
Review: Dystopian masterpiece that feels eerily relevant

==========================================
  TOP RATED BOOK
==========================================

Title: The Great Gatsby
Author: F. Scott Fitzgerald
Rating: ****- (5/5)

==========================================

==========================================
  REVIEW SUMMARY
==========================================

Total Books Reviewed: 2
Average Rating: 4.5/5
Highest Rating: 5/5

==========================================
```

## Version History
**v2.2 - Current**
- **NEW**: Enhanced visual formatting with consistent separators and headers
- **NEW**: Professional output styling with progress indicators
- **NEW**: Visual star rating system (filled/empty stars)
- **NEW**: Review summary statistics and analytics
- **NEW**: Improved user interface with section organization
- Better error messaging and user feedback

**v2.1**
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
- `print_header()` - Creates consistent formatted section headers
- `print_mini_separator()` - Adds visual separation between sections

These utilities can be reused in other C projects for robust input handling and professional output formatting.

## Future Enhancements
- Interactive menu system for navigation
- Edit and delete functionality for existing reviews
- Search capabilities by title or author
- Export options (CSV, JSON)
- Reading list and wishlist features
- Enhanced rating system with multiple categories
- Color-coded terminal output
- Review sorting and filtering options

## Learning Outcomes
This project provided hands-on experience with:
- Memory management and leak prevention
- File I/O and data persistence patterns
- Error handling strategies in C
- **Modular programming and code organization**
- **Header file creation and management**
- User interface design for command-line applications
- **Professional output formatting and user experience design**
- Software versioning and iterative development

---
*Learning project focused on C programming fundamentals and software development practices.*