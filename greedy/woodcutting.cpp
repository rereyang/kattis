#include <iostream>
#include <cstring>

using namespace std;

int cmp(const void* a, const void* b) {
    return *((unsigned long long int *)a) - *((unsigned long long int *)b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, wi, cr;
        cin >> n;
        unsigned long long int hash[n];
        memset(hash, 0.0, n * sizeof(unsigned long long int));
        for (int i = 0; i < n; i++) {
            cin >> wi;
            for (int j = 0; j < wi; j++) {
                cin >> cr;
                hash[i] += cr;
            }
        }
        qsort(hash, n, sizeof(unsigned long long int), cmp);
        long double sum = 0;
        long double acc = 0;
        for (int i = 0; i < n; i++) {
            sum += hash[i];
            acc += sum;
        }
        cout << fixed;
        cout.precision(9);
        cout << acc / n << endl;
    }
    return 0;
}