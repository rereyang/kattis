#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long int x, y, prev = 0;
    int n;
    cin >> x >> y;
    cin >> n;
    double accfact = 0;
    while (n--) {
        int l, u;
        double f;
        cin >> l >> u >> f;
        accfact += (l - prev) + (u - l) * f;
        prev = u;
    }
    if (prev <= y) {
        accfact += (y - prev);
    }
    cout << fixed;
    cout << setprecision(11) << x / accfact << endl;
    return 0;
}