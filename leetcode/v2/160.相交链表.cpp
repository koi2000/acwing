/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    // 将题目的语义丰富一下，链表中可能回有环
    // 获得带环链表的第一个节点
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
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
    // 判断链表是否有环
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && slow != nullptr) {
            if (slow->next != nullptr) {
                slow = slow->next;
            } else {
                return false;
            }
            if (fast->next != nullptr && fast->next->next != nullptr) {
                fast = fast->next->next;
            } else {
                return false;
            }
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 情况有几种
        // 第一种，两个链表都有环，则拿到两个链表的入环节点，若是同一个，则说明有公共节点
        // 若不是同一个，则说明没有公共节点
        // 同一个则将入口当做链表尾，执行无环的求交
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pa = headA;
        ListNode *pb = headB;

        while (pa != pb) {
            if (pa == nullptr) {
                pa = headB;
            } else {
                pa = pa->next;
            }
            if (pb == nullptr) {
                pb = headA;
            } else {
                pb = pb->next;
            }
        }
        return pa;
    }
};
// @lc code=end
