#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *preHead = new ListNode();
        preHead->next = head;
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        if (len == 1)return nullptr;
        head = preHead->next;
        int idx = len - n - 1;
        if (idx < 0)return preHead->next->next;
        for (int i = 0; i < idx; i++) {
            head = head->next;
        }
        if (head && head->next) {
            head->next = head->next->next;
        }
        return preHead->next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

