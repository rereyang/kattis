#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <limits>
#include <utility>

using namespace std; 

int main() {
    string line; 
    while (getline(cin, line)) {
        istringstream ss(line);
        size_t key_len; 
        ss >> key_len;  
        if (key_len < 1)
            continue; 
        vector<int> keys;
        int n;  
        for (size_t i = 0; i < key_len; i++) {
            ss >> n; 
            keys.push_back(n - 1); 
        }
        string message; 
        getline(cin, message); 
        while (message.size() % key_len != 0)
            message = message + " "; 
        string result = ""; 
        for (size_t start = 0; start < message.size(); start+=key_len)
            for (size_t i = 0; i < key_len; i++)
                result = result + message[start + keys[i]]; 
        cout << "\'" << result << "\'" << endl;
    }
    return EXIT_SUCCESS; 
}