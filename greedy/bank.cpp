#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int main() {
    int n, t; 
    while (cin >> n >> t) {
        int ci, ti; 
        vector<vector<int>> hashtable(t);  
        for (int i = 0; i < n; i++) {
            cin >> ci >> ti; 
            hashtable[ti].push_back(ci); 
        }
        int sum = 0; 
        priority_queue<int> pq; 
        for (int i = t - 1; i > -1; i--) {
            for (const auto& c: hashtable[i])
                pq.push(c); 
            if (pq.size() > 0) {
                sum = sum + pq.top(); 
                pq.pop(); 
            }
        } 
        cout << sum << endl; 
    }
    return EXIT_SUCCESS; 
}