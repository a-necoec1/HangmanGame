#include "hangman_functions.h"
#include <iostream>
#include <vector>

using namespace std;

// define functions

void greet() {
  std::cout << "==========\n";
  std::cout << "Welcome to Hangman!\n";
  std::cout
      << "Save Mr. Hangman by guessing the word before he is fully drawn!\n";
  std::cout << "==========\n";
}

// display total amount of misses including mr. hangman
void display_misses(int misses) {
  if (misses == 0) {
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << " ========= \n";
  } else if (misses == 1) {
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "  O   | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << " ========= \n";
  } else if (misses == 2) {
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "  O   | \n";
    cout << "  |   | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << " ========= \n";
  } else if (misses == 3) {
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "  O   | \n";
    cout << " /|   | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << " ========= \n";
  } else if (misses == 4) {
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "  O   | \n";
    cout << " /|\\  | \n";
    cout << "      | \n";
    cout << "      | \n";
    cout << " ========= \n";
  } else if (misses == 5) {
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "  O   | \n";
    cout << " /|\\  | \n";
    cout << " /    | \n";
    cout << "      | \n";
    cout << " ========= \n";
  } else if (misses == 6) {
    cout << "  +---+ \n";
    cout << "  |   | \n";
    cout << "  O   | \n";
    cout << " /|\\  | \n";
    cout << " / \\  | \n";
    cout << "      | \n";
    cout << " ========= \n";
  }
}

// display current status of the game
void display_status(std::vector<char> incorrectGuess, std::string answer) {
  cout << "Incorrect Guesses: \n";

  for (int i = 0; i < incorrectGuess.size(); i++) {
    cout << incorrectGuess[i] << " ";
  }

  cout << "\nCodeword:\n";

  for (int i = 0; i < answer.length(); i++) {
    cout << answer[i] << " ";
  }
}

// trigger once the player gets either 7 misses or gets the word
void end_game(string answer, string codeword) {
  if (answer == codeword) {
    cout << "\nCongratulations! You saved Mr. Hangman from being hanged!\n";
    cout << "The word was: " << codeword << "\n";
    cout << "Thanks for playing!\n";
  } else {
    cout << "\nOh no! Mr. Hangman has been hanged! :(\n";
    cout << "Game over!";
  }
}