- 求链表的倒数第k个节点

一开始想到的方法是求出所有链表的长度len,倒数第k个节点也就是第len-k+1个节点.

后来看网上的代码，我们可以使用two point 方法进行查找，一个快指针比一个慢指针差k-1个距离，这样快的指针到了节点尾部，慢指针刚好在倒数第k个节点，具体代码如下:

```

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int data;
    struct ListNode *next;
};

// 头插法建立无头结点链表
struct ListNode* createListHead(int n) {
    struct ListNode *last,*p,*head;
    last = NULL;

    int i;
    for (i = 0;i < n;i++) {
         head = (struct ListNode *)malloc(sizeof(struct ListNode));
         scanf("%d",&head->data);
         // this is need init the node->next,otherwise the link can not stop.
         head->next = NULL;
        if (last == NULL) {
            last = head;
            p = last;
        }else {
            head->next = p;
            p = head;
        }
    }
    return head;
}

void printAllNode(struct ListNode *l) {
    if (l == NULL) {
        return NULL;
    }
    while (l) {
        printf("%d ",l->data);
        l = l->next;
    }
    printf("\n");
}

// After count the len of link,then the n-k+1 node is the k node
struct ListNode* findKNode(struct ListNode *L,int k) {
    if (L == NULL || k < 0) {
        return NULL;
    }

    int num,len = 0;
    struct ListNode *head,*p,*knode;
    p = head = L;

    while (p) {
        len++;
        p = p->next;
    }

    num = len - k + 1;

    if (num < 0) {
        return NULL;
    }

    int i;

    for (i = 0;i < num-1;i++) {
        head = head->next;
    }
    knode = head;
    return knode;
};

struct ListNode * findKNodeWithTwoPoint(struct ListNode *L,int k) {
    if (L == NULL || k < 0) {
        return NULL;
    }

    struct ListNode *ahead = L,*behind;

    int i;
    for (i = 0;i < k-1;i++) {
        if (ahead->next != NULL) {
            ahead = ahead->next;
        }else {
            return NULL;
        }
    }

    behind = L;

    while(ahead->next) {
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind;
};

int main()
{
    struct ListNode *L,*kNode;
    L = createListHead(6);
    printAllNode(L);
    kNode = findKNode(L,2);
    printf("the last 2  node data is %d\n",kNode->data);
    kNode = findKNodeWithTwoPoint(L,4);
    printf("the last 3 node data is %d\n",kNode->data);
    return 0;
}

```