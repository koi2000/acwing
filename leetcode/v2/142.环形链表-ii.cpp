/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && slow != nullptr) {
            if (slow->next != nullptr) {
                slow = slow->next;
            } else {
                return nullptr;
            }
            if (fast->next != nullptr && fast->next->next != nullptr) {
                fast = fast->next->next;
            } else {
                return nullptr;
            }
            if (fast == slow) {
                ListNode* ptr = head;
                while(ptr!=slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
// @lc code=end

