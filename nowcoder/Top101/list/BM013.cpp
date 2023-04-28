//
// Created by DELL on 2023/4/28.
//
class Solution {
public:
    //反转链表指针
    ListNode *reverse(ListNode *head) {
        //前序节点
        ListNode *prev = NULL;
        while (head != NULL) {
            //断开后序
            ListNode *next = head->next;
            //指向前序
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPail(ListNode *head) {
        //空链表直接为回文
        if (head == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        //双指针找中点
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //中点处反转
        slow = reverse(slow);
        fast = head;
        while (slow != NULL) {
            //比较判断节点值是否相等
            if (slow->val != fast->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};

