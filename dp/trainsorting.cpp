#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int lis(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> minx;
    for(int i = 0; i < nums.size(); i++){
        auto lp = lower_bound(minx.begin(), minx.end(), nums[i]);
        if (lp == minx.end()) minx.emplace_back(nums[i]);
        else *lp = nums[i];
    }  
    return minx.size();
}

int main() {
    int n, glob_maxr = 0;
    cin >> n;
    vector<int> nums;
    map<int, int> idnums;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        vector<int> gt, lt;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                gt.push_back(nums[j]);
            }
            if (nums[i] > nums[j]) {
                lt.push_back(-nums[j]);
            }
        }
        glob_maxr = max(glob_maxr, 1 + lis(gt) + lis(lt));
    }
    cout << glob_maxr << endl;
    return 0;
}