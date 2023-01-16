#include <stdio.h>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void displayBoard() {
    printf("\n");
    printf("    |   |   \n");
    printf("  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("----+---+----\n");
    printf("  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("----+---+----\n");
    printf("  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("    |   |   \n");
}

//conditions for win horizontal
//if horizontal row [i][0],[i][1] & [i][2] == player// wins
//if vertical row [0][j],[1][j] & [2][j] == player// wins
// if diagonal [0][0]& [1][1] & [2][2] +++++++ [2][0] & [1][1] & [0][2]

int drawCheck() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int winCheck( char player){

int i;

for (i = 0 ; i < 3 ; i++){
    if ( board[i][0]== player & board[i][1] == player & board[i][2] == player )
        {
           return 1;
        }
}
// checks for similar player input in rows 
for (i = 0; i < 3 ; i++) {
    if (board[0][i]== player & board[1][i] == player & board[2][i] == player )
        {
            return 1;
        }
}
// checks for similar player input in columns
// the next will be special cases where diagonal wins are checked
// right diagonal and left diagonal
if ( board[0][0] == player & board[1][1] == player & board[2][2] == player)
    {
        return 1;
    }
if ( board [2][0] == player & board [1][1] == player  & board [0][2] == player)
    {
        return 1;
    }
return 0;
}



int main() {    
    int position;
    int gameOver = 0;
    char player = 'X';
    int turns = 0;
    displayBoard();
    while (!gameOver){
        printf(" Player %c turn \n", player);
        printf(" Player %c please enter a number from 1-9 where you want to claim your spot: ", player);
        //displayBoard();
        scanf("%d", &position);
        if (position >=1 && position <= 9) {
            int row = (position - 1) / 3;
            int col = (position - 1) % 3;
            if ( board[row][col] != 'X' && board[row][col] != 'O') {
                board [row][col] = player;
                turns ++;
                displayBoard();
                if (winCheck(player)){
                    printf("player %c wins! ", player);
                    gameOver = 1;
                    
                }
                if(turns == 9){
                printf("The game is a draw!");
                gameOver = 1;
                }
                if(drawCheck()){
                    printf("The game is a draw!");
                    gameOver = 1;
                    }
                else {
                    if (player == 'X'){
                        player = '0';}
                    else {
                        player = 'X';
                        }
                }
            }
            else
            {
                printf("Position already filled pick another number\n");
            }

        }else {
            printf( "you picked an invalid position, please pick another \n");
            }
        }
    return 0;
    }
// this is a test comment for a git push

    
