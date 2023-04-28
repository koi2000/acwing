//
// Created by DELL on 2023/4/28.
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
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write code here
        ListNode *save = head;
        while (head != nullptr) {
            ListNode *tp = head->next;
            while (tp != nullptr) {
                if (tp->val == head->val) {
                    tp = tp->next;
                } else {
                    break;
                }
            }
            head->next = tp;
            head = head->next;
        }
        return save;
    }
};
