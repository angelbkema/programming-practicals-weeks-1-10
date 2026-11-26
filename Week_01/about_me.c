// About Me - C version of the Week 1 interactive practical.
// This version uses seven questions, 200-character answer arrays,
// a blank-name check, and a personalized closing message.

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

static int read_answer(const char *prompt, char answer[MAX_LEN]) {
    fputs(prompt, stdout);
    if (fgets(answer, MAX_LEN, stdin) == NULL) {
        return 0;
    }

    size_t length = strcspn(answer, "\n");
    if (answer[length] == '\n') {
        answer[length] = '\0';
    } else {
        // Discard the rest of an answer that is longer than the array.
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
    }
    return 1;
}

static int is_blank(const char *text) {
    while (*text != '\0') {
        if (!isspace((unsigned char)*text)) {
            return 0;
        }
        text++;
    }
    return 1;
}

int main(void) {
    char name[MAX_LEN];
    char course[MAX_LEN];
    char hobby[MAX_LEN];
    char reason[MAX_LEN];
    char expectation[MAX_LEN];
    char definition[MAX_LEN];
    char favourite_food[MAX_LEN];

    printf("==============================================\n");
    printf("            WELCOME TO MY FIRST C PROGRAM     \n");
    printf("==============================================\n\n");

    do {
        if (!read_answer("1. What is your name? ", name)) {
            return 1;
        }
        if (is_blank(name)) {
            printf("You didn't enter a name! Please try again.\n");
        }
    } while (is_blank(name));

    if (!read_answer("2. What course are you doing? (BBIT/BCS): ", course) ||
        !read_answer("3. What is your hobby? ", hobby) ||
        !read_answer("4. Why did you choose this course? ", reason) ||
        !read_answer("5. What do you expect to learn in programming? ", expectation) ||
        !read_answer("6. In your own words, what is programming? ", definition) ||
        !read_answer("7. What is your favourite food? ", favourite_food)) {
        printf("Input ended before all answers were entered.\n");
        return 1;
    }

    printf("\n+----------------------------------------------+\n");
    printf("|              YOUR PROFILE SUMMARY           |\n");
    printf("+----------------------------------------------+\n");
    printf("| Name:           %s\n", name);
    printf("| Course:         %s\n", course);
    printf("| Hobby:          %s\n", hobby);
    printf("| Reason:         %s\n", reason);
    printf("| Expectation:    %s\n", expectation);
    printf("| Programming is: %s\n", definition);
    printf("| Favourite food: %s\n", favourite_food);
    printf("+----------------------------------------------+\n");
    printf("\nGreat job, %s! You are on your way to becoming a programmer!\n", name);
    printf("Thank you for completing this practical.\n");

    return 0;
}
