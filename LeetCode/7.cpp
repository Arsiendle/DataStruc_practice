// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

#include <malloc.h>
#include <stdio.h>
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    int carry = 0;
    while (l1 || l2)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = sum % 10;
        p = p->next;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }
    if (carry)
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = carry;
        p = p->next;
    }
    p->next = NULL;
    return head->next;
}