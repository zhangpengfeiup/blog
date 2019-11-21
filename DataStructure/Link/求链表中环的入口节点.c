### 求链表中环的入口节点
// 思路可以参考 https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
// 代码参考 https://leetcode.com/problems/linked-list-cycle-ii/discuss/129071/4ms-16lines-C-solution-beats-100

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow,*fast;
    slow = fast = head;
    
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // found node meeting
            fast = head;
            
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}