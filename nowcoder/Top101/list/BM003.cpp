//
// Created by DELL on 2023/4/20.
//
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    pair<ListNode *, ListNode *> reverseL(ListNode *st, ListNode *ed) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = ed->next;
        ListNode *p = st;
        ListNode *s = nullptr;
        while (p != ed) {
            ListNode *nxt = p->next;
            p->next = dummyHead->next;
            dummyHead->next = p;
            p = nxt;
        }
        return {ed, st};
    }

    pair<ListNode *, ListNode *> myReverse(ListNode *head, ListNode *tail) {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail) {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }


    ListNode *reverseKGroup(ListNode *head, int k) {
        // write code here
        ListNode *save = new ListNode(0);
        save->next = head;
        ListNode *preHead = save;
        while (head) {
            ListNode *tail = preHead;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return save->next;
                }
            }
            ListNode *nxt = tail->next;
            pair < ListNode * , ListNode * > pll = myReverse(head, tail);
            head = pll.first;
            tail = pll.second;
            preHead->next = head;
            tail->next = nxt;
            preHead = tail;
            head = tail->next;

        }
        return save->next;
    }
};
