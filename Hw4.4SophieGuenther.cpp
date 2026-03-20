#include <iostream>
using namespace std;

bool gameWon = false;

bool checkIfValid(char arr[3][3], char where) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == where) {
                return true;
            }
        }
    }
    return false;
}

bool checkGameWon(char board[3][3]){
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && 
            board[i][1] == board[i][2] &&
            (board[i][0] == 'X' || board[i][0] == 'O')) {
            return true;
        }
    }

    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && 
            board[1][j] == board[2][j] &&
            (board[0][j] == 'X' || board[0][j] == 'O')) {
            return true;
        }
    }

    // diagonals
    if (board[0][0] == board[1][1] && 
        board[1][1] == board[2][2] &&
        (board[0][0] == 'X' || board[0][0] == 'O')) {
        return true;
    }

    if (board[0][2] == board[1][1] && 
        board[1][1] == board[2][0] &&
        (board[0][2] == 'X' || board[0][2] == 'O')) {
        return true;
    }

    return false;
}

int main() {
    char playAgain = 'Y';
    int placement; // changed to int
    int row = -1;
    int column = -1;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1 is X and Player 2 is O." << endl;

    while (playAgain == 'Y' || playAgain == 'y') {

        char game[3][3] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
        };

        cout << "The starting board is:" << endl;

        // print board
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                cout << game[j][k] << " ";
            }
            cout << endl;
        }

        for(int i=0; i<9; i++){

            // PLAYER 1
            if(i % 2 == 0){
                cout << "Player 1's turn (X), select position (1-9) -> ";
                cin >> placement;

                //check placement validity
                while (placement < 1 || placement > 9 || !checkIfValid(game, placement + '0')) {
                    cout << "Invalid placement. Try again -> ";
                    cin >> placement;
                }

                //change placement to character for board
                char placementChar = placement + '0';

                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        if (game[r][c] == placementChar) {
                            row = r;
                            column = c;
                        }
                    }
                }

                game[row][column] = 'X';

                // print board
                for(int j=0; j<3; j++){
                    for(int k=0; k<3; k++){
                        cout << game[j][k] << " ";
                    }
                    cout << endl;
                }

                if(checkGameWon(game)){
                    cout << "Congrats Player1 you won!" << endl;
                    cout << "Would you like to play again? (Y or N) -> ";
                    cin >> playAgain;
                    break;
                }
            }

            // PLAYER 2
            else{
                cout << "Player 2's turn (O), select position (1-9) -> ";
                cin >> placement;

                while (placement < 1 || placement > 9 || !checkIfValid(game, placement + '0')) {
                    cout << "Invalid placement. Try again -> ";
                    cin >> placement;
                }

                char placementChar = placement + '0';

                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        if (game[r][c] == placementChar) {
                            row = r;
                            column = c;
                        }
                    }
                }

                game[row][column] = 'O';

                // print board
                for(int j=0; j<3; j++){
                    for(int k=0; k<3; k++){
                        cout << game[j][k] << " ";
                    }
                    cout << endl;
                }

                if(checkGameWon(game)){
                    cout << "Congrats Player2 you won!" << endl;
                    cout << "Would you like to play again? (Y or N) -> ";
                    cin >> playAgain;
                    break;
                }
            }

            // tie
            if(i == 8){
                cout << "Tie! Would you like to play again (Y or N) -> ";
                cin >> playAgain;
            }
        }
    }

    return 0;
}