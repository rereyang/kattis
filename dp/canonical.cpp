#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        coins.push_back(k);
    }
    int lrg_len = coins[n - 2] + coins[n - 1];
    int dp[lrg_len];
    memset(dp, 0, sizeof(int) * lrg_len);
    for (int i = 1; i < lrg_len; i++) {
        int cur_max = 0, lrg_ind = 0;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                lrg_ind = j;
            }
            if (i - coins[j] >= 0 && dp[i - coins[j]] <= dp[i - coins[cur_max]]) {
                cur_max = j;
            }
        }
        if (lrg_ind != cur_max) {
            cout << "non-canonical" << endl;
            return 0;
        }
        dp[i] = dp[i - coins[cur_max]] + 1;
    }
    cout << "canonical" << endl;
    return 0; 
}