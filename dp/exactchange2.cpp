#include <bits/stdc++.h>

using namespace std;

int main() {
    int ntc;
    cin >> ntc;
    for (int tc = 0; tc < ntc; tc++) {
        int n, target;
    cin >> target;
        cin >> n;
    int coins[n];
    for (int c = 0; c < n; c++)
            cin >> coins[c];
    int dp[10001];
    memset(dp, 10000, (10001) * sizeof(int));
    dp[0] = 0;
    for (int i = 0; i < n; i++) 
            for (int j = 10000; j >= 0; j--) 
                if (j >= coins[i]) 
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
    int min_change, count = 0;
    for (int i = target; i < 10001; i++) {
            if (dp[i] < 10000) {
                min_change = i;
        count = dp[i];
        break;
        }
    }
    cout << min_change << " " << count << endl;
    }
    return 0;
}
