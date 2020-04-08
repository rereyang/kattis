#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 1, r = 1000, t = 1;
    while (l <= r && t < 11) {
        t = t + 1;
        int mid = (l + r) / 2;
        string ans;
        cout << mid << endl;
        cin >> ans;
        if (ans == "lower") {
            r = mid;
        } else if (ans == "higher") {
            l = mid + 1;
        } else {
            return 0;
        }
    }
    return 0;
}