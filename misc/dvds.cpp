#include <iostream>

using namespace std;

int main() {
    int k, n, b;
    cin >> k;
    while (k--) {
        cin >> n;
        int arr[n];
        int a = 0, tofind = 1;
        while (a < n) {
            cin >> arr[a++];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == tofind) {
                tofind += 1;
            }
        }
        cout << n - tofind + 1<< endl;
    }
    return 0;
}