#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

void print(int nums[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i < n - 1)
            cout << nums[i] << ", ";
        else
            cout << nums[i] << "]" << endl;
    }
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    int supl[n], infr[n];
    supl[0] = -1;
    for (int i = 1; i < n; i++) 
        supl[i] = max(supl[i - 1], nums[i - 1]);
    infr[n - 1] = numeric_limits<int>::max();
    for (int i = n - 2; i > -1; i--)
        infr[i] = min(infr[i + 1], nums[i + 1]);
    // print(nums, n);
    // print(supl, n);
    // print(infr, n);
    for (int i = 0; i < n; i++)
        if (supl[i] <= nums[i] && nums[i] < infr[i])
            count = count + 1;
    printf("%d\n", count);
    return 0;
}