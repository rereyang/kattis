#include <iostream>
#include <vector>

using namespace std; 

bool validate(int len, vector<int> cities, int boxes) {
    int required = 0; 
    for (size_t i = 0; i < cities.size(); i++) 
        required += (cities[i] % len == 0) ? (cities[i] / len)
                                         : (cities[i] / len + 1); 
    return required <= boxes; 
}

int main() {
    int a, b; 
    while(cin >> a >> b, a != -1 && b != -1) {
        vector<int> cities; 
        int cu; 
        int l = 0, r = 0, mi; 
        for (int i = 0; i < a; i++) {
            cin >> cu; 
            cities.push_back(cu);
            r = max(r, cu);
        }
        while (l < r) {
            int mid = (l + r) / 2; 
            if (validate(mid, cities, b))
                r = mid; 
            else
                l = mid + 1; 
            mi = mid; 
        }
        string empty; 
        getline(cin, empty);
        cout << r << endl; 
    }
    return 0; 
}