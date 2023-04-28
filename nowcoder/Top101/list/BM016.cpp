//
// Created by DELL on 2023/4/28.
//
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            //遇到相邻两个节点值相同
            if (cur->next->val == cur->next->next->val) {
                int temp = cur->next->val;
                //将所有相同的都跳过
                while (cur->next != nullptr && cur->next->val == temp)
                    cur->next = cur->next->next;
            } else
                cur = cur->next;
        }
        //返回时去掉表头
        return dummyHead->next;
    }
};

