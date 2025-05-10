# Book Review Tracker (C)

This is my first time programming my own small project! 
This is a simple terminal-based application that allows users to enter and view book reviews, including star ratings and written feedback.

## Features

- Add multiple book reviews:
  - Title
  - Author
  - Written review
  - Star rating (0–5)
- Display all submitted reviews
- Identify and print the highest-rated book(s)

## Concepts Used

- C structs and arrays
- Loops and conditionals
- User input with `scanf()` and `fgets()`
- String manipulation and basic validation

## Example Output

```
How many books would you like to review? 3

Book name: Wuthering Heights
Author: Emily Brontë
Review: (review here)
How many stars out of five would you give this book? 5

Book name: Jane Eyre
Author: Charlotte Brontë
Review: (review here)
How many stars out of five would you give this book? 4

Book name: Agnes Grey
Author: Anne Brontë
Review: (review here)
How many stars out of five would you give this book? 3

ALL BOOKS REVIEWED: 

STARS: * * * * *
BOOK NAME: Wuthering Heights
AUTHOR: Emily Brontë
REVIEW: (review here)

STARS: * * * *
BOOK NAME: Jane Eyre
AUTHOR: Charlotte Brontë
REVIEW: (review here)

STARS: * * *
BOOK NAME: Shirley
AUTHOR: Charlotte Brontë
REVIEW: (review here)


=====================
Highest Rated Book(s):

Wuthering Heights by Emily Brontë
Stars: * * * * *
=====================
```

## Things I Will Improve/Add In The Future
- Menus! (coming soon)
- Options to edit/delete existing review
- Search feature by title or author
- Average rating
