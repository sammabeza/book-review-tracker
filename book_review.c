#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 100
#define MAX_STARS 5
#define MAX_LENGTH 1000

// Struct to hold book review data
typedef struct
{
    int stars;
    char name[MAX_LENGTH];
    char author[MAX_LENGTH];
    char review[MAX_LENGTH];
} book_review;

// Helper function to clear the input buffer
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to remove trailing newline from fgets
void trim_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

int main(void)
{
    int num;

    printf("How many books would you like to review? ");
    scanf("%d", &num);
    clear_input_buffer(); // clear leftover newline

    if (num <= 0 || num > MAX_BOOKS)
    {
        printf("Invalid number of books.\n");
        return 1;
    }

    book_review reviews[num];

    // Collect book reviews
    for (int i = 0; i < num; i++)
    {
        printf("\nBook %d:\n", i + 1);

        printf("Book name: ");
        fgets(reviews[i].name, MAX_LENGTH, stdin);
        trim_newline(reviews[i].name);

        printf("Author: ");
        fgets(reviews[i].author, MAX_LENGTH, stdin);
        trim_newline(reviews[i].author);

        printf("Review: ");
        fgets(reviews[i].review, MAX_LENGTH, stdin);
        trim_newline(reviews[i].review);

        printf("How many stars out of five? ");
        scanf("%d", &reviews[i].stars);
        clear_input_buffer();

        if (reviews[i].stars < 0 || reviews[i].stars > MAX_STARS)
        {
            reviews[i].stars = MAX_STARS;
        }
    }

    // Print all reviews
    printf("\nALL BOOKS REVIEWED:\n");
    for (int i = 0; i < num; i++)
    {
        printf("\n");
        printf("STARS: ");
        for (int j = 0; j < reviews[i].stars; j++)
        {
            printf("* ");
        }
        printf("\n");
        printf("BOOK NAME: %s\nAUTHOR: %s\nREVIEW: %s\n",
               reviews[i].name, reviews[i].author, reviews[i].review);
    }

    // Find highest rated book(s)
    int highest = 0;
    for (int i = 0; i < num; i++)
    {
        if (reviews[i].stars > highest)
        {
            highest = reviews[i].stars;
        }
    }

    printf("\n=====================\n");
    printf("Highest Rated Book(s):\n\n");
    for (int i = 0; i < num; i++)
    {
        if (reviews[i].stars == highest)
        {
            printf("%s by %s\n", reviews[i].name, reviews[i].author);
            printf("Stars: ");
            for (int j = 0; j < reviews[i].stars; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    printf("\n=====================\n");

    return 0;
}
