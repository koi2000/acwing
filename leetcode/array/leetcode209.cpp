#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int l = 0;
        int r = 0;
        int res = INT_MAX;
        int sum = 0;
        while (true) {
            if (sum >= target) {
                res = min(r - l, res);
                sum -= nums[l];
                l++;
            } else if (r < nums.size()) {
                sum += nums[r];
                r++;
            } else {
                break;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    Solution solution = Solution();
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    solution.generateMatrix(3);
    return 0;
}

