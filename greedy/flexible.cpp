#include <bits/stdc++.h>

using namespace std;

bool acc[101];

int main() {
    int w, p;
    cin >> w >> p;
    int nums[p + 2];
    nums[0] = 0;
    nums[p + 1] = w;
    for (int i = 1; i < p + 1; i++) 
        cin >> nums[i];
    for (int i = 0; i < p + 2; i++) {
        for (int j = i + 1; j < p + 2; j++) {
            acc[nums[j] - nums[i]] = true;
        }
    }
    for (int i = 0; i <= w; i++) {
        if (acc[i]) {
            if (i == w) 
                printf("%d\n", i);
            else 
                printf("%d ", i);
        }
    }
    return 0; 
}