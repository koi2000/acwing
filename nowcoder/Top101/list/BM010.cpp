//
// Created by DELL on 2023/4/28.
//
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) return nullptr;
        ListNode *h1 = pHead1;
        ListNode *h2 = pHead2;
        int flag = 0;
        while (h1 != h2) {
            if (flag >= 3)break;
            if (h1->next == nullptr) {
                h1 = pHead2;
                flag++;
            } else {
                h1 = h1->next;
            }
            if (h2->next == nullptr) {
                h2 = pHead1;
                flag++;
            } else {
                h2 = h2->next;
            }
        }
        return flag >= 3 ? nullptr : h1;
    }
};

