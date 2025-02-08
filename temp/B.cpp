#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {
    int n;
    scanf("%d", &n);  // 读取链表的数量
  
    // 动态分配链表数组的空间
    struct ListNode** lists = (ListNode**)malloc(n * sizeof(struct ListNode*)); 

    for (int i = 0; i < n; ++i) {
        int listSize;
        scanf("%d", &listSize); // 读取单个链表的大小

        struct ListNode* head = NULL;
        struct ListNode* current = NULL;
  
        // 读取链表的所有节点值
        for(int j = 0; j < listSize; j++) {
            int num;
            scanf("%d", &num);
  
            struct ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
            node->val = num;
            node->next = NULL;
  
            if (head == NULL) {
                head = node;
                current = node;
            } else {
                current->next = node;
                current = node;
            }
        }
        lists[i] = head;
    }
    return 0;
}
