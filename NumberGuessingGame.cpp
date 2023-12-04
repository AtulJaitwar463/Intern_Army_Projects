#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int Attempts = 0;
    int MaximumAttempts = 8; // Maximum number of attempts the user has

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between 1 and 100. You have " << MaximumAttempts << " attempts to guess it.\n";

    do 
    {
        cout << "Enter your guess number: ";
        cin >> guess;
        Attempts++;

        if (guess == secretNumber) 
        {
            cout << "Congratulations! You have guessed Number  (" << secretNumber << ") correctly in " << Attempts << " attempts!\n";
            break;
        } 
        else if (guess < secretNumber) 
        {
            cout << "Too small!, Try again.\n";
        }
        else 
        {
            cout << "Too large!, Try again.\n";
        }

        if (Attempts == MaximumAttempts) 
        {
            cout << "Sorry, you've used all your attempts. The number I was thinking of is " << secretNumber << ". Better luck next time!\n";
            break;
        }
    } while (Attempts < MaximumAttempts);

    return 0;
}
