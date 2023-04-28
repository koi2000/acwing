/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode *reverseList(ListNode *head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = nullptr;
        ListNode *s = nullptr;
        ListNode *p = head;
        while (p != nullptr) {
            s = p;
            p = p->next;
            s->next = dummyHead->next;
            dummyHead->next = s;
        }
        return dummyHead->next;
    }

    ListNode *listAdd(ListNode *head1, ListNode *head2) {
        int now = 0;
        int pre = 0;
        ListNode *save1 = new ListNode(0);
        ListNode *save2 = new ListNode(0);
        save1->next = head1;
        save2->next = head2;
        ListNode *newHead = new ListNode(0);
        ListNode *save = newHead;
        while (head1 != nullptr && head2 != nullptr) {
            int val = head1->val + head2->val + pre;
            now = val % 10;
            pre = val / 10;
            newHead->val = now;
            ListNode *news = new ListNode(0);
            newHead->next = news;
            newHead = newHead->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while (head1 != nullptr) {
            int val = head1->val + pre;
            now = val % 10;
            pre = val / 10;
            newHead->val = now;
            ListNode *news = new ListNode(0);
            newHead->next = news;
            newHead = newHead->next;
            head1 = head1->next;
        }
        while (head2 != nullptr) {
            int val = head2->val + pre;
            now = val % 10;
            pre = val / 10;
            newHead->val = now;
            ListNode *news = new ListNode(0);
            newHead->next = news;
            newHead = newHead->next;
            head2 = head2->next;
        }
        if (pre > 0) {
            newHead->val += pre;
        } else {
            newHead = nullptr;
        }

        return save;
    }


    ListNode *addInList(ListNode *head1, ListNode *head2) {
        // write code here
        ListNode *h1 = reverseList(head1);
        ListNode *h2 = reverseList(head2);
        ListNode *res = listAdd(h1, h2);
        res = reverseList(res);
        if (res->val == 0) {
            return res->next;
        }
        return res;
    }
};
