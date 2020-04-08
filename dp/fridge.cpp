#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int dcount[10];
int new_num[10];

int main() {
    string digits;
    cin >> digits;
    int numlen = digits.size(), min_count = 1000, min_digit = 9;
    vector<int> old_num;
    for (auto& d: digits) {
        old_num.push_back(d - '0');
        dcount[d - '0']++;
    }
    for (int i = 1; i < 10; i++) {
        if (min_count > dcount[i]) {
            min_count = dcount[i];
            min_digit = i;
        }
    }
    if (min_count == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (dcount[0] <= (min_count - 1)) {
        cout << 1;
        while (dcount[0]--) cout << 0;
        cout << 0 << endl;
        return 0;
    }
    dcount[min_digit] -= min_count;
    for (int i = 0; i < 10; i++) {
        if (dcount[i] == 0) {
            for (int j = 0; j < min_count; j++) 
                cout << min_digit;
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}