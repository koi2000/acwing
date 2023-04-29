//
// Created by DELL on 2023/4/29.
//
#include <vector>

class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int> &arr) {
        // write code here
        int n = arr.size();
        vector<int> flag(n, 1);
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                flag[i] = flag[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1] && flag[i] <= flag[i + 1]) {
                flag[i] = flag[i + 1] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += flag[i];
        }
        return res;
    }
};