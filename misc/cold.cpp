// 17:46
// 17:50
#include <iostream>

using namespace std;
int main() {
    int n, a, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) c++;
    }
    cout << c << endl;
    return 0;
}