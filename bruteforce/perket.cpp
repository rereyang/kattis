#include <iostream>

using namespace std; 

typedef long long int lli; 

#define absi(_a, _b) (_a > _b) ? (_a - _b) : (_b - _a)

int main() {
    int n; 
    while (cin >> n) {
        lli ing[n][2]; 
        for (int i = 0; i < n; i++) 
            cin >> ing[i][0] >> ing[i][1]; 
        lli diff = 1000000000; 
        for (int i = 1; i < (1 << n); i++) {
            lli s = 1, b = 0; 
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    s *= ing[j][0]; 
                    b += ing[j][1]; 
                }
            }
            diff = min(diff, absi(s, b)); 
        }
        cout << diff << endl; 
        
    }
    return 0; 
}