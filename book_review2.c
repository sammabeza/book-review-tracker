#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input_utils.h"

#define MAX_BOOKS 100
#define MAX_STARS 5 
#define MAX_LENGTH 1000
#define SEPARATOR "=========================================="
#define MINI_SEPARATOR "------------------------"

// struct to hold book review data
typedef struct
{
    int stars;
    char name[MAX_LENGTH];
    char author[MAX_LENGTH];
    char review[MAX_LENGTH];
} book_review;

// function to print a header with title
void print_header(FILE *file, const char *title)
{
    fprintf(file, "\n%s\n", SEPARATOR);
    fprintf(file, "  %s\n", title);
    fprintf(file, "%s\n", SEPARATOR);
}

// function to print a mini separator
void print_mini_separator(FILE *file)
{
    fprintf(file, "%s\n", MINI_SEPARATOR);
}

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
    printf("\n%s\n", SEPARATOR);
    printf("  BOOK REVIEW MANAGER\n");
    printf("%s\n", SEPARATOR);
    printf("\nHow many books would you like to review? ");
    
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
    printf("\n%s\n", MINI_SEPARATOR);
    printf("  ENTERING BOOK DETAILS\n");
    printf("%s\n", MINI_SEPARATOR);
    
    for (int i = 0; i < num; i++)
    {
        printf("\n[Book %d of %d]\n", i + 1, num);

        printf("Book Title: ");
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

        printf("Rating (1-5 stars): ");
        if (scanf("%d", &reviews[i].stars) != 1)
        {
            printf("Invalid input, setting to 5 stars.\n");
            reviews[i].stars = MAX_STARS;
        }
        clear_input_buffer();

        if (reviews[i].stars < 1 || reviews[i].stars > MAX_STARS)
        {
            printf("Invalid star rating, setting to %d stars.\n", MAX_STARS);
            reviews[i].stars = MAX_STARS;
        }
        
        if (i < num - 1) {
            printf("\n%s\n", MINI_SEPARATOR);
        }
    }
}

void print_books(int num, book_review *reviews, FILE *file)
{
    print_header(file, "COMPLETE BOOK REVIEW COLLECTION");
    
    for (int i = 0; i < num; i++)
    {
        fprintf(file, "\n[Review #%d]\n", i + 1);
        fprintf(file, "Title: %s\n", reviews[i].name);
        fprintf(file, "Author: %s\n", reviews[i].author);
        fprintf(file, "Rating: ");
        
        // Print filled stars
        for (int j = 0; j < reviews[i].stars; j++)
        {
            fprintf(file, "*");
        }
        // Print empty stars
        for (int j = reviews[i].stars; j < MAX_STARS; j++)
        {
            fprintf(file, "-");
        }
        fprintf(file, " (%d/5)\n", reviews[i].stars);
        
        fprintf(file, "Review: %s\n", reviews[i].review);
        
        if (i < num - 1) {
            fprintf(file, "\n");
            print_mini_separator(file);
        }
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
    int count = 0;
    
    // Count how many books have the highest rating
    for (int i = 0; i < num; i++)
    {
        if (reviews[i].stars == highest)
        {
            count++;
        }
    }
    
    fprintf(file, "\n\n");
    if (count == 1) {
        print_header(file, "TOP RATED BOOK");
    } else {
        print_header(file, "TOP RATED BOOKS");
    }
    
    for (int i = 0; i < num; i++)
    {
        if (reviews[i].stars == highest)
        {
            fprintf(file, "\nTitle: %s\n", reviews[i].name);
            fprintf(file, "Author: %s\n", reviews[i].author);
            fprintf(file, "Rating: ");
            for (int j = 0; j < reviews[i].stars; j++)
            {
                fprintf(file, "*");
            }
            for (int j = reviews[i].stars; j < MAX_STARS; j++)
            {
                fprintf(file, "-");
            }
            fprintf(file, " (%d/5)\n", reviews[i].stars);
        }
    }
    
    fprintf(file, "\n%s\n", SEPARATOR);
}

void print_summary(int num, book_review *reviews, FILE *file)
{
    fprintf(file, "\n");
    print_header(file, "REVIEW SUMMARY");
    
    // Calculate average rating
    float total = 0;
    for (int i = 0; i < num; i++)
    {
        total += reviews[i].stars;
    }
    float average = total / num;
    
    fprintf(file, "\nTotal Books Reviewed: %d\n", num);
    fprintf(file, "Average Rating: %.1f/5\n", average);
    fprintf(file, "Highest Rating: %d/5\n", get_highest(num, reviews));
    
    fprintf(file, "\n%s\n", SEPARATOR);
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
    
    // print summary statistics
    print_summary(num, reviews, file);

    printf("\n%s\n", SEPARATOR);
    printf("  SUCCESS! Reviews saved to bookreview.txt\n");
    printf("%s\n", SEPARATOR);

    fclose(file);
    free(reviews);
    return 0;
}