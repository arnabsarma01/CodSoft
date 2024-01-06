#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int secretNumber = rand() % 50 + 1;
    
    int guess;
    int attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    
    do {
        cout << "Enter your guess (1-50): ";
        cin >> guess;
        attempts++;
        
        if (guess < secretNumber) {
            cout << "You guessed it too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "You guessed it too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number, which is " << secretNumber << "." << endl;
            cout << "It took you " << attempts << " attempts to guess the number." << endl;
        }
    } while (guess != secretNumber);
    
    return 0;
}
