#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main() {
    string word; 
    while (cin >> word) {
        vector<int> dict(26, 0); 
        int num_odd = 0; 
        for (const auto& c: word)
           dict[c - 'a'] = dict[c - 'a'] + 1;  
        for (const auto& cnt: dict)
            if (cnt % 2 != 0)
                num_odd = num_odd + 1; 
        if (num_odd < 1)
            cout << 0 << endl; 
        else
            cout << num_odd - 1 << endl; 
    }
    return EXIT_SUCCESS; 
}
