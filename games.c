#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
void resetboard();
void printboard();
int checkFreeSpaces();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);
int main()
{
    char winner = ' ';
    char response = ' ';
    do
    {
        winner = ' ';
        response = ' ';
        resetboard();
        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printboard();
            playermove();
            winner = checkwinner();

            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
            computermove();
            winner = checkwinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }
        printboard();
        printwinner(winner);
        printf("\n would you like to continue(Y/N)");
        scanf("%c", &response);
        response = toupper(response);

    } while (response == 'Y');
    printf("thanks for playing");
    return 0;
}

void resetboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printboard()
{
    printf("%c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freespaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}

void playermove()
{
    int x;
    int y;
    do
    {
        printf("enter row#(1-3)\n");
        scanf("%d", &x);
        x--;
        printf("enter column#(1-3\n");
        scanf("%d", &y);
        y--;
        if (board[x][y] != ' ')
        {
            printf("invalid move\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

char checkwinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

void printwinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("you win");
    }
    else if (winner == COMPUTER)
    {
        printf("you lost!");
    }
    else
    {
        printf("its a tie");
    }
}

void computermove()
{
    srand(time(0));
    int x;
    int y;
    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
    {
        printwinner(' ');
    }
}
