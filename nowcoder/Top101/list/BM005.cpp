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

    //两个有序链表合并函数
    ListNode *Merge2(ListNode *pHead1, ListNode *pHead2) {
        //一个已经为空了，直接返回另一个
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;
        //加一个表头
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
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

    //划分合并区间函数
    ListNode *divideMerge(vector<ListNode *> &lists, int left, int right) {
        if (left > right)
            return NULL;
            //中间一个的情况
        else if (left == right)
            return lists[left];
        //从中间分成两段，再将合并好的两段合并
        int mid = (left + right) / 2;
        return Merge2(divideMerge(lists, left, mid), divideMerge(lists, mid + 1,
                                                                 right));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return divideMerge(lists, 0, lists.size() - 1);
    }
};