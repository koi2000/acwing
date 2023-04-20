//
// Created by DELL on 2023/4/19.
//
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
#include <cstddef>

class Solution {
public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = nullptr;
        ListNode *p = pHead;
        ListNode *s = nullptr;
        while (p != nullptr) {
            s = p;
            p = p->next;
            s->next = dummyHead->next;
            dummyHead->next = s;
        }
        return dummyHead->next;
    }
};
