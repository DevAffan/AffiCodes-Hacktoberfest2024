#include <stdio.h>

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//board print 
void printBoard() {
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |      |   \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |      |   \n");
    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |      |   \n");
    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("     |      |   \n");
    printf("\n\n");
}

int checkWin() {
    int winning_combinations[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}             // Diagonals
    };

    for(int i = 0; i < 8; i++) {
        if(board[winning_combinations[i][0]] == board[winning_combinations[i][1]] &&
           board[winning_combinations[i][1]] == board[winning_combinations[i][2]]) {
            return 1;
        }
    }

    for(int i = 1; i <= 9; i++) {
        if(board[i] != 'X' && board[i] != 'O') {
            return -1; // Game is still running
        }
    }

    return 0; // Game is a draw
}

int main() {
    int player = 1, input, status = -1;
    char mark;
    
    while(status == -1) {
        printBoard();
        mark = (player % 2) ? 'X' : 'O';  // Automatically assign 'X' or 'O' based on player turn

        printf("Enter the position (1-9) for player %d: ", (player % 2) ? 1 : 2);
        scanf("%d", &input);

        // check input
        if(input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O') {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        board[input] = mark;
        status = checkWin();
        player++;
    }

    printBoard();

    if(status == 1) {
        printf("==> Player %d wins the match.\n", --player);
    } else {
        printf("==> The game is a draw.\n");
    }

    return 0;
}
