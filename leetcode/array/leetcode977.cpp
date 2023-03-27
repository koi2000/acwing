#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> ans;
        for (int num: nums) {
            ans.push_back(num * num);
        }
        sort(ans.begin(), ans.end());
        return ans;
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

