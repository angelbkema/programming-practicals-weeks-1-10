// Week 3: conditionals, nested decisions, menu selection, and grading.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void eventEligibility() {
    int age, ticket, member, banned, parent;
    cout << "\nACTIVITY 1 - Event eligibility\nAge, ticket(1/0), member(1/0), banned(1/0), parent(1/0): ";
    if (!(cin >> age >> ticket >> member >> banned >> parent)) return;
    bool baseAllowed = ((age >= 18 && ticket) || member) && !banned;
    bool canEnter = baseAllowed && (age >= 16 || parent);
    cout << (canEnter ? "You can enter the event.\n" : "Sorry, you cannot enter.\n");
}

void nestedConditions() {
    int a, b, c;
    cout << "\nACTIVITY 2 - Enter three distinct numbers: ";
    if (!(cin >> a >> b >> c)) return;
    if (a > b && b > c) cout << "Path 1: a > b > c\n";
    else if (a > c && c > b) cout << "Path 2: a > c > b\n";
    else if (b > a && a > c) cout << "Path 3: b > a > c\n";
    else if (b > c && c > a) cout << "Path 4: b > c > a\n";
    else if (c > a && a > b) cout << "Path 5: c > a > b\n";
    else if (c > b && b > a) cout << "Path 6: c > b > a\n";
    else cout << "Some values are equal; the six paths assume distinct values.\n";
}

void menuComparison() {
    int choice;
    cout << "\nACTIVITY 3 - Menu choice (1 Start, 2 Load, 3 Settings, 4 Exit): ";
    if (!(cin >> choice)) return;
    cout << "if-else version: ";
    if (choice == 1) cout << "Starting game...\n";
    else if (choice == 2) cout << "Loading game...\n";
    else if (choice == 3) cout << "Opening settings...\n";
    else if (choice == 4) cout << "Exiting...\n";
    else cout << "Invalid choice!\n";
    cout << "switch version: ";
    switch (choice) {
        case 1: cout << "Starting game...\n"; break;
        case 2: cout << "Loading game...\n"; break;
        case 3: cout << "Opening settings...\n"; break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
    }
}

void gradeCalculator() {
    int count;
    cout << "\nACTIVITY 4 - Number of students: ";
    if (!(cin >> count) || count < 1 || count > 100) {
        cout << "Enter a student count from 1 to 100.\n"; cin.clear(); cin.ignore(10000, '\n'); return;
    }
    int totals[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < count; ++i) {
        string name; double score;
        cout << "Student name: "; cin >> ws; getline(cin, name);
        cout << "Percentage (0-100): ";
        if (!(cin >> score) || score < 0 || score > 100) {
            cout << "Invalid score. This student was skipped.\n";
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }
        char grade = score >= 90 ? 'A' : score >= 80 ? 'B' : score >= 70 ? 'C' : score >= 60 ? 'D' : 'F';
        char modifier = ' ';
        int lastDigit = static_cast<int>(score) % 10;
        if (grade == 'A') { if (score >= 97) modifier = '+'; else if (score < 93) modifier = '-'; }
        else if (grade != 'F') { if (lastDigit >= 7) modifier = '+'; else if (lastDigit <= 3) modifier = '-'; }
        cout << fixed << setprecision(1) << name << ": " << score << "% - " << grade;
        if (modifier != ' ') cout << modifier;
        cout << " - ";
        switch (grade) {
            case 'A': cout << "Excellent work!\n"; ++totals[0]; break;
            case 'B': cout << "Good job!\n"; ++totals[1]; break;
            case 'C': cout << "Satisfactory.\n"; ++totals[2]; break;
            case 'D': cout << "Needs improvement.\n"; ++totals[3]; break;
            default: cout << "Please seek help.\n"; ++totals[4];
        }
    }
    cout << "Grade summary A/B/C/D/F: ";
    for (int n : totals) cout << n << ' ';
    cout << '\n';
}

int main() {
    cout << "WEEK 3 - CONTROL STRUCTURES PRACTICAL\n";
    eventEligibility(); nestedConditions(); menuComparison(); gradeCalculator();
    return 0;
}
