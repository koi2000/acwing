/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyStack {
  public:
    queue<int> stk;
    
    MyStack() {}


    void push(int x) {
        int n = stk.size();
        stk.push(x); 
        for (int i = 0; i < n; i++) {
            stk.push(stk.front());
            stk.pop();
        }
        
     }

    int pop() {
        int re = stk.front();
        stk.pop();
        return re;
    }

    int top() {
        return stk.front();
    }

    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
