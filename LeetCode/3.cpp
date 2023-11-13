// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
// 进阶：你能否用 O(n)时间复杂度和 O(1) 空间复杂度解决此题？

#include <stdio.h>
#include <stdlib.h>
//   Definition for singly-linked list.
typedef struct Nodeptr
{
    int val;
    struct Nodeptr *next;
} MyNode, *Node;

Node newNode(int val)
{
    Node node = (Node)malloc(sizeof(MyNode));
    if (!node)
    {
        printf("malloc failed\n");
        exit(1);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

bool isPalindrome(Node head)
{
    if (!head || !head->next)
        return true;
    Node l = head;
    int size = 0;
    while (l)
    {
        size++;
        l = l->next;
    }

    Node p = head, s = NULL, r = NULL;
    for (int i = 0; i < size / 2; i++)
    {
        r = s;
        s = p;
        p = p->next;
        s->next = r;
    }
    if (size % 2 == 1)
        p = p->next;
    while (p && s)
    {
        if (p->val != s->val)
            return false;
        p = p->next;
        s = s->next;
    }
    return true;
}

/**
 * @brief 遍历结点
 *
 * @param MyNode 需要遍历的首个结点
 */
void iterNode(Node head)
{
    Node p = head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

int main()
{
    Node head = newNode(1);
    Node n1 = newNode(2);
    Node n2 = newNode(1);
    Node n3 = newNode(2);
    Node n4 = newNode(1);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    isPalindrome(head) ? printf("true\n") : printf("false\n");

    return 0;
}