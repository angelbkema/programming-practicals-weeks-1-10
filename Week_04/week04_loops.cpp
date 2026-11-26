// Week 4: for/while/do-while loops, break/continue, and nested loops.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "ACTIVITY 1 - Enter positive N: ";
    if (!(cin >> n) || n < 1) { cout << "N must be positive.\n"; return 1; }
    for (int i = 1; i <= n; ++i) sum += i;
    cout << "Sum from 1 to " << n << " = " << sum << "\n";

    cout << "\nACTIVITY 2 - Skip multiples of 3; stop at 15\n";
    for (int i = 1; i <= 20; ++i) {
        if (i == 15) { cout << "Breaking at 15!\n"; break; }
        if (i % 3 == 0) continue;
        cout << i << ' ';
    }
    cout << "\n\nACTIVITY 3A - while validation\nEnter a positive number: ";
    int number; if (!(cin >> number)) return 1;
    while (number <= 0) { cout << "Invalid. Try again: "; if (!(cin >> number)) return 1; }
    cout << "Accepted: " << number << "\n";

    cout << "ACTIVITY 3B - do-while validation\n";
    do { cout << "Enter a positive number: "; if (!(cin >> number)) return 1; if (number <= 0) cout << "Invalid. "; }
    while (number <= 0);
    cout << "Accepted: " << number << "\n\n";

    cout << "ACTIVITY 4 - Multiplication table (1 to 10)\n    ";
    for (int col = 1; col <= 10; ++col) cout << setw(4) << col;
    cout << "\n" << string(44, '-') << '\n';
    for (int row = 1; row <= 10; ++row) {
        cout << setw(3) << row << '|';
        for (int col = 1; col <= 10; ++col) cout << setw(4) << row * col;
        cout << '\n';
    }
    cout << "Challenge table 1 to 5:\n";
    for (int row = 1; row <= 5; ++row) { for (int col = 1; col <= 5; ++col) cout << setw(4) << row * col; cout << '\n'; }
    return 0;
}
