#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std; 

int main() {
    int n_item;
    while (cin >> n_item) {
        vector<int> items, queries; 
        int item, n_query, query; 
        for (int i = 0; i < n_item; i++) {
            cin >> item; 
            items.push_back(item);
        }
        cin >> n_query; 
        for (int i = 0; i < n_query; i++) {
            cin >> query; 
            queries.push_back(query); 
        }
        vector<int> last_sel(32001, -2);
        last_sel[0] = 0; 
        for (int i = 0; i < n_item; i++) {
            for (int j = 0; j < 30001; j++) {
                if (last_sel[j] >= 0) {
                    if (last_sel[j + items[i]] == -2)
                        last_sel[j + items[i]] = i; 
                    else 
                        last_sel[j + items[i]] = -1; 
                } 
                if (last_sel[j] == -1) {
                    last_sel[j + items[i]] = -1; 
                }
            }
        }
        auto query_fvt = [&](int target) -> void {
            vector<int> backtrack; 
            if (last_sel[target] == -2) {
                cout << "Impossible" << endl;
                return; 
            }
            if (last_sel[target] == -1) {
                cout << "Ambiguous" << endl;
                return; 
            }
            while (target > 0) {
                backtrack.push_back(last_sel[target] + 1); 
                target = target - items[last_sel[target]]; 
            }
            sort(backtrack.begin(), backtrack.end()); 
            for (size_t i = 0; i < backtrack.size(); i++) {
                if (i == backtrack.size() - 1)
                    cout << backtrack[i] << endl; 
                else
                    cout << backtrack[i] << " "; 
            }
        }; 
        for (const auto& query: queries)
            query_fvt(query); 
    }
    return EXIT_SUCCESS; 
}