#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *preNode = new ListNode(0, nullptr);
        ListNode *p = head;
        ListNode *s = nullptr;
        while (p != nullptr) {
            s = p;
            p = p->next;
            s->next = preNode->next;
            preNode->next = s;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

