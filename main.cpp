#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    int max1 = nums[0];
    vector<int>re(len,-1);
    re[1] = 1;
    for (int i = 0; i < len; i++) {
        if (nums[i] > max1) {
            max1 = nums[i];
        }
    }
    stack<int>a;
    int i = 0;
    int u = 0;
    while (u <= len) {
        if (nums[i % len] == max1) {
            re[i % len] = -1;
            u++;
            i++;
            continue;
        }
        if (a.empty()) {
            a.push(i % len);
            i++;
        }
        if (nums[a.top()] < nums[i % len]) {
            re[a.top()] = nums[i % len];
            a.pop();
            u++;
        }
        else {
            a.push(i % len);
            i++;
        }
    }
    return re;
}
int main() {
    vector<int>a(3);
    a[1] = 2;
    a[0] = 1;
    a[2] = 1;
    vector<int>re1(3);
    re1 = nextGreaterElements(a);
    cout << re1[0] << re1[1] << re1[2] << endl;
}
