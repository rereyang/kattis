#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;
typedef unsigned long long ull; 

int main() {
    int n; 
    while (cin >> n) {
        ull cn, sum_t = 0;
        ull nums[n]; 
        for (int i = 0; i < n; i++) {
            cin >> cn;
            nums[i] = cn; 
            sum_t = sum_t + cn; 
        }
        sum_t = sum_t << (n - 1); 
        for (int i = 0; i < n; i++) {
            if (nums[i] < 200)
                sum_t = sum_t - nums[i]; 
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] < 200)
                    sum_t = sum_t - (nums[i] + nums[j]); 
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] < 200)
                        sum_t = sum_t - (nums[i] + nums[j] + nums[k]); 
                }
            }
        }
        cout << sum_t << endl; 
    }
    return EXIT_SUCCESS; 
}