#include <iostream>

using namespace std;

int main() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int l = min(a, min(b, c));
    int h = max(a, max(b, c));
    int md = a + b + c - (l + h);
    if (l + md <= h) {
        if (m >= h) {
            cout << "possible" << endl;
        } else {
            cout << "impossible" << endl;
        }
    } else {
        if ((l + md - h) % 2 == 0) {
            if ((l + md + h) / 2 <= m) {
                cout << "possible" << endl;
            } else {
                cout << "impossible" << endl;
            }
        } else {
            if ((l + md + h - 1) / 2 + 1 <= m) {
                cout << "possible" << endl;
            } else {
                cout << "impossible" << endl;
            }
        }
    }
    return 0;
}

