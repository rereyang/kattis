#include <iostream>

using namespace std; 

int main() {
    int len, offset; 
    while (cin >> len >> offset) {
        int curr_num, max_sum = 0, curr_max = 0;  
        for (int i = 0; i < len; i++) {
            cin >> curr_num; 
            curr_max = max(curr_max + curr_num - offset, 
                           curr_num - offset); 
            max_sum = max(max_sum, curr_max); 
        }
        cout << max_sum << endl; 
    }
    return EXIT_SUCCESS; 
}