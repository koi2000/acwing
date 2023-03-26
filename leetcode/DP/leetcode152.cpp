leetcode121.cpp#include<bits / stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int dpx[n];
        int dpn[n];
        memset(dpx, 0, sizeof dpx);
        memset(dpn, 0, sizeof dpn);
        dpx[0] = nums[0];
        dpn[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dpx[i] = max(dpx[i - 1] * nums[i], max(nums[i], dpn[i - 1] * nums[i]));
            dpn[i] = min(dpx[i - 1] * nums[i], min(nums[i], dpn[i - 1] * nums[i]));
        }
        return *max_element(dpx, dpx + n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

