#include <stdio.h>

#include<stdlib.h>


char GridVal(int i)
{
    switch(i)
    {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void draw(int b[9])
{
    printf(" %c | %c | %c\n",GridVal(b[0]),GridVal(b[1]),GridVal(b[2]));
    printf("-----------\n");
    printf(" %c | %c | %c\n",GridVal(b[3]),GridVal(b[4]),GridVal(b[5]));
    printf("-----------\n");
    printf(" %c | %c | %c\n",GridVal(b[6]),GridVal(b[7]),GridVal(b[8]));
}

int CheckWin(const int board[9])
{
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i)
    {
        if(board[wins[i][0]] != 0 && board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])

            return board[wins[i][2]];
    }
    return 0;
}

int CheckMove(int board[9], int player)
{
    int winner = CheckWin(board);
    if(winner != 0)
    {
        return (winner*player);
    }

    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i)
    {
        if(board[i] == 0)
        {
            board[i] = player;
            int thisScore = -CheckMove(board, player*-1);
            if(thisScore > score)
            {
                score = thisScore;
                move = i;
            }
            board[i] = 0;
        }
    }
    if(move == -1) return 0;
    return score;
}

void computerMove(int board[9])
{
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i)
    {
        if(board[i] == 0)
        {
            board[i] = 1;
            int tempScore = -CheckMove(board, -1);
            board[i] = 0;
            if(tempScore > score)
            {
                score = tempScore;
                move = i;
            }
        }
    }
    board[move] = 1;
}

void PlayerMove(int board[9])
{
    int move = 0;
    do
    {
        printf("\nInput move ([0-8]): ");
        scanf("%d", &move);
        printf("\n");
    }
    while (move >= 9 || move < 0 && board[move] == 0);
    if(board[move] != 0){
        printf("wrong input\n");
        PlayerMove(board);
    }
    else{
        board[move] = -1;
    }
}

int Game() {
    int board[9] = {0,0,0,0,0,0,0,0,0};
    printf("                \tHello");

    printf("    \nWelcome To Tik-tok-toe Game You are playing with a robot!!");

    printf("\n\nRobot: O, You: X\nIf you want play 1st press 1 or press 2 to play 2nd. ");

    int player=0;

    scanf("%d",&player);

    printf("\n");
    unsigned turn;
    for(turn = 0; turn < 9 && CheckWin(board) == 0; ++turn)
    {
        if((turn+player) % 2 == 0)
            computerMove(board);
        else {
            draw(board);
            PlayerMove(board);
        }
    }
    switch(CheckWin(board)) {
        case 0:
            printf("\nGame has Draw!.\n");
            break;
        case 1:
            draw(board);
            printf("\nYou Have lost The game.\n");
            break;
        case -1:
            printf("\nYou Have won the Game!!\n");
            break;
    }
}

int main()
{
    char loop = 'y';
    while(loop == 'Y' || loop == 'y')
    {
        Game();
        printf("If you want to play again press y else exit the game : ");
        printf("%c\n",loop);
        printf("\n");
    }
    printf("Thanks for playing Hope you have enjoyed!!");

    return 0;
}