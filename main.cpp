#include <iostream>
#include <unistd.h>
using namespace std;
#include <string>


int main() {
  bool lose = false;
  string direction = "";
  int randomx = 1;
  int randomy = 1;

  //Creating a 4*4 matrix for the game
  int matrix[4][4];


  //Setting the matrix to 0
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(matrix[i][j] != 0){
        matrix[i][j] = 0;
      }
    }
  }

  //Get a random index of the grid after a user input, then check to see if it is empty to add a 2

  while(lose == false){
    bool full = true;
    cout << "Enter a direction: " << endl;
    cin >> direction;

    //moving up
    if(direction == "w"){
      cout << "You are going up!" << endl;
      for(int i = 3; i > 0; i--){
        for(int j = 0; j < 4; j++){
          if (matrix[i][j] != 0 && matrix[i-1][j] == 0){
            matrix[i-1][j] = matrix[i][j];
            matrix[i][j] = 0;
          }
          else if(matrix[i-1][j] == matrix[i][j]){
            matrix[i-1][j] = matrix[i][j] * 2;
            matrix[i][j] = 0;
          } 
        }
      }
    }
      
    //moving down
    else if (direction == "s"){
      cout << "You are going down!" << endl;
      for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
          if (matrix[i][j] != 0 && matrix[i+1][j] == 0){
            matrix[i+1][j] = matrix[i][j];
            matrix[i][j] = 0;
          }
          else if (matrix[i+1][j] == matrix[i][j]){
            matrix[i+1][j] = matrix[i][j] * 2;
            matrix[i][j] = 0;
          }
        }
      }
    }
      
    //move right
    else if (direction == "d"){
      cout << "You are going right!" << endl;
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
          if (matrix[i][j] != 0 && matrix[i][j+1] == 0){
            matrix[i][j+1] = matrix[i][j];
            matrix[i][j] = 0;
          }
          else if (matrix[i][j+1] == matrix[i][j]){
            matrix[i][j+1] = matrix[i][j] * 2;
            matrix[i][j] = 0;
          }
        }
      }
    }

    //moving left
    else if (direction == "a"){
      cout << "You are going left!" << endl;
      for (int i = 0; i < 4; i++){
        for (int j = 3; j > 0 ; j--){
          if (matrix[i][j] != 0 && matrix[i][j-1] == 0){
            matrix[i][j-1] = matrix[i][j];
            matrix[i][j] = 0;
          }
          else if (matrix[i][j-1] == matrix[i][j]){
            matrix[i][j-1] = matrix[i][j] * 2;
            matrix[i][j] = 0;
          }
        }
      }
    }

    //Checks to see if a random block is empty and if it is, then add a 2
    randomx = rand() % 4;
    randomy = rand() % 4;
    while (matrix[randomx][randomy] != 0){
      randomx = rand() % 4;
      randomy = rand() % 4;
    }
    matrix[randomx][randomy] = 2;


//Me just printing out the array to see if it works
    for(int i = 0 ; i < 4; i++){
      for(int j = 0; j < 4; j++){
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;

//Checking the array to see if there is an empty spot
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        if(matrix[i][j] == 0){
          full = false;
        }
      }
    }

//If no empty spot, then array is full and you lose
    if(full == true){
      lose = true;
      cout << "You lose!" << endl;
    }
    
  }
  return 0;
}
