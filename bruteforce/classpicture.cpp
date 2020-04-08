#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

bool validate(vector<vector<bool>>& cfl, vector<int>& nums) {
    for (size_t i = 0; i < nums.size() - 1; i++) 
        if (cfl[nums[i]][nums[i + 1]]) 
            return false; 
    return true; 
}

int main() {
    int n; 
    while (cin >> n) {
        string cr, cr1;
        vector<string> students;
        vector<int> nums; 
        vector<vector<bool>> conflicts(n, vector<bool> (n, false)); 
        for (int i = 0; i < n; i++) {
            cin >> cr; 
            students.push_back(cr);
            nums.push_back(i); 
        }
        sort(students.begin(), students.end());
        int cln; 
        cin >> cln; 
        for (int i = 0; i < cln; i++) {
            cin >> cr >> cr1; 
            int x = lower_bound(students.begin(), students.end(), cr) - students.begin(); 
            int y = lower_bound(students.begin(), students.end(), cr1) - students.begin(); 
            conflicts[x][y] = true; 
            conflicts[y][x] = true; 
        }
        bool possible = false; 
        do {
            if (validate(conflicts, nums)) 
                possible = true; 
            
        } while (!possible && next_permutation(nums.begin(), nums.end())); 
        if (possible) {
            for (int i = 0; i < n; i++) {
                if (i == n - 1)
                    cout << students[nums[i]] << endl; 
                else 
                    cout << students[nums[i]] << " "; 
            }
        } else {
            cout << "You all need therapy." << endl; 
        }
    }
    return 0; 
}