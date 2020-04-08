#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int parent[101];
int counts[101];
char line[440];

int main() {
    int cat, root = 0;
    cin >> cat;
    string str;
    getline(cin, str, '\n');
    while (getline(cin, str, '\n') && str != "-1") {
        stringstream ist(str);
        int par, num;
        ist >> par;
        counts[par]++;
        while (ist >> num) {
            parent[num] = par; 
            counts[num] += 2;
        }
    }
    for (int i = 0; i < 101; i++) {
        if (counts[i] == 1) {
            root = i;
        }
    }
    // cout << root <<endl;
    while (cat != root) {
        cout << cat << " ";
        cat = parent[cat];
    }
    cout << cat << endl;
    return 0;
}