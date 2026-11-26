// About Me - Week 1 interactive C++ practical
// Includes the six required questions and the four student challenges.

#include <iostream>
#include <string>

using namespace std;

string ask_question(const string& prompt) {
    string answer;
    cout << prompt;
    getline(cin, answer);
    return answer;
}

int main() {
    string name;
    string course;
    string hobby;
    string reason;
    string expectation;
    string definition;
    string favourite_food;
    string dream_job;

    cout << "==============================================\n";
    cout << "          WELCOME TO MY FIRST PROGRAM         \n";
    cout << "==============================================\n\n";

    do {
        name = ask_question("1. What is your name? ");
        if (name.find_first_not_of(" \t\r\n") == string::npos) {
            cout << "You didn't enter a name! Please try again.\n";
        }
    } while (name.find_first_not_of(" \t\r\n") == string::npos);

    course = ask_question("2. What course are you doing? (BBIT/BCS): ");
    hobby = ask_question("3. What is your hobby? ");
    reason = ask_question("4. Why did you choose this course? ");
    expectation = ask_question("5. What do you expect to learn in programming? ");
    definition = ask_question("6. In your own words, what is programming? ");

    // Challenges 1 and 2: add two questions and validate the name above.
    favourite_food = ask_question("7. What is your favourite food? ");
    dream_job = ask_question("8. What is your dream job? ");

    cout << "\n+----------------------------------------------+\n";
    cout << "|              YOUR PROFILE SUMMARY           |\n";
    cout << "+----------------------------------------------+\n";
    cout << "| Name:           " << name << '\n';
    cout << "| Course:         " << course << '\n';
    cout << "| Hobby:          " << hobby << '\n';
    cout << "| Reason:         " << reason << '\n';
    cout << "| Expectation:    " << expectation << '\n';
    cout << "| Programming is: " << definition << '\n';
    cout << "| Favourite food: " << favourite_food << '\n';
    cout << "| Dream job:      " << dream_job << '\n';
    cout << "+----------------------------------------------+\n";

    // Challenge 3: personalize the closing message. Challenge 4: format neatly.
    cout << "\nGreat job, " << name
         << "! You are on your way to becoming a programmer!\n";
    cout << "Thank you for completing this practical.\n";

    return 0;
}
