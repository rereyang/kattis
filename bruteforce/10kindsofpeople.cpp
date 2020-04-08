#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<vector<int>>& board, int i, int j, int iden, vector<vector<int>>& ident, int marker) {
    if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1 || ident[i][j] != -1 || board[i][j] != marker)
        return;
    ident[i][j] = iden;
    dfs(board, i - 1, j, iden, ident, marker);
    dfs(board, i, j - 1, iden, ident, marker);
    dfs(board, i + 1, j, iden, ident, marker);
    dfs(board, i, j + 1, iden, ident, marker);
}

int main() {
    int r, c, n, iden = 0;
    cin >> r >> c;
    vector<vector<int>> board(r);
    vector<vector<int>> ident(r, vector<int> (c, -1));
    vector<int> decbin;
    string input;
    for (int i = 0; i < r; i++) {
        cin >> input;
        for (auto ch: input) {
            board[i].push_back(ch - '0');
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (ident[i][j] == -1) {
                dfs(board, i, j, iden, ident, board[i][j]);
                decbin.push_back(board[i][j]);
                iden += 1;
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (ident[r1 - 1][c1 - 1] == ident[r2 - 1][c2 - 1]) {
            if (decbin[ident[r1 - 1][c1 - 1]] == 1) {
                cout << "decimal" << endl;
            } else {
                cout << "binary" << endl;
            }
        } else {
            cout << "neither" << endl;
        }
    }
    return 0;
}