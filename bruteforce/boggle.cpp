#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <memory>
#include <cstdlib>

using namespace std; 

int marks[] = {0, 0, 0, 1, 1, 2, 3, 5, 11}; 

bool help(vector<vector<char>>& board, vector<vector<bool>>& used,  string& word, 
          int i, int j, size_t k) {
    if (k == word.size()) 
        return true; 
    if (i < 0 || i > 3 || j < 0 || j > 3)
        return false; 
    if (used[i][j])
        return false; 
    if (board[i][j] != word[k]) 
        return false; 
    used[i][j] = true; 
    for (int x = -1; x < 2; x++) {
        for (int y = -1; y < 2; y++) {
            if (help(board, used, word, i + x, j + y, k + 1)) {
                return true; 
            }
        }
    }
    used[i][j] = false; 
    return false; 
}

bool exist(vector<vector<char>>& board, string& word) {
    vector<vector<bool>> is_used(board.size(), vector<bool> (board[0].size(), false)); 
    if (word.size() == 0) return true;
    for (size_t i = 0; i < board.size(); i++) 
        for (size_t j = 0; j < board[0].size(); j++) 
            if (help(board, is_used, word, i, j, 0))
                return true; 
    return false; 
}

int main() {
    int n; 
    while (cin >> n) {
        string strin; 
        int intin; 
        vector<string> words; 
        for (int i = 0; i < n; i++) {
            cin >> strin; 
            words.push_back(strin); 
        }
        cin >> intin; 
        sort(words.begin(), words.end()); 
        for (int i = 0; i < intin; i++) {
            vector<vector<char>> board(4, vector<char> (4, 0)); 
            cin >> strin;
            board[0][0] = strin[0]; board[0][1] = strin[1]; 
            board[0][2] = strin[2]; board[0][3] = strin[3]; 
            cin >> strin;
            board[1][0] = strin[0]; board[1][1] = strin[1]; 
            board[1][2] = strin[2]; board[1][3] = strin[3]; 
            cin >> strin;
            board[2][0] = strin[0]; board[2][1] = strin[1]; 
            board[2][2] = strin[2]; board[2][3] = strin[3]; 
            cin >> strin;
            board[3][0] = strin[0]; board[3][1] = strin[1]; 
            board[3][2] = strin[2]; board[3][3] = strin[3]; 
            int total = 0, count = 0; 
            string max_len = ""; 
            for (auto& word: words) {
                if (exist(board, word)) {
                    total = total + marks[word.size()]; 
                    count = count + 1; 
                    if (word.size() > max_len.size())
                        max_len = word; 
                }
            } 
            cout << total << " " << max_len << " " << count << endl; 
        }
    }
    return EXIT_SUCCESS; 
}