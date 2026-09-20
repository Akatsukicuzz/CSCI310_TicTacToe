// Players.c 
//This file contains the implementation of the player functions for a game.

#include <pthread.h> 
#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h>
#include <time.h>


//creating temporary global varibales for the board and the current player.
//need to implement a mutex lock to prevent race conditions when accessing the board and current player variables.

#define ROW 3
#define COL 3

//initializing the board to be "empty"
char board[ROW][COL] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};


// void test() 
// {
//     printf("%c\n", board[0][0]);
// };


//maybe make it so the player that starts is random each time the game is run. 

void Player1() 
{ 
    int row = 0; 
    int col = 0;

    while(true) 
    { 
        int full = 0; 

        for(int i=0; i<ROW; i++) 
        { 
            for(int j=0; j<COL; j++) 
            { 
                if(board[i][j] != ' ')
                {
                    full +=1;
                } 
                printf("board[%d][%d]:%c\n",i,j,board[i][j]);
            }
        }
        if (full == ROW * COL) 
        { 
            break; //game over, check if and who won. 
        }
        else 
        { 
            while(true)
            {
                row = rand() % ROW;
                col = rand() % COL;
                printf("row: %d, col: %d", row, col);
                //make sure the space is not already taken 
                if(board[row][col] == ' ')
                { 
                    board[row][col] = 'X';
                    break;
                }
                else if(board[row][col] != ' ')
                {
                    printf("The location was already populated\n");
                }
            }
        }


    }
    
};


void Player2()
{ 
    int row = 0; 
    int col = 0;

    while(true) 
    { 
        int full = 0; 

        for(int i=0; i<ROW; i++) 
        { 
            for(int j=0; j<COL; j++) 
            { 
                if(board[i][j] != ' ')
                {
                    full +=1;
                } 
                printf("board[%d][%d]:%c\n",i,j,board[i][j]);
            }
        }
        if (full == ROW * COL) 
        { 
            break; //game over, check if and who won. 
        }
        else 
        { 
            while(true)
            {
                row = rand() % ROW; //generate random location for the row location 
                col = rand() % COL; //generate random location for the col location 
                printf("row: %d, col: %d", row, col);
                
                //make sure the space is not already taken 
                if(board[row][col] == ' ')
                { 
                    board[row][col] = 'O';
                    break;
                }
                else if(board[row][col] != ' ')
                {
                    printf("The location was already populated\n");
                }
            }
        }

    }
};
