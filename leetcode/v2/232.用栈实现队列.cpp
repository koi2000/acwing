/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyQueue {
  public:
    stack<int> in;
    stack<int> out;
    MyQueue() {}

    void convert() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }

    void push(int x) { in.push(x); }

    int pop() {
        if (out.empty()) {
            convert();
        }
        int ret = out.top();
        out.pop();
        return ret;
    }

    int peek() {
        if (out.empty()) {
            convert();
        }
        return out.top();
    }

    bool empty() { return in.empty() && out.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
