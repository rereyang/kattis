#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n + n - 1];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = n; i < n + n - 1; i++) {
        nums[i] = nums[i - n];
    }
    for (int i = 0; i < n; i++) {
        int bal = nums[i], dem = 0;
        bool is_good = true;
        for (int j = i + 1; j < i + n; j++) {
            if (bal < nums[j]) {
                is_good = false;
                break;
            }
            dem += nums[j];
        }
        if (is_good && dem >= nums[i]) {
            cout << (i % n) + 1;
            for (int j = i + 1; j < i + n; j++) {
                cout << " " << (j % n) + 1;
            }
            cout << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}