#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int tc_count; 
    cin >> tc_count; 
    for (int i = 1; i < tc_count + 1; i++) {
        int len; 
        cin >> len; 
        vector<int> xs, ys; 
        int xy;
        long long int sum_prod = 0; 
        for (int j = 0; j < len; j++) {
            cin >> xy; 
            xs.push_back(xy); 
        }
        sort(xs.begin(), xs.end()); 
        for (int j = 0; j < len; j++) {
            cin >> xy;
            ys.push_back(xy); 
        }
        sort(ys.begin(), ys.end()); 
        for (int k = 0; k < len; k++) 
            sum_prod += (long long)xs[k] * (long long)ys[len - k - 1]; 
        
        cout << "Case #" << i << ": " << sum_prod << endl; 
    }
    return 0; 
}