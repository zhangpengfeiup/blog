/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
// 暴力求解判断链表b中的节点是否与a中的结点是否相等
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a,*b;
    a = headA;
  
    if (!headA || !headB) {
        return NULL;
    }

    while (a) {
         b = headB;
        while (b) {
            if (a == b) {
                return a;
            }
            b=b->next;
        }
        a = a->next;
    }
    return NULL;
}