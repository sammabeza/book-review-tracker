#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input_utils.h"

#define MAX_BOOKS 100
#define MAX_STARS 5 
#define MAX_LENGTH 1000

// struct to hold book review data
typedef struct
{
    int stars;
    char name[MAX_LENGTH];
    char author[MAX_LENGTH];
    char review[MAX_LENGTH];
} book_review;

// function to open a file where all the book reviews will go to
FILE* open_file()
{
    FILE *file = fopen("bookreview.txt", "w");
    if (file == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return NULL;
    }
    return file;
}

// function to ask user how many books to review
int review_amount(int *num, book_review **reviews)
{
    printf("How many books would you like to review? ");
    if (scanf("%d", num) != 1)
    {
        printf("Error: Invalid input.\n");
        return 1;
    }
    clear_input_buffer();

    if (*num <= 0 || *num > MAX_BOOKS)
    {
        printf("Invalid number of books. Please enter 1-%d.\n", MAX_BOOKS);
        return 1;
    }
    
    *reviews = malloc(*num * sizeof(book_review));
    if (*reviews == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    return 0;
}

void collect_books(int num, book_review *reviews)
{
    for (int i = 0; i < num; i++)
    {
        printf("\nBook %d:\n", i + 1);

        printf("Book name: ");
        if (!fgets(reviews[i].name, MAX_LENGTH, stdin))
        {
            printf("Error reading book name.\n");
            continue;
        }
        trim_newline(reviews[i].name);

        printf("Author: ");
        if (!fgets(reviews[i].author, MAX_LENGTH, stdin))
        {
            printf("Error reading author name.\n");
            continue;
        }
        trim_newline(reviews[i].author);

        printf("Review: ");
        if (!fgets(reviews[i].review, MAX_LENGTH, stdin))
        {
            printf("Error reading review.\n");
            continue;
        }
        trim_newline(reviews[i].review);

        printf("How many stars out of five? ");
        if (scanf("%d", &reviews[i].stars) != 1)
        {
            printf("Invalid input, setting to 5 stars.\n");
            reviews[i].stars = MAX_STARS;
        }
        clear_input_buffer();

        if (reviews[i].stars < 0 || reviews[i].stars > MAX_STARS)
        {
            printf("Invalid star rating, setting to %d stars.\n", MAX_STARS);
            reviews[i].stars = MAX_STARS;
        }
    }
}

void print_books(int num, book_review *reviews, FILE *file)
{
    fprintf(file, "\nALL BOOKS REVIEWED:\n");
    for (int i = 0; i < num; i++)
    {
        fprintf(file, "\n");
        fprintf(file, "STARS: ");
        for (int j = 0; j < reviews[i].stars; j++)
        {
            fprintf(file, "* ");
        }
        fprintf(file, "\n");
        fprintf(file, "BOOK NAME: %s\nAUTHOR: %s\nREVIEW: %s\n",
               reviews[i].name, reviews[i].author, reviews[i].review);
    }
}

int get_highest(int num, book_review *reviews)
{
    int highest = 0;
    for (int i = 0; i < num; i++)
    {
        if (reviews[i].stars > highest)
        {
            highest = reviews[i].stars;
        }
    }
    return highest;
}

void print_highest(int num, book_review *reviews, FILE *file)
{
    int highest = get_highest(num, reviews);

    fprintf(file, "\n=====================\n");
    fprintf(file, "Highest Rated Book(s):\n\n");
    for (int i = 0; i < num; i++)
    {
        if (reviews[i].stars == highest)
        {
            fprintf(file, "%s by %s\n", reviews[i].name, reviews[i].author);
            fprintf(file, "Stars: ");
            for (int j = 0; j < reviews[i].stars; j++)
            {
                fprintf(file, "* ");
            }
            fprintf(file, "\n");
        }
    }
    fprintf(file, "\n=====================\n");
}

int main(void)
{
    int num = 0;
    book_review *reviews = NULL;

    // opening file
    FILE* file = open_file();
    if (file == NULL)
    {
        return 1;
    }

    // amount of books reviewing
    if (review_amount(&num, &reviews) != 0)
    {
        fclose(file);
        return 1;
    }

    // collect book reviews
    collect_books(num, reviews);

    // print all reviews
    print_books(num, reviews, file);

    // find highest rated book(s) and print
    print_highest(num, reviews, file);

    printf("Reviews saved to bookreview.txt\n");

    fclose(file);
    free(reviews);
    return 0;
}