#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int case_id = 1; 
    int arr_len; 
    while (cin >> arr_len) {
        cout << "Case " << case_id << ":" << endl; 
        int curr_num, query_len, curr_query; 
        vector<int> arr; 
        for (int i = 0; i < arr_len; i++) {
            cin >> curr_num; 
            arr.push_back(curr_num); 
        }
        sort(arr.begin(), arr.end());
        auto query = [&](int target) {
            int i = 0, j = arr_len - 1;
            int diff = numeric_limits<int>::max(), min_i = i, min_j = j;
            while (i < j) {
                if (arr[i] + arr[j] < target) {
                    if (target - arr[i] - arr[j] < diff) {
                        diff = target - arr[i] - arr[j]; 
                        min_i = i; 
                        min_j = j; 
                    }
                    i = i + 1; 
                } else {
                    if (arr[i] + arr[j] - target < diff) {
                        diff = arr[i] + arr[j] - target; 
                        min_i = i; 
                        min_j = j; 
                    }
                    j = j - 1; 
                }
            }
            return arr[min_i] + arr[min_j]; 
        }; 
        cin >> query_len;
        for (int i = 0; i < query_len; i++) {
            cin >> curr_query; 
            cout << "Closest sum to " << curr_query << " is " 
                 << query(curr_query) << "."        << endl;  
        } 
        case_id = case_id + 1; 
    }
    return EXIT_SUCCESS; 
}