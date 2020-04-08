#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> nums, accnums;

int dp[2001][2001][21];

int round10(int n) {
    if ((n % 10) < 5) return (n / 10) * 10;
    else return ((n / 10) + 1) * 10;
}

int compute(int s, int e, int nd) {
    if (dp[s][e][nd] != -1) return dp[s][e][nd];
    int opt = 2000 * 10000 + 1;
    if (nd == 0 || s == e) {
        dp[s][e][nd] = round10(accnums[e + 1] - accnums[s]);
        return dp[s][e][nd];
    }
    for (int i = s; i < e; i++) {
        opt = min(opt, round10(accnums[i + 1] - accnums[s]) + compute(i + 1, e, nd - 1));
    }
    opt = min(opt, compute(s, e, nd - 1));
    dp[s][e][nd] = opt;
    return opt;
}

int main() {
    int n, d;
    cin >> n >> d;
    int ncpy = n;
    
    accnums.push_back(0);
    while (ncpy--) {
        int t;
        cin >> t;
        nums.push_back(t);
        accnums.push_back(t + accnums.back());
    }
    
    memset(dp, -1, (2001) * (2001) * (21) * sizeof(int));
    cout << compute(0, n - 1, d) << endl;
    return 0;
}