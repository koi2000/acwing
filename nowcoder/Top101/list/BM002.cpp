//
// Created by DELL on 2023/4/20.
//
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseL(ListNode st, ListNode *ed) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = ed;
        ListNode *p = &st;
        ListNode *s = nullptr;
        while (p != ed) {
            s = p;
            p = p->next;
            s->next = dummyHead->next;
            dummyHead->next = s;
        }
        return dummyHead->next;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write code here
        if (n == m)return head;
        int idx = 0;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *save = dummyHead;
        while (idx < m - 1) {
            dummyHead = dummyHead->next;
            idx++;
        }
        ListNode *st = dummyHead;
        while (idx < n + 1) {
            dummyHead = dummyHead->next;
            idx++;
        }
        ListNode *ed = dummyHead;
        auto node = reverseL(*st->next, ed);
        st->next = node;
        return save->next;
    }
};
