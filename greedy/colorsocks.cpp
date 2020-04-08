#include <bits/stdc++.h>

using namespace std;

int cmp(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int s, c, k, ans = 0;
    cin >> s >> c >> k;
    int nums[s];
    for (int i = 0; i < s; i++) 
        cin >> nums[i];
    qsort(nums, s, sizeof(int), cmp);
    int inf = 0;
    while (inf < s) {
        int sup = min(inf + c - 1, s - 1);
        while (nums[sup] - nums[inf] > k)
            sup -= 1;
        ans += 1;
        inf = sup + 1;
    }
    cout << ans << endl;
    return 0; 
}
