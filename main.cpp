#include <iostream>
#include <unistd.h>
using namespace std;


int main() {

  //Creating a 4*4 matrix for the game
  int matrix[4][4];

  //Setting the matrix to 0
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      matrix[i][j] = 0;
    }
  }

  //Get a random index of the grid after a user input, then check to see if it is empty to add a 2
  while(true){
    int randomx = rand() % 5;
    int randomy = rand() % 5;
    if(matrix[randomx][randomy] == 0){
      matrix[randomx][randomy] = 2;
    }

//Me just printing it out to see if it works
    for(int i = 0 ; i < 4; i++){
      for(int j = 0; j < 4; j++){
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    sleep(2);
    cout << endl;
  }
  return 0;
}
