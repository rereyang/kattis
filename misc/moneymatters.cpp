#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>

using namespace std;

int find(int i, int par[]) {
    if (par[i] == i) {
        return i;
    } else {
        par[i] = find(par[i], par);
        return par[i];
    }
}

void uunion(int i, int j, int par[], int rank[]) {
    int fi = find(i, par);
    int fj = find(j, par);
    par[fj] = fi;
}

int main() {
    int n, m;
    cin >> n >> m;
    int bal[n], rank[n], par[n];
    for (int i = 0; i < n; i++) {
        cin >> bal[i];
        rank[i] = 0;
        par[i] = i;
    }
    int f1, f2;
    for (int i = 0; i < m; i++) {
        cin >> f1 >> f2;
        uunion(f1, f2, par, rank);
    }
    for (int i = 0; i < n; i++) {
        int fi = find(i, par);
        if (par[i] == i)
            continue;
        bal[fi] += bal[i];
    }
    for (int i = 0; i < n; i++) {
        if (par[i] == i && bal[i] < 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    return 0;
}