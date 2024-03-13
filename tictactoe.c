#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void ResetBoard();
void PrintBoard();
int CheckFreespaces();
void PlayerMove();
void ComputerMove();
char CheckWinner();
void PrintWinner(char);

int main(void)
{
    char winner = ' ';
    char response;
    
    do
    {
    winner = ' ';
    response = ' ';
    ResetBoard();

    while(winner == ' ' && CheckFreespaces() != 0)
    {
        PrintBoard();

        PlayerMove();
        winner = CheckWinner();
        if(winner != ' ' || CheckFreespaces() == 0)
        {
            break;

        }

          ComputerMove();
        winner = CheckWinner();
        if(winner != ' ' || CheckFreespaces() == 0)
        {
            break;

        }
    }

    PrintBoard();
    PrintWinner(winner);
    
    printf("\nWould you like to play again? (Y) or (N): ");
    scanf("%c" , &response);
    scanf("%c", &response);
    response = toupper(response);
        
    } while (response == 'Y');

    printf("Thanks for playing");
    

   

    return 0;
}


void ResetBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void PrintBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
      printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
      printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}
int CheckFreespaces()
{
    int freeSpaces = 9;

    for(int i = 0; i < 3; i++)
    {
           for(int j = 0; j < 3; j++)
           {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }

           }
    }
    return freeSpaces;
}
void PlayerMove()
{
    int x;
    int y;

    do
    {
    printf("Enter Row #(1-3):");
    scanf("%d", &x);
    x--;
     printf("Enter Column #(1-3):");
    scanf("%d", &y);
    y--;

    if(board[x][y] != ' ')
    {
        printf("Invalid Move\n");
    }
    else
    {
        board[x][y] = PLAYER;
        break;
    }

    } while (board[x][y] != ' ');
    
}
void ComputerMove()
{
    //create a seed apparently no idea wtf it means but les doo ittt!!!!!!!!!!!!!!!
    srand(time(0));
    int x;
    int y;

    if(CheckFreespaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board [x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else
    {
        PrintWinner(' ');
    }

}
char CheckWinner()
{
    //check rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];

        }
    }
    //check columns
     for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];

        }
    }
    //check diagonals
      if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];

        }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];

        }
        return ' ';


}
void PrintWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WINN!!");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOOSEE!!!");
    }
    else
    {
        printf("ITS A DRAWW!!");
    }
    

}