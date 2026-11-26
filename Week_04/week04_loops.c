// Week 4 C companion: loop control, validation, and nested tables.
#include <stdio.h>

int main(void) {
    int n, sum = 0, number;
    printf("ACTIVITY 1 - Enter positive N: ");
    if (scanf("%d", &n) != 1 || n < 1) { puts("N must be positive."); return 1; }
    for (int i = 1; i <= n; ++i) sum += i;
    printf("Sum from 1 to %d = %d\n", n, sum);

    puts("\nACTIVITY 2 - Skip multiples of 3; stop at 15");
    for (int i = 1; i <= 20; ++i) {
        if (i == 15) { puts("Breaking at 15!"); break; }
        if (i % 3 == 0) continue;
        printf("%d ", i);
    }
    printf("\n\nACTIVITY 3A - while validation\nEnter a positive number: ");
    if (scanf("%d", &number) != 1) return 1;
    while (number <= 0) { printf("Invalid. Try again: "); if (scanf("%d", &number) != 1) return 1; }
    printf("Accepted: %d\n", number);
    puts("ACTIVITY 3B - do-while validation");
    do { printf("Enter a positive number: "); if (scanf("%d", &number) != 1) return 1; if (number <= 0) printf("Invalid. "); }
    while (number <= 0);
    printf("Accepted: %d\n\n", number);

    puts("ACTIVITY 4 - Multiplication table (1 to 10)");
    printf("    "); for (int col = 1; col <= 10; ++col) printf("%4d", col);
    printf("\n------------------------------------------------\n");
    for (int row = 1; row <= 10; ++row) {
        printf("%3d|", row);
        for (int col = 1; col <= 10; ++col) printf("%4d", row * col);
        putchar('\n');
    }
    puts("Challenge table 1 to 5:");
    for (int row = 1; row <= 5; ++row) { for (int col = 1; col <= 5; ++col) printf("%4d", row * col); putchar('\n'); }
    return 0;
}
