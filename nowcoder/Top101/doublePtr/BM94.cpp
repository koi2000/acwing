//
// Created by DELL on 2023/4/19.
//
class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int> &arr) {
        // write code here
        if (arr.size() == 0) return 0;
        long long res = 0;
        int l = 0;
        int r = arr.size() - 1;
        int maxL = 0;
        int maxR = 0;
        while (l < r) {
            maxL = max(maxL, arr[l]);
            maxR = max(maxR, arr[r]);
            if (maxR > maxL) {
                res += maxL - arr[l++];
            } else {
                res += maxR - arr[r--];
            }
        }
        return res;
    }
};