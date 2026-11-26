// Week 5: functions, parameters, scope, recursion, and geometry helpers.
#include <iostream>
#include <iomanip>
using namespace std;

int globalValue = 100;
void swapByValue(int a, int b) { int temp = a; a = b; b = temp; cout << "Inside pass-by-value: " << a << ' ' << b << '\n'; }
void swapByReference(int& a, int& b) { int temp = a; a = b; b = temp; }
int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }
int factorialTail(int n, int result = 1) { return n <= 1 ? result : factorialTail(n - 1, n * result); }
double areaCircle(double r) { return 3.141592653589793 * r * r; }
double areaRectangle(double l, double w) { return l * w; }
double areaTriangle(double b, double h) { return b * h / 2.0; }
double areaSquare(double side) { return side * side; }
double perimeterRectangle(double l, double w) { return 2 * (l + w); }

int main() {
    cout << "ACTIVITY 1 - Pass by value vs reference\n";
    int x = 5, y = 10; swapByValue(x, y); cout << "Originals after value call: " << x << ' ' << y << '\n';
    swapByReference(x, y); cout << "After reference fix: " << x << ' ' << y << "\n\n";
    cout << "ACTIVITY 2 - Scope\nGlobal value: " << globalValue << " (visible in main and functions)\n";
    { int localValue = 25; cout << "Block-local value: " << localValue << " (not available outside this block)\n\n"; }
    cout << "ACTIVITY 3 - Factorials for n=5\nSimple recursion: " << factorial(5) << "\nTail recursion: " << factorialTail(5) << "\n\n";
    cout << fixed << setprecision(2) << "ACTIVITY 4 - Geometry library (positive dimensions)\n";
    cout << "Circle area r=2: " << areaCircle(2) << "\nRectangle area 4x3: " << areaRectangle(4,3)
         << "\nTriangle area b=6 h=4: " << areaTriangle(6,4) << "\nSquare area side=3: " << areaSquare(3)
         << "\nRectangle perimeter 4x3: " << perimeterRectangle(4,3) << '\n';
    return 0;
}
