// 11
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    vector<vector<char>> board;
    int count = 0;
    while (cin >> str) {
        board.push_back(vector<char> ());
        for (auto& ch: str) {
            board.back().push_back(ch);
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'k') {
                if ((i - 2) > -1 && (j - 1) > -1) {
                    if (board[i - 2][j - 1] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                if ((j - 2) > -1 && (i - 1) > -1) {
                    if (board[i - 1][j - 2] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                if ((j + 2) < board[0].size() && (i - 1) > -1) {
                    if (board[i - 1][j + 2] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                if ((i - 2) > -1 && (j + 1) < board[0].size()) {
                    if (board[i - 2][j + 1] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                if ((i + 2) < board.size() && (j - 1) > -1) {
                    if (board[i + 2][j - 1] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                if ((i + 1) < board.size() && (j - 2) > -1) {
                    if (board[i + 1][j - 2] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                if ((i + 2) < board.size() && (j + 1) < board[0].size()) {
                    if (board[i + 2][j + 1] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                if ((i + 1) < board.size() && (j + 2) < board[0].size()) {
                    if (board[i + 1][j + 2] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                count += 1;
            }
        }
    }
    if (count == 9) cout << "valid" << endl;
    else cout << "invalid" << endl;
    return 0;
}