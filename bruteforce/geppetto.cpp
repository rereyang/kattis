#include <bits/stdc++.h>

using namespace std; 

#define setn(_set, _i) (_set | (1 << _i))
#define clrn(_set, _i) (_set & (~(1 << _i)))
#define getn(_set, _i) ((_set & (1 << _i)) >> _i)

bool validate(int nums, int x, int len, vector<vector<bool>>& confs) {
    for (int i = 0; i < len; i++)
        if (i != x && getn(nums, i) && confs[x][i])
            return false; 
    return true; 
}

void dfs(int& nums, int len, int& acc, vector<vector<bool>>& confs, vector<bool>& visited) {
    if (nums > ((1 << len) - 1))
        return;  
    if (visited[nums])
        return; 
    visited[nums] = true; 
    acc = acc + 1; 
    for (int i = 0; i < len; i++) {
        if (getn(nums, i) == 0 && validate(nums, i, len, confs)) {
            nums = setn(nums, i); 
            dfs(nums, len, acc, confs, visited);
            nums = clrn(nums, i); 
        }
    }
}

int main() {
    int n, m; 
    cin >> n >> m; 
    vector<int> nums; 
    for (int i = 0; i < n; i++) 
        nums.push_back(i);
    int a, b;
    int count = 0; 
    vector<vector<bool>> conflicts(n, vector<bool> (n, false));  
    vector<bool> visited(1 << n, false); 
    for (int i = 0; i < m; i++) {
        cin >> a >> b; 
        conflicts[a - 1][b - 1] = true; 
        conflicts[b - 1][a - 1] = true;
    }
    int num_set = 0; 
    dfs(num_set, n, count, conflicts, visited);
    cout << count << endl;  
    return EXIT_SUCCESS; 
}