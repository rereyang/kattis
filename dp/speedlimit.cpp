#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n, n > 0) {
        int prevt = 0, miles = 0;
        while (n--) {
            int speed, currt;
            cin >> speed >> currt;
            miles += speed * (currt - prevt);
            prevt = currt;
        }
        cout << miles << " miles" << endl;
    }
    return 0;
}