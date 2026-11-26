// Week 2 Student Score Calculator - C++ version
// Includes four-test calculation, score validation, highest score, and grade.

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

const int MAX_SCORE = 100;
const int NUMBER_OF_TESTS = 4;
const int MAX_TOTAL = MAX_SCORE * NUMBER_OF_TESTS;

bool read_score(const string& prompt, int& score) {
    while (true) {
        cout << prompt;
        if (!(cin >> score)) {
            if (cin.eof()) {
                return false;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a whole number from 0 to "
                 << MAX_SCORE << ".\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (score < 0 || score > MAX_SCORE) {
            cout << "Score must be between 0 and " << MAX_SCORE
                 << ". Please try again.\n";
            continue;
        }
        return true;
    }
}

int main() {
    string studentName;
    string course;
    int score1, score2, score3, score4;
    int totalScore;
    int highestScore;
    double average;
    double percentage;
    char grade;

    cout << "========================================\n";
    cout << "       STUDENT SCORE CALCULATOR         \n";
    cout << "========================================\n\n";

    cout << "Enter student name: ";
    getline(cin, studentName);
    cout << "Enter course (BBIT/BCS): ";
    getline(cin, course);

    if (!read_score("Enter score for Test 1: ", score1) ||
        !read_score("Enter score for Test 2: ", score2) ||
        !read_score("Enter score for Test 3: ", score3) ||
        !read_score("Enter score for Test 4: ", score4)) {
        cout << "Input ended before all scores were entered.\n";
        return 1;
    }

    totalScore = score1 + score2 + score3 + score4;
    average = totalScore / static_cast<double>(NUMBER_OF_TESTS);
    percentage = (totalScore / static_cast<double>(MAX_TOTAL)) * 100.0;

    highestScore = score1;
    if (score2 > highestScore) highestScore = score2;
    if (score3 > highestScore) highestScore = score3;
    if (score4 > highestScore) highestScore = score4;

    if (percentage >= 90) grade = 'A';
    else if (percentage >= 80) grade = 'B';
    else if (percentage >= 70) grade = 'C';
    else if (percentage >= 60) grade = 'D';
    else grade = 'F';

    cout << "\n========================================\n";
    cout << "               REPORT CARD             \n";
    cout << "========================================\n\n";
    cout << "Student:      " << studentName << '\n';
    cout << "Course:       " << course << "\n\n";
    cout << "Test 1:       " << score1 << '/' << MAX_SCORE << '\n';
    cout << "Test 2:       " << score2 << '/' << MAX_SCORE << '\n';
    cout << "Test 3:       " << score3 << '/' << MAX_SCORE << '\n';
    cout << "Test 4:       " << score4 << '/' << MAX_SCORE << "\n\n";
    cout << "Total:        " << totalScore << '/' << MAX_TOTAL << '\n';
    cout << fixed << setprecision(2);
    cout << "Average:      " << average << '\n';
    cout << "Percentage:   " << percentage << "%\n";
    cout << "Highest score:" << ' ' << highestScore << '\n';
    cout << "Grade:        " << grade << '\n';
    cout << "Result:       " << (percentage >= 50 ? "PASS" : "FAIL") << '\n';
    cout << "========================================\n";

    return 0;
}
