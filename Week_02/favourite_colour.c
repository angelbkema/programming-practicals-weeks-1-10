// Optional Week 2 bonus: ask for a favourite colour and display it.

#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int main(void) {
    char colour[MAX_LEN];

    printf("Enter your favourite colour: ");
    if (fgets(colour, MAX_LEN, stdin) == NULL) {
        printf("No colour was entered.\n");
        return 1;
    }
    colour[strcspn(colour, "\n")] = '\0';

    printf("Your favourite colour is %s.\n", colour);
    return 0;
}
