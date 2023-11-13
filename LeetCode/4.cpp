// 给你一个链表的头节点 head ，判断链表中是否有环。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

// 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
// 进阶：你能用 O(1)（即，常量）内存解决此问题吗？

#include <stdio.h>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
/* 这段代码是用来检测链表中是否存在环的。这里使用了一个被称为“快慢指针”或“龟兔赛跑”算法的技巧。这是检测链表中是否存在环的关键步骤。 */