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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 // 计算两个链表的长度，然后计算长度的差值，然后让比较长的链表先走差值的步数，然后进行比较
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    if (!headA || !headB) {
         return NULL;
    }    
    // a 的len
    // b 的len
    int lenA = 0,lenB = 0,differ;
    struct ListNode *a,*b;
    a = headA;
    b = headB;
    
    while (a) {
        lenA++;
        a = a->next;
    }
    
    while (b) {
        lenB++;
        b = b->next;
    }
    
    // 计算出长度以后，将a和b重新指向head头结点
    a = headA;
    b = headB;
    
    if (lenA >= lenB) {
        differ = lenA - lenB;
        // A 先走
        while (differ--) {
            a = a->next;
        }
    }else {
        differ = lenB - lenA;
        // B 先走differ
         while (differ--) {
             b = b->next;
         }   
    }
    
     // a 和 b 同时走
    while (a && b && a != b) {
        a = a->next;
        b = b->next;
    }
    
    if (a == b) {
        return a;
    }
    
    return NULL;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 // 比较巧妙的方式，如果链表有环的话，一个链表走到结尾，然后从另一个链表的头开始走，另一个链表也是如此，那么他们走过相同的步数，如果有环的话，他们会在某个节点相遇，如果没有环的话，他们最后等走到空节点这个时候也会相遇
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) {
        return NULL;
    }
    struct ListNode *a,*b;
    a = headA;
    b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}
