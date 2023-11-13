#include <stdlib.h>
#include <stdio.h>

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

int main()
{
    Node node = newNode(1);
    node->next = (Node)malloc(sizeof(MyNode));
    return 0;
}