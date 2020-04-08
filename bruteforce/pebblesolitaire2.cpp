#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int global_min = 23;
unordered_set<string> map;
void dfs(string& board) {
    if (map.count(string (board)) > 0) 
        return;
    bool can_move = false;
    for (int i = 0; i < 21; i++) {
        if (board.substr(i, 3) == "-oo") {
            board[i] = 'o';
            board[i + 1] = '-';
            board[i + 2] = '-';
            dfs(board);
            board[i] = '-';
            board[i + 1] = 'o';
            board[i + 2] = 'o';
            can_move = true;
        }
        if (board.substr(i, 3) == "oo-") {
            board[i] = '-';
            board[i + 1] = '-';
            board[i + 2] = 'o';
            dfs(board);
            board[i] = 'o';
            board[i + 1] = 'o';
            board[i + 2] = '-';
            can_move = true;
        }
    }
    map.emplace(string (board));
    int pcount = 0;
    if (!can_move) {
        for (int i = 0; i <= 22; i++) {
            if (board[i] == 'o') {
                pcount += 1;
            }
        }
        global_min = min(global_min, pcount);
    }

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        global_min = 23;
        dfs(input);
        cout << global_min << endl;
    }
    return 0;
}