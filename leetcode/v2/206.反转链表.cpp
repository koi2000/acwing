/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyHead = nullptr;
        ListNode* p = head;
        ListNode* s = nullptr;
        while (p!=nullptr) {
            s = p;
            p = p->next;
            s->next = dummyHead;
            dummyHead = s;
        }
        return s;
    }
};
// @lc code=end

