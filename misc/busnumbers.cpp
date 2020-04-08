#include <iostream>

using namespace std;

int buses[1002];

int main() {
    int n, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        buses[c] += 1;
    }
    int prev = 1;
    for (int i = 1; i < 1002; i++) {
        if (!buses[i] && buses[prev]) {
            if (i - prev > 2) {
                cout << prev << "-" << i - 1 << " ";
            } else {
                if (i - prev == 2)
                    cout << prev << " " << i - 1 << " ";
                else
                    cout << prev << " ";
            }
            prev = i;
        } else if (!buses[i]) {
            prev = i;
        } else if (buses[i] && !buses[prev]) {
            prev = i;
        }
    }
    return 0;
}