#include <stdlib.h>
#include <stdio.h>

/**
 * @brief 结点
 * @param  val  值
 * @param  next 下一个结点
 */
typedef struct MyNode
{
    int val;
    struct MyNode *next;
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

/**
 * @brief 链表
 * @param head 头结点
 * @param size 链表大小
 */
typedef struct
{
    Node head;
    int size;
} LinkedList, *List;

/**
 * @brief 创建链表
 * @param  head 头结点
 * @param  size 链表大小
 * @return List
 */
List newList()
{
    List list = (List)malloc(sizeof(LinkedList));
    if (!list)
    {
        printf("malloc failed\n");
        exit(1);
    }
    list->head = (Node)malloc(sizeof(MyNode));
    list->head->next = NULL;
    list->size = 0;
    return list;
}

/**
 * @brief 追加结点 增
 *
 * @param list
 * @param val 追加的值
 * @return true
 * @return false
 */
bool appendNode(List list, int val)
{
    Node node = newNode(val);
    Node p = list->head;
    for (int i = 0; i < list->size; i++)
    {
        p = p->next;
    }
    p->next = node;
    node->next = list->head->next;
    list->size++;
    return true;
}

/**
 * @brief 删除MyNode之后的首个结点 删
 *
 * @param i 删除位置
 * @return true
 * @return false
 */
int delNode(List list, int i)
{
    if (i > list->size)
    {
        printf("del failed\n");
        return false;
    }
    Node p = list->head;
    for (int j = 0; j < i - 1; j++)
    {
        if (!p->next)
        {
            printf("del failed\n");
            return false;
        }
        p = p->next;
    }
    Node temp = p->next;
    p->next = temp->next;
    if (i == 1)
    {
        list->head->next = p;
    }
    int key = temp->val;
    free(temp);
    list->size--;
    return key;
}

/**
 * @brief 插入结点 插
 *
 * @param i 插入位置
 * @param val 插入的值
 * @return true
 * @return false
 */
bool insertNode(List list, int i, int val)
{
    if (i > list->size + 1)
    {
        printf("insert failed\n");
        return false;
    }
    Node p = list->head, node = newNode(val);
    for (int j = 0; j < i - 1; j++)
    {
        if (!p->next)
        {
            printf("insert failed\n");
            return false;
        }
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    list->size++;
    return true;
}

/**
 * @brief 遍历结点
 *
 * @param MyNode 需要遍历的首个结点
 */
void iterNode(List list)
{
    Node p = list->head;
    for (int i = 0; i < list->size; i++)
    {
        p = p->next;
        printf("%d\n", p->val);
    }
}

int main()
{
    List list = newList();
    appendNode(list, 0);
    appendNode(list, 1);
    appendNode(list, 2);
    appendNode(list, 3);
    appendNode(list, 4);

    insertNode(list, 6, 9);

    printf("del:%d\n", delNode(list, 9));

    iterNode(list);

    printf("size: %d\n", list->size);

    return 0;
}