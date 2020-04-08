#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int n, m; 
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<vector<int>> intervals;
        int src, dest, start, dur; 
        for (int i = 0; i < n; i++) {
            cin >> src >> dest >> start >> dur; 
            intervals.push_back({start, dur}); 
        }
        int qstart, qdur; 
        for (int i = 0; i < m; i++) {
            cin >> qstart >> qdur; 
            int ans = 0; 
            for (const auto& interval: intervals) 
                if (qstart < interval[0] + interval[1] && 
                    interval[0] < qstart + qdur)
                    ans = ans + 1;
            cout << ans << endl; 
        }
    }
    return EXIT_SUCCESS; 
}
