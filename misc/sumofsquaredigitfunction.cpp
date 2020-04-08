#include <iostream>

using namespace std;

int main() {
    int k, n, b;
    cin >> k;
    while (cin >> k >> b >> n) {
        int acc = 0;
        while (n > 0) {
            int r = n % b;
            acc += r * r;
            n = n / b;
        }
        cout << k << " " << acc << endl;
    }
    return 0;
}