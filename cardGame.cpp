#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct card
{
    string face;
    string suit;
};

void guessNum (const string&, vector<struct card>);
void guessSuit (const string&, vector<struct card>);

int main() {

    vector<string> faceValue{"Ace", "2", "3", "4", "5", "6","7", "8", "9", "10", "Jack", "Queen", "King"};
    vector<string> suits{"Hearts", "Clubs", "Diamonds", "Spades"};
    vector<struct card> deck(52);
    struct card temp;
    string guess;
    int menuInput = 0, deckControl = 0, timesPlayed = 0;
    char answer = 'y';
    bool finishGame = false;

    for (int a = 0; a < 13; a++)
    {
        for (int b = 0; b < 4; b++)
        {
            deck[deckControl].face = faceValue[a];
            deck[deckControl].suit = suits[b];
            deckControl++;
        }
    }


    // Loops game until user decides to finish program
    while (!finishGame) {
        // Resetting output after the first round is played
        if (timesPlayed > 0) {
            cout << endl << endl << endl << endl;
            cout << endl << endl << endl;
        }
        // Outputs menu options
        cout << "Card Guessing Game " << endl;
        cout << "====================" << endl;
        cout << "1) Guess the face value of the next card." << endl;
        cout << "2) Guess the suit of the next card." << endl;
        cout << "Enter your selection: ";
        cin >> menuInput;

        shuffle(deck.begin(), deck.end(), std::mt19937(std::random_device()()));

        switch (menuInput) {
            case 1:
                cout << "Guess the face value of the top card: ";
                cin >> guess;
                guessNum(guess, deck);
                timesPlayed++;
                break;
            case 2:
                cout << "Guess the suit of the top card: ";
                cin >> guess;
                guessSuit(guess, deck);
                timesPlayed++;
                break;
            default:
                cout << "* Error: Invalid Input *";
                cout << endl << endl;
                continue;
        }
        cout << endl << "Would you like to play again? (y/n)" << endl;
        cin >> answer;
        if (answer == 'n') {
            finishGame = true;
            cout << endl << "Thanks for playing!" << endl;
        }
    }
    return 0;
}

/* A function to pass in the guessed value and compare it to the
 * top card of the deck and output an appropriate message */
void guessNum(const string& guess, vector<struct card> deck)
{
   if (guess == deck.back().face)
       cout << "You won! The top card was the " << deck.back().face << " of "
            << deck.back().suit << endl;
   else
       cout << "Incorrect! The top card was the " << deck.back().face << " of "
            << deck.back().suit << endl;

} // End guessNum

/* A function to pass in the guessed suit and compare it to the top card of the
 * deck and output an appropriate message */
void guessSuit (const string& guess, vector<struct card> deck)
{
    if (guess == deck.back().suit)
        cout << "You won! The top card was the " << deck.back().face << " of "
             << deck.back().suit << endl;
    else
        cout << "Incorrect! The top card was the " << deck.back().face << " of "
             << deck.back().suit << endl;

} // End guessSuit
