#include <iostream>
#include <vector>
#include <set>

using namespace std; 

int main() {
    int n, t; 
    while (cin >> n >> t) {
        long a, b, c, t0; 
        cin >> a >> b >> c >> t0; 
        multiset<long> mset;
        mset.insert(t0);
        for (long i = 1; i < n; i++) {
            t0 = (((a * t0) + b) % c) + 1;
            mset.insert(t0); 
        }
        long sum = 0; 
        long penalty = 0; 
        long curr_time = 0; 
        for (const auto& num: mset) {
            if (num + curr_time <= t) {
                sum = sum + 1;
                penalty = (penalty + curr_time + num) % 1000000007; 
                curr_time = curr_time + num; 
            } else {
                break; 
            }
        }
        cout << sum << " " << penalty << endl; 
    }
    return EXIT_SUCCESS; 
}