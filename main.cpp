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

  matrix[3][3] = 12345;
  //Get a random index of the grid after a user input, then check to see if it is empty to add a 2

  while(lose == false){
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
    
    
    while (matrix[randomx][randomy] != 0){
      randomx = rand() % 4;
      randomy = rand() % 4;
    }
    matrix[randomx][randomy] = 2;
      

//Me just printing it out to see if it works
    for(int i = 0 ; i < 4; i++){
      for(int j = 0; j < 4; j++){
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
