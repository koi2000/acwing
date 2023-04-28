//
// Created by DELL on 2023/4/23.
//
#include <deque>
#include <queue>
#include <vector>

class Solution {
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        deque <pair<int, int>> q;
        vector<int> ret;
        int k = size;
        if (num.size() == 0 || size < 1 || num.size() < size) return ret;
        for (int i = 0; i < num.size(); i++) {
            while (!q.empty() && q.front().second <= (i - k)) {
                q.pop_front();
            }
            while (!q.empty() && q.back().first < num[i]) {
                q.pop_back();
            }
            q.push_back({num[i], i});
            if (i >= size - 1) {
                ret.push_back(q.front().first);
            }
        }
        return ret;
    }
};