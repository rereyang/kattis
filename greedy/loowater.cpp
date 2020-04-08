#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std; 

int main() {
    int n, m; 
    while (cin >> n >> m, n && m) {
        multiset<int> knights; 
        priority_queue<int, vector<int>, greater<int>> heads; 
        int cu; 
        for (int i = 0; i < n; i++) {
            cin >> cu; 
            heads.push(cu); 
        }
        for (int i = 0; i < m; i++) {
            cin >> cu; 
            knights.insert(cu); 
        }
        int cost = 0; 
        while (knights.size() > 0 && heads.size() > 0) {
            auto matched = knights.lower_bound(heads.top()); 
            if (matched == knights.end()) 
                break; 
            cost = cost + *matched; 
            knights.erase(matched); 
            heads.pop(); 
        }
        if (heads.size() > 0) 
            cout << "Loowater is doomed!" << endl;
        else
            cout << cost << endl; 
    }
    return EXIT_SUCCESS; 
}