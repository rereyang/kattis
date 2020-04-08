#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(_a, _b) (_a > _b) ? (_a) : (_b)

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int times[101001];
    memset(times, 0, 101001 * sizeof(int));
    int start;
    for (int i = 0; i < n; i++) {
        scanf("%d", &start);
        times[start] += 1;
        times[start + 1000] -= 1;
    }
    int ans = -1, count = 0;
    for (int i = 0; i < 101001; i++) {
        count = count + times[i];
        ans = max(ans, count);
    }
    // printf("%d ", ans);
    printf("%d\n", (ans % k == 0) ? (ans / k) : (ans / k + 1));
    return EXIT_SUCCESS;
}