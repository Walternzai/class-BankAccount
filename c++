#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void boarder(char *space);
void playerMove(char *space, char player);
void computerM(char *space, char computer);
bool check_winner(char *space, char player, char computer);
bool checkTie(char *space);

int main() {
    char space[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool run = true;
    boarder(space);
    
    while (run) {
        playerMove(space, player);
        boarder(space);
        if (check_winner(space, player, computer)) {
            run = false;
            break;
        } else if (checkTie(space)) {
            run = false;
            break;
        }
        computerM(space, computer);
        boarder(space);
        if (check_winner(space, player, computer)) {
            run = false;
            break;
        } else if (checkTie(space)) {
            run = false;
            break;
        }
    }
    
    cout << "Thanks for playing!\n";
    return 0;
}

void boarder(char *space) {
    cout << '\n';
    cout << " | | " << '\n';
    cout << " " << space[0] << " | " << space[1] << " | " << space[2] << '\n';
    cout << " | | " << '\n';
    cout << "___|___|___" << '\n';
    cout << " | | " << '\n';
    cout << " " << space[3] << " | " << space[4] << " | " << space[5] << '\n';
    cout << " | | " << '\n';
    cout << "___|___|___" << '\n';
    cout << " " << space[6] << " | " << space[7] << " | " << space[8] << '\n';
    cout << " | | " << '\n';
    cout << " | | " << '\n';
}

void playerMove(char *space, char player) {
    int num;
    do {
        cout << "Enter a number between {1-9} to place the spot of " << player << " : ";
        cin >> num;
        num--;
        if (space[num] == ' ') {
            space[num] = player;
            break;
        } else {
            cout << "Spot already taken, try another number." << endl;
        }
    } while (num < 0 || num >= 9);
}

void computerM(char *space, char computer) {
    int num;
    srand(time(0));
    while (true) {
        num = rand() % 9;
        if (space[num] == ' ') {
            space[num] = computer;
            break;
        }
    }
}

bool check_winner(char *space, char player, char computer) {
    char winner = ' ';
    if ((space[0] != ' ') && (space[0] == space[1]) && (space[1] == space[2])) {
        winner = space[0];
    } else if ((space[3] != ' ') && (space[3] == space[4]) && (space[4] == space[5])) {
        winner = space[3];
    } else if ((space[6] != ' ') && (space[6] == space[7]) && (space[7] == space[8])) {
        winner = space[6];
    } else if ((space[0] != ' ') && (space[0] == space[3]) && (space[3] == space[6])) {
        winner = space[0];
    } else if ((space[1] != ' ') && (space[1] == space[4]) && (space[4] == space[7])) {
        winner = space[1];
    } else if ((space[2] != ' ') && (space[2] == space[5]) && (space[5] == space[8])) {
        winner = space[2];
    } else if ((space[0] != ' ') && (space[0] == space[4]) && (space[4] == space[8])) {
        winner = space[0];
    } else if ((space[2] != ' ') && (space[2] == space[4]) && (space[4] == space[6])) {
        winner = space[2];
    }

    if (winner == player) {
        cout << "YOU WIN!\n";
        return true;
    } else if (winner == computer) {
        cout << "YOU LOSE!\n";
        return true;
    } else {
        return false;
    }
}

bool checkTie(char *space) {
    for (int i = 0; i < 9; i++) {
        if (space[i] == ' ') {
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}
