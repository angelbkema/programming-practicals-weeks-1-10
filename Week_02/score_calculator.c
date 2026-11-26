// Week 2 Student Score Calculator - C version
// Includes four-test calculation, score validation, highest score, and grade.

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_SCORE 100
#define NUMBER_OF_TESTS 4
#define MAX_TOTAL (MAX_SCORE * NUMBER_OF_TESTS)

static int read_line(const char *prompt, char text[MAX_LEN]) {
    size_t length;
    int character;

    printf("%s", prompt);
    if (fgets(text, MAX_LEN, stdin) == NULL) {
        return 0;
    }

    length = strcspn(text, "\n");
    if (text[length] == '\n') {
        text[length] = '\0';
    } else {
        while ((character = getchar()) != '\n' && character != EOF) {
        }
    }
    return 1;
}

static int read_score(const char *prompt, int *score) {
    int result;
    int character;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", score);
        if (result == EOF) {
            return 0;
        }
        if (result != 1) {
            while ((character = getchar()) != '\n' && character != EOF) {
            }
            printf("Invalid input. Enter a whole number from 0 to %d.\n", MAX_SCORE);
            continue;
        }

        while ((character = getchar()) != '\n' && character != EOF) {
        }
        if (*score < 0 || *score > MAX_SCORE) {
            printf("Score must be between 0 and %d. Please try again.\n", MAX_SCORE);
            continue;
        }
        return 1;
    }
}

int main(void) {
    char studentName[MAX_LEN];
    char course[MAX_LEN];
    int score1, score2, score3, score4;
    int totalScore;
    int highestScore;
    double average;
    double percentage;
    char grade;

    printf("========================================\n");
    printf("       STUDENT SCORE CALCULATOR         \n");
    printf("========================================\n\n");

    if (!read_line("Enter student name: ", studentName) ||
        !read_line("Enter course (BBIT/BCS): ", course)) {
        printf("Input ended before the student details were entered.\n");
        return 1;
    }

    if (!read_score("Enter score for Test 1: ", &score1) ||
        !read_score("Enter score for Test 2: ", &score2) ||
        !read_score("Enter score for Test 3: ", &score3) ||
        !read_score("Enter score for Test 4: ", &score4)) {
        printf("Input ended before all scores were entered.\n");
        return 1;
    }

    totalScore = score1 + score2 + score3 + score4;
    average = totalScore / (double)NUMBER_OF_TESTS;
    percentage = (totalScore / (double)MAX_TOTAL) * 100.0;

    highestScore = score1;
    if (score2 > highestScore) highestScore = score2;
    if (score3 > highestScore) highestScore = score3;
    if (score4 > highestScore) highestScore = score4;

    if (percentage >= 90) grade = 'A';
    else if (percentage >= 80) grade = 'B';
    else if (percentage >= 70) grade = 'C';
    else if (percentage >= 60) grade = 'D';
    else grade = 'F';

    printf("\n========================================\n");
    printf("               REPORT CARD             \n");
    printf("========================================\n\n");
    printf("Student:      %s\n", studentName);
    printf("Course:       %s\n\n", course);
    printf("Test 1:       %d/%d\n", score1, MAX_SCORE);
    printf("Test 2:       %d/%d\n", score2, MAX_SCORE);
    printf("Test 3:       %d/%d\n", score3, MAX_SCORE);
    printf("Test 4:       %d/%d\n\n", score4, MAX_SCORE);
    printf("Total:        %d/%d\n", totalScore, MAX_TOTAL);
    printf("Average:      %.2f\n", average);
    printf("Percentage:   %.2f%%\n", percentage);
    printf("Highest score: %d\n", highestScore);
    printf("Grade:        %c\n", grade);
    printf("Result:       %s\n", percentage >= 50 ? "PASS" : "FAIL");
    printf("========================================\n");

    return 0;
}
