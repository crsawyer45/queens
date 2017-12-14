#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <cstdlib>

using namespace std;
int board[40][40];
int columns[40];

bool checkDiag(int r, int c) {
  for (int i = r; i >= 0; i--){

    if ((c-(r-i) >= 0) && board[i][c-(r-i)] == 1) {return false;}
    if ((c+(r-i)) && board[i][c+(r-i)] == 1) {return false;}
  }
  return true;
}
bool checkCol(int c) {
  if (columns[c] == 1) {return false;}
  else {return true;}
}
void placeQueen(int size, int &solutions, int row){

  // if we are at the end of the board, then add one to the total number of solutions
  if (size == 0) {return;}
  if (row == size) {solutions = solutions + 1; return;}
  else {
    bool didPlace = false;

    // otherwise, place a queen in every spot in the row
    for (int i = 0; i < size; i++){
      // check if you can place a queen, if not then return
      if (checkCol(i) && checkDiag(row, i)) {
        board[row][i] = 1; columns[i] = 1; didPlace = true;
      }
      else {continue;}

      placeQueen(size, solutions, row + 1);

      // remove the queen from the spot so it can be placed in the next column
      board[row][i] = 0;
      columns[i] = 0;
      if (!didPlace && i == size -1) {return;}
    }
  }
}

int main(int argc, char **argv) {

  int size = atoi(argv[1]);
  int solutions = 0;
  placeQueen(size, solutions, 0);


  if (solutions != 1) {cout << "There are: " << solutions << " solutions" << endl;}
  else {cout << "There is: " << solutions << " solution" << endl;}

return 0;
}
