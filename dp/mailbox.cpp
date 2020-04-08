#include <iostream>
#include <vector>

using namespace std;

int explode(int k, int ms, int me, vector<vector<vector<int>>>& dp) {
    if (ms > me) {
        return 0;
    }
    if (dp[k][ms][me] != -1) return dp[k][ms][me];
    if (ms == me) {
        dp[k][ms][ms] = ms;
        return ms;
    }
    if (k == 1) {
        dp[k][ms][me] = (ms + me) * (me - ms + 1) / 2;
        return dp[k][ms][me];
    }
    dp[k][ms][me] = (ms + me) * (me - ms + 1) / 2;
    for (int i = ms; i <= me; i++) {
        dp[k][ms][me] = min(dp[k][ms][me], i + max(explode(k - 1, ms, i - 1, dp), explode(k, i + 1, me, dp)));
    }
    return dp[k][ms][me];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k, m, prev_min = 1;
        cin >> k >> m;
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>> (m + 1, vector<int> (m + 1, -1)));
        cout << explode(k, 1, m, dp) << endl;
    }
    return 0;
}