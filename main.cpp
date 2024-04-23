#include <iomanip> // For std::setw
#include <iostream>
#include <unistd.h>
using namespace std;
#include <string>

int main() {
  //Initializing variables
  bool lose = false;
  string direction = "";
  int randomx = 1;
  int randomy = 1;
  int score = 0;

  // Creating a 4*4 matrix for the game
  int matrix[4][4];

  // Setting the matrix to 0
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (matrix[i][j] != 0) {
        matrix[i][j] = 0;
      }
    }
  }

  cout << "Instructions: The objective of the game is to slide numbered tiles "
          "on a grid to combine them to create a tile with the number 2048. "
          "Use the WASD keys to move the tiles. Press Q to quit the game."
       << endl;

  //GAME LOOP STARTS HERE
  // Get a random index of the grid after a user input, then check to see if it
  // is empty to add a 2

  while (lose == false){
    bool full = true;
    cout << "Enter a direction or Quit: " << endl;
    cin >> direction;

    // Check if the player wants to quit the game
    if (direction == "Q") {
      cout << "You lost!" << endl;
      break;
    }
    // moving up
    if (direction == "w") {
      cout << "You are going up!" << endl;
      for (int i = 3; i > 0; i--) {
        for (int j = 0; j < 4; j++) {
          if (matrix[i][j] != 0 && matrix[i - 1][j] == 0) {
            matrix[i - 1][j] = matrix[i][j];
            matrix[i][j] = 0;
          } else if (matrix[i - 1][j] == matrix[i][j]) {
            matrix[i - 1][j] = matrix[i][j] * 2;
            score += matrix[i][j]*2;
            matrix[i][j] = 0;
          }
        }
      }
    }

    // moving down
    else if (direction == "s") {
      cout << "You are going down!" << endl;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
          if (matrix[i][j] != 0 && matrix[i + 1][j] == 0) {
            matrix[i + 1][j] = matrix[i][j];
            matrix[i][j] = 0;
          } else if (matrix[i + 1][j] == matrix[i][j]) {
            matrix[i + 1][j] = matrix[i][j] * 2;
            score += matrix[i][j]*2;
            matrix[i][j] = 0;
          }
        }
      }
    }

    // move right
    else if (direction == "d") {
      cout << "You are going right!" << endl;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
          if (matrix[i][j] != 0 && matrix[i][j + 1] == 0) {
            matrix[i][j + 1] = matrix[i][j];
            matrix[i][j] = 0;
          } else if (matrix[i][j + 1] == matrix[i][j]) {
            matrix[i][j + 1] = matrix[i][j] * 2;
            score += matrix[i][j]*2;
            matrix[i][j] = 0;
          }
        }
      }
    }

    // moving left
    else if (direction == "a") {
      cout << "You are going left!" << endl;
      for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
          if (matrix[i][j] != 0 && matrix[i][j - 1] == 0) {
            matrix[i][j - 1] = matrix[i][j];
            matrix[i][j] = 0;
          } else if (matrix[i][j - 1] == matrix[i][j]) {
            matrix[i][j - 1] = matrix[i][j] * 2;
            score += matrix[i][j]*2;
            matrix[i][j] = 0;
          }
        }
      }
    }

    // Generate a random x and y coordinate
    // Checks to see if a random block is empty and if it is, then add a 2
    // Otherwise find a different index until it gets an empty one
    randomx = rand() % 4;
    randomy = rand() % 4;
    while (matrix[randomx][randomy] != 0) {
      randomx = rand() % 4;
      randomy = rand() % 4;
    }
    matrix[randomx][randomy] = 2;

    // Printing out the array with even spacing
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cout << setw(5) << matrix[i][j];
      }
      cout << endl;
    }
    cout << endl;

    // //Me just printing out the array to see if it works. NOT NEEDED ANYMORE!
    //     for(int i = 0 ; i < 4; i++){
    //       for(int j = 0; j < 4; j++){
    //         cout << matrix[i][j] << " ";
    //       }
    //       cout << endl;
    //     }
    //     cout << endl;

    // Checking the array to see if there is an empty spot
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (matrix[i][j] == 0) {
          full = false;
        }
      }
    }

    // If no empty spot, then array is full and you lose
    if (full == true) {
      lose = true;
      cout << "You lose!" << endl;
    }
    cout << "Score: " << score << endl;
  }
  return 0;
}
