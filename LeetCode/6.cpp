// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

// Definition for singly-linked list.
#include <malloc.h>
#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

/* struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            p->next = list1;
            list1 = list1->next;
        }
        else
        {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    p->next = list1 ? list1 : list2;
    return head->next;
}
 */
// 递归
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main()
{
    // 创建链表list1 1->2->4
    struct ListNode *list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;
    // 创建链表list2 1->3->4
    struct ListNode *list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;
    // 合并两个链表
    struct ListNode *list = mergeTwoLists(list1, list2);
    // 打印合并后的链表
    while (list)
    {
        printf("%d ", list->val);
        list = list->next;
    }
    return 0;
}