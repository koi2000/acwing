//
// Created by DELL on 2023/4/28.
//
class Solution {
public:
    //合并两段有序链表
    ListNode* merge(ListNode* pHead1, ListNode* pHead2) {
        //一个已经为空了，直接返回另一个
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        //加一个表头
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        //两个链表都要不为空
        while (pHead1 && pHead2) {
            //取较小值的节点
            if (pHead1->val <= pHead2->val) {
                cur->next = pHead1;
                //只移动取值的指针
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                //只移动取值的指针
                pHead2 = pHead2->next;
            }
            //指针后移
            cur = cur->next;
        }
        //哪个链表还有剩，直接连在后面
        if (pHead1)
            cur->next = pHead1;
        else
            cur->next = pHead2;
        //返回值去掉表头
        return head->next;
    }

    ListNode* sortInList(ListNode* head) {
        //链表为空或者只有一个元素，直接就是有序的
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* left = head;
        ListNode* mid = head->next;
        ListNode* right = head->next->next;
        //右边的指针到达末尾时，中间的指针指向该段链表的中间
        while (right != NULL && right->next != NULL) {
            left = left->next;
            mid = mid->next;
            right = right->next->next;
        }
        //左边指针指向左段的左右一个节点，从这里断开
        left->next = NULL;
        //分成两段排序，合并排好序的两段
        return merge(sortInList(head), sortInList(mid));
    }
};

