/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0,head);
        if(head==nullptr)return nullptr;
        if(head->next==nullptr)return head;
        ListNode* res = dummyHead;
        ListNode* first = head;
        ListNode* second = head->next;
        while (first!=nullptr&&second!=nullptr) {
            first->next = second->next;
            second->next = first;
            dummyHead->next = second;
            dummyHead = first;
            first = dummyHead->next;
            if(first!=nullptr){
                second = first->next;
            }
        }
        return res->next;
    }
};
// @lc code=end

