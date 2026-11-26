// Week 3 C companion: conditions, nested if statements, and grading.
#include <stdio.h>

static void event_eligibility(void) {
    int age, ticket, member, banned, parent;
    printf("\nACTIVITY 1 - Age, ticket(1/0), member(1/0), banned(1/0), parent(1/0): ");
    if (scanf("%d%d%d%d%d", &age, &ticket, &member, &banned, &parent) != 5) return;
    if ((((age >= 18 && ticket) || member) && !banned) && (age >= 16 || parent))
        printf("You can enter the event.\n");
    else printf("Sorry, you cannot enter.\n");
}

static void nested_conditions(void) {
    int a, b, c;
    printf("\nACTIVITY 2 - Enter three distinct numbers: ");
    if (scanf("%d%d%d", &a, &b, &c) != 3) return;
    if (a > b && b > c) puts("Path 1: a > b > c");
    else if (a > c && c > b) puts("Path 2: a > c > b");
    else if (b > a && a > c) puts("Path 3: b > a > c");
    else if (b > c && c > a) puts("Path 4: b > c > a");
    else if (c > a && a > b) puts("Path 5: c > a > b");
    else if (c > b && b > a) puts("Path 6: c > b > a");
    else puts("Some values are equal; the six paths assume distinct values.");
}

static void menu_comparison(void) {
    int choice;
    printf("\nACTIVITY 3 - Menu choice (1 Start, 2 Load, 3 Settings, 4 Exit): ");
    if (scanf("%d", &choice) != 1) return;
    printf("if-else version: ");
    if (choice == 1) puts("Starting game...");
    else if (choice == 2) puts("Loading game...");
    else if (choice == 3) puts("Opening settings...");
    else if (choice == 4) puts("Exiting...");
    else puts("Invalid choice!");
    printf("switch version: ");
    switch (choice) {
        case 1: puts("Starting game..."); break;
        case 2: puts("Loading game..."); break;
        case 3: puts("Opening settings..."); break;
        case 4: puts("Exiting..."); break;
        default: puts("Invalid choice!");
    }
}

static void grade_calculator(void) {
    int count, totals[5] = {0, 0, 0, 0, 0};
    printf("\nACTIVITY 4 - Number of students (1-100): ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 100) { puts("Invalid count."); return; }
    for (int i = 0; i < count; ++i) {
        char name[80], grade, modifier = ' ';
        double score;
        int lastDigit;
        printf("Student name: ");
        if (scanf(" %79[^\n]", name) != 1) return;
        printf("Percentage (0-100): ");
        if (scanf("%lf", &score) != 1 || score < 0 || score > 100) { puts("Invalid score."); return; }
        grade = score >= 90 ? 'A' : score >= 80 ? 'B' : score >= 70 ? 'C' : score >= 60 ? 'D' : 'F';
        lastDigit = (int)score % 10;
        if (grade == 'A') { if (score >= 97) modifier = '+'; else if (score < 93) modifier = '-'; }
        else if (grade != 'F') { if (lastDigit >= 7) modifier = '+'; else if (lastDigit <= 3) modifier = '-'; }
        printf("%s: %.1f%% - %c", name, score, grade);
        if (modifier != ' ') printf("%c", modifier);
        if (grade == 'A') { puts(" - Excellent work!"); ++totals[0]; }
        else if (grade == 'B') { puts(" - Good job!"); ++totals[1]; }
        else if (grade == 'C') { puts(" - Satisfactory."); ++totals[2]; }
        else if (grade == 'D') { puts(" - Needs improvement."); ++totals[3]; }
        else { puts(" - Please seek help."); ++totals[4]; }
    }
    printf("Grade summary A/B/C/D/F: %d %d %d %d %d\n", totals[0], totals[1], totals[2], totals[3], totals[4]);
}

int main(void) {
    puts("WEEK 3 - CONTROL STRUCTURES PRACTICAL (C)");
    event_eligibility(); nested_conditions(); menu_comparison(); grade_calculator();
    return 0;
}
