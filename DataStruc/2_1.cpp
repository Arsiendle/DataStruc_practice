#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

// 单个结点
typedef struct LNode
{
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;

// 尾插法建立单链表
Status LinkList_Creat(LinkList &L)
{
    ElemType length;
    ElemType node;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    printf("请输入列表长度\n");
    scanf("%d", &length);

    LinkList r = L;

    printf("请输入列表元素\n");
    for (int i = 0; i < length; i++)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if (!p)
            return ERROR;
        scanf("%d", &node);
        p->data = node;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return OK;
}

// 输出单链表
void LinkList_Output(LinkList L)
{
    LinkList p = L->next;
    printf("单链表为: \n");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * @brief 插入结点
 *
 * @param L 链表
 * @param i 插入位置
 * @param e 插入元素
 */
Status LinkList_Insert(LinkList &L, int i, ElemType e)
{
    LinkList p = L, s;
    int j = 0;
    // 寻找第i-1个结点
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    // 插入
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * @brief 删除单结点,并释放空间
 *
 * @param L 链表
 * @param i 删除元素位置
 * @param e 被删除元素(用于记录并输出)
 * @return Status
 */
Status LinkList_Delete(LinkList &L, int i, ElemType &e)
{
    LinkList p = L, q;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

/**
 * @brief 查找结点位置上的元素
 *
 * @param L 链表
 * @param i 查找位置
 * @param e 查找元素(用于记录并输出)
 * @return Status
 */
Status LinkList_LocateElem(LinkList &L, int i, ElemType &e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

Status LinkList_Merge(LinkList &L1, LinkList &L2)
{
    LinkList p = L1->next;
    LinkList q = L2->next;
    LinkList r = L1;
    while (p && q)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    r->next = p ? p : q;
    free(L2);
    return OK;
}

int main()
{
    // 创建单链表
    LinkList L;
    LinkList_Creat(L);
    // 输出单链表
    LinkList_Output(L);

    // 插入结点
    int i;
    ElemType e;
    printf("请输入插入位置\n");
    scanf("%d", &i);
    printf("请输入插入元素\n");
    scanf("%d", &e);
    if (LinkList_Insert(L, i, e))
        LinkList_Output(L);
    else
        printf("Insert failed!\n");

    // 删除结点
    printf("请输入删除位置\n");
    scanf("%d", &i);
    if (LinkList_Delete(L, i, e))
    {
        printf("已删除元素为: \n");
        LinkList_Output(L);
        printf("%d\n", e);
    }
    else
        printf("删除失败!\n");

    // 查找结点位置上的元素
    printf("请输入查找位置\n");
    scanf("%d", &i);
    if (LinkList_LocateElem(L, i, e))
        printf("%d 查找成功!\n", e);
    else
        printf("查找失败!\n");

    LinkList L1, L2;
    LinkList_Creat(L1);
    LinkList_Output(L1);
    LinkList_Creat(L2);
    LinkList_Output(L2);

    LinkList_Merge(L1, L2);
    LinkList_Output(L1);
    return 0;
}