//
// Created by DELL on 2023/5/23.
//

#include <functional>
#include <queue>
#include <vector>
class Solution {
public:


    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        for (int i = 0; i < input.size(); i++) {
            q.push(input[i]);
        }
        vector<int>res;
        while (k--) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
