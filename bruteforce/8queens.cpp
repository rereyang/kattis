#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int board[15 * 2 + 8 * 2], qcount = 0;
    
    memset(board, 0, (46) * sizeof(int));
    string input;
    for (int i = 0; i < 8; i++) {
        cin >> input;
        for (int j = 0; j < 8; j++) {
            if (input[j] == '*') {
                qcount += 1;
                board[i] += 1;
                board[8 + j] += 1;
                board[8 * 2 + 7 + i - j] += 1;
                board[8 * 2 + 15 + j + i] += 1;
            }
        }
    }
    for (int i = 0; i < 46; i++) {
        if (board[i] > 1) {
            printf("invalid\n");
            return 0;
        }
    }
    if (qcount == 8)
        printf("valid\n");
    else
        printf("invalid\n");
    return 0;
}
