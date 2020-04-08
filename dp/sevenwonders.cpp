#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    cin >> line;
    int tc = 0, cc = 0, gc = 0;
    for (auto& ch: line) {
        switch (ch) {
            case 'T': tc++; break;
            case 'C': cc++; break;
            case 'G': gc++; break;
            default: break;
        }
    }
    cout << tc * tc + cc * cc + gc * gc + 7 * min(tc, min(cc, gc)) << endl;
    return 0;
}