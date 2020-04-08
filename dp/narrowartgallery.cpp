#include <iostream>
#include <vector>

using namespace std; 

int main() {
    int n, k; 
    while (cin >> n >> k) {
        int l, r; 
        vector<vector<int>> g; 
        for (int i = 0; i < n; i++) {
            cin >> l >> r; 
            g.push_back({l, r}); 
        }
        cin >> l >> r; 
        vector<int> a(k + 1, -1); int diag_a = -1; // a[k][j] = max(a[k - 1][j - 1], c[k - 1][j - 1]) + g[k][0];   
        vector<int> b(k + 1, -1); int diag_b = -1; // b[k][j] = max(b[k - 1][j - 1], c[k - 1][j - 1]) + g[k][1]; 
        vector<int> c(k + 1, -1); int diag_c = -1; // c[k][j] = max(a[k - 1][j], b[k - 1][j]) + g[k][0] + g[k][1]; 
        c[0] = g[0][0] + g[0][1]; 
        if (k > 0) {
            a[1] = g[0][0];
            b[1] = g[0][1];
        } 
        for (int i = 1; i < n; i++) {
            diag_c = c[0]; 
            c[0] = c[0] + g[i][0] + g[i][1];
            for (int j = 1; j < min(i + 1, k + 1); j++) {
                int temp_a = max(diag_a, diag_c) + g[i][0]; 
                diag_a = a[j]; 
                a[j] = temp_a; 
                int temp_b = max(diag_b, diag_c) + g[i][1]; 
                diag_b = b[j]; 
                b[j] = temp_b; 
                int temp_c = max(max(diag_a, diag_b), c[j]) + g[i][0] + g[i][1]; 
                diag_c = c[j]; 
                c[j] = temp_c; 
            }
            if (i < k) {
                a[i + 1] = diag_a + g[i][0]; 
                b[i + 1] = diag_b + g[i][1]; 
            }
        }
        cout << max(max(c[k], b[k]), a[k]) << endl;
    }
    return EXIT_SUCCESS; 
}