/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include<bits/stdc++.h>
using namespace std;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* cntLen = head;
        int len = 0;
        while (cntLen!=nullptr) {
            cntLen = cntLen->next;
            len++;
        }
        n = len - n;
        dummyHead->next = head;
        ListNode* res = dummyHead;
        while (n--) {
            dummyHead = dummyHead->next;
        }
        dummyHead->next = dummyHead->next->next;
        return res->next;

        // int cnt = n;
        // while (cnt--&&fast!=nullptr) {
        //     fast = fast->next;
        // }
        // if(cnt>0) return head;
        // if(fast==nullptr) return nullptr;
        // while (fast->next!=nullptr) {
        //     fast = fast->next;
        //     slow = slow->next;
        // }
        // slow->next = slow->next->next;
        // cout<<slow->val<<endl;
        // return head;
    }
};
// @lc code=end
