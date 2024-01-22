#include "hangman_functions.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  greet();

  // change this so the game randomly takes words from a file instead of a set
  // code word
  string codeword = "aaronwashere";
  string answer = "____________";

  int misses = 0;
  vector<char> incorrectGuess;
  bool guess = false;
  char letter;

  // keep the game running until the player wins or loses
  while (answer != codeword && misses < 7) {
    display_misses(misses);
    display_status(incorrectGuess, answer);

    cout << "\n\nPlease enter your guess: ";
    cin >> letter;

    // checks if the guess made is correct or not
    for (int i = 0; i < codeword.length(); i++) {
      if (letter == codeword[i]) {
        answer[i] = letter;
        guess = true;
      }
    }
    // add an else if statement to see if the player has already guessed a
    // letter already and don't penalize them for it
    if (guess) {
      cout << "\nCorrect!\n";
    } else {
      std::cout
          << "\nIncorrect! Another portion of Mr.Hangman has been drawn.\n";
      incorrectGuess.push_back(letter);
      misses++;
    }
    guess = false;
  }

  end_game(answer, codeword);
  return 0;
}