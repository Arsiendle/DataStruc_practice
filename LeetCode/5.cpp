// 给定一个链表的头节点 head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 不允许修改 链表。
// 进阶：你是否可以使用 O(1) 空间解决此题？

#include <stdio.h>
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head, *meet = head;
    int index = 0;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        index++;
        if (fast == slow)
        {
            fast = head;
            while (meet != slow)
            {
                meet = meet->next;
                slow = slow->next;
            }
            return meet;
        }
    }
    return NULL;
}