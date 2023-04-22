#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Class to handle the game
class Game {
private:
    int level; // Game level
    int guessCount; // Number of guesses left
    int guessNumber; // Number to guess
    int prize; // Winning prize
    vector<int> guessList; // List of guesses made by the player

public:
    Game(int level) {
        this->level = level;
        guessCount = 3 + level;
        guessNumber = rand() % (level * 10) + 1;
        prize = 50 * level;
    }

    // Function to play the game
    void play() {
        int guess;

        cout << "\nGuess a number between 1 and " << level * 10 << "." << endl;

        while (guessCount > 0) {
            cout << "\nYou have " << guessCount << " guesses left." << endl;
            cout << "Enter your guess: ";
            cin >> guess;

            // Check if the guess is valid
            if (guess < 1 || guess > level * 10) {
                cout << "Invalid guess. Please try again." << endl;
                continue;
            }

            // Check if the guess has already been made
            if (find(guessList.begin(), guessList.end(), guess) != guessList.end()) {
                cout << "You have already guessed " << guess << ". Please try again." << endl;
                continue;
            }

            guessCount--;
            guessList.push_back(guess);

            if (guess == guessNumber) {
                cout << "\nCongratulations! You have won " << prize << " dollars!" << endl;
                return;
            }
            else if (guess < guessNumber) {
                cout << "Your guess is too low." << endl;
            }
            else {
                cout << "Your guess is too high." << endl;
            }
        }

        cout << "\nSorry, you have run out of guesses. The number was " << guessNumber << "." << endl;
    }
};

int main() {
    srand(time(NULL));

    cout << "Welcome to the Casino Number Guessing Game!" << endl;

    int level;

    do {
        cout << "\nPlease select a game level (1-5): ";
        cin >> level;
    } while (level < 1 || level > 5);

    Game game(level);

    char choice;

    do {
        game.play();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for playing!" << endl;

    return 0;
}
