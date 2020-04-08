#include <iostream>
#include <vector>

using namespace std;

void print(int subset, int len, vector<int>& v) {
    for (int i = 0; i < len; i++) {
        if ((subset & (1 << i))) {
            if (i == len - 1)
                cout << v[i] << endl;
            else
                cout << v[i] << " ";
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int n, gsum = 0;
        cin >> n;
        vector<int> nums(n);
        for (int a = 0; a < n; a++) {
            cin >> nums[a];
            gsum += nums[a];
        }
        vector<vector<int>> sums(gsum + 1);
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j))) {
                    sum += nums[j];
                }
            }
            sums[sum].push_back(i);
        }
        cout << "Case #" << m + 1 << ":" << endl;
        for (const auto& substs: sums) {
            if (substs.size() > 1) {
                for (int i = 0; i < 2; i++) {
                    print(substs[i], n, nums);
                    cout << endl;
                }
                goto skip;
            }
        }
        cout << "Impossible" << endl;
        skip:
        continue;
    }
    return EXIT_SUCCESS;
}
