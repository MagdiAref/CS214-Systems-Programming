/*                                                                                                                                                                                     
This program is a game of a player and monster moving on a 2D grid. The player has a goal to reach. The monster wants to reach the player.                                             
In each turn, the player moves one square, then the monster moves towards the player. If either reaches their target, the game ends immediately. If the player reaches the goal, it pr\
ints “player wins!”. If the monster reaches the player, it prints “monster wins!”.                                                                                                     
The player’s moves (N, W, S, or E) are read from stdin, one per line. If the move is invalid (e.g., the player tries to move off the board, print “invalid move” and read a new move).\
 If the player intentionally moves into the monster’s square, it counts as the monster winning.                                                                                        
On its turn, the monster considers the horizontal and vertical distances to reach the player and moves to reduce the larger of these two. If they’re the same, the monster chooses the\
 vertical direction. Its move should be printed, e.g., “monster moves E”.                                                                                                              
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//#define MAX 25                                                                                                                                                                       

int main(int argc, char* argv[]){

  int row = atoi(argv[1]);
  int col = atoi(argv[2]);
  int playX = atoi(argv[3]);
  int playY = atoi(argv[4]);
  int goalX = atoi(argv[5]);
  int goalY = atoi(argv[6]);
  int monX = atoi(argv[7]);
  int monY = atoi(argv[8]);
  char gameBoard[row][col];                                                                                                                                        
  //char transpose[MAX][MAX];                                                                                                                                                          


  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      gameBoard[i][j] = '.';
      gameBoard[playX][playY] = 'P';
      gameBoard[goalX][goalY] = 'G';
      gameBoard[monX][monY] = 'M';
      printf("%c ", gameBoard[i][j]);
    }
    printf("\n");
  }
  char choice;

  scanf("%c", &choice);

 while (gameBoard[playX][playY] != gameBoard[monX][monY] || gameBoard[playX][playY] != gameBoard[goalX][goalY]){
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
    if (choice == 'N'){
      gameBoard[playX][playY + 1] = 'P';
      gameBoard[goalX][goalY] = 'G';
      gameBoard[monX][monY] = 'M';
      printf("%c ", gameBoard[i][j]);
    }
    else if (choice == 'E'){
      gameBoard[playX + 1][playY] = 'P';
      gameBoard[goalX][goalY] = 'G';
      gameBoard[monX][monY] = 'M';
      printf("%c ", gameBoard[i][j]);
    }
    else if (choice == 'W'){
      gameBoard[playX - 1][playY] = 'P';
      gameBoard[goalX][goalY] = 'G';
      gameBoard[monX][monY] = 'M';
      printf("%c ", gameBoard[i][j]);
    }
    else if (choice == 'S'){
      gameBoard[playX][playY - 1] = 'P';
      gameBoard[goalX][goalY] = 'G';
      gameBoard[monX][monY] = 'M';
      printf("%c ", gameBoard[i][j]);
    }
    }
    printf("\n");
    }
 }
  if (gameBoard[playX][playY] == gameBoard[monX][monY]){
    printf("monster wins!");
  }
  else if (gameBoard[playX][playY] == gameBoard[goalX][goalY]){
    printf("player wins!");
  }
  return 0;
}
