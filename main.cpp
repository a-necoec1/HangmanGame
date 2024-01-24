#include "hangman_functions.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random> // Include the <random> header
#include <vector>

using namespace std;

string chooseRandomWord(const string &filename) {
  vector<string> words;
  ifstream file(filename);

  if (file.is_open()) {
    string word;
    while (file >> word) {
      words.push_back(word);
    }
    file.close();
  } else {
    cerr << "Unable to open file: " << filename << endl;
    exit(EXIT_FAILURE);
  }

  // Use random_device to seed the random number generator
  random_device rd;
  mt19937 gen(rd());

  // Choose a random word from the vector
  uniform_int_distribution<> dis(0, words.size() - 1);
  return words[dis(gen)];
}

int main() {
  greet();

  // Specify the filename containing words (relative path)
  string filename = "wordfile.txt";
  string codeword = chooseRandomWord(filename);
  string answer(codeword.length(), '_');

  int misses = 0;
  vector<char> incorrectGuess;
  char letter;

  // Keep the game running until the player wins or loses
  while (answer != codeword && misses < 7) {
    display_misses(misses);
    display_status(incorrectGuess, answer);

    cout << "\n\nPlease enter your guess: ";
    cin >> letter;

    bool guess = false;

    // Checks if the guess made is correct or not
    for (int i = 0; i < codeword.length(); i++) {
      if (letter == codeword[i]) {
        answer[i] = letter;
        guess = true;
      }
    }

    if (guess) {
      cout << "\nCorrect!\n";
    } else if (std::find(incorrectGuess.begin(), incorrectGuess.end(),
                         letter) != incorrectGuess.end()) {
      cout << "\nYou've already guessed the letter '" << letter
           << "'. Try again.\n";
    } else {
      cout << "\nIncorrect! Another portion of Mr.Hangman has been drawn.\n";
      incorrectGuess.push_back(letter);
      misses++;
    }
  }

  end_game(answer, codeword);
  return 0;
}
