// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
// 链表中节点的数目范围是[0, 5000]
// - 5000 <= Node.val <= 5000

//  Definition for singly-linked list.
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 结点
 * @param  val  值
 * @param  next 下一个结点
 */
typedef struct Nodeptr
{
    int val;
    struct Nodeptr *next;
} MyNode, *Node;

/**
 * @brief 创建结点
 * @param  val  值
 * @return  MyNode 节点
 */
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

Node reverseList(Node head)
{
    if (!head || !head->next)
    {
        return head;
    }
    Node p = head, s = NULL, r = NULL;
    while (p)
    {
        r = s;
        s = p;
        p = p->next;
        s->next = r;
        // p于2时,移到3,2的next指向1
    }
    return s;
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
    Node head = newNode(0);
    Node n1 = newNode(1);
    Node n2 = newNode(2);
    Node n3 = newNode(3);
    Node n4 = newNode(4);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    iterNode(reverseList(head));

    return 0;
}