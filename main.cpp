#include "hangman_functions.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  greet();

  string codeword = "aaronwashere";
  string answer = "____________";

  int misses = 0;
  vector<char> incorrectGuess;
  bool guess = false;
  char letter;

  while (answer != codeword && misses < 7) {
    display_misses(misses);
    display_status(incorrectGuess, answer);
  }

  return 0;
}