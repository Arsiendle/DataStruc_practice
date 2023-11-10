#include <stdio.h>
#include <stdlib.h>

// 双向循环链表的结点类型定义
typedef int ElemType;
typedef struct DuLNode
{
    ElemType data;         // 存放猴子的编号
    struct DuLNode *prior; // 前驱指针域
    struct DuLNode *next;  // 后继指针域
} CDLNode, *CDLinkList;

void CDLinkList_create(CDLinkList &L, int n)
{
    // 用尾插法创建一个不带头结点的长度为n的双向循环链表L(L为链表头指针）
    CDLinkList p, r;
    L = r = (CDLinkList)malloc(sizeof(CDLNode));
    L->data = 1; // 创建了链表中的第1个结点
    n--;         // 需创建的结点数减1
    int i = 2;   // 接下来是从编号为2的结点开始，依次将其并加入链表中
    while (n--)
    {
        p = (CDLinkList)malloc(sizeof(CDLNode));
        p->data = i;
        r->next = p;
        p->prior = r;
        r = p;
        i++;
    }
    r->next = L; // 链表的首尾相连
    L->prior = r;
}

void Pking_m(CDLinkList &L, CDLinkList &start, int m, CDLinkList &p)
{
    // 从L中的start位置开始顺时针报数，将报到m的结点删除，并通过p返回被删结点的后继
    CDLinkList q = start; // q指示当前报到数的结点，从start所指结点开始
    int num = 1;
    while (num != m) // 顺时针报数
    {
        q = q->next; // 指针顺时针方向移动
        num++;
    }
    printf("%2d号猴子 出圈\n", q->data);
    p = q->next;        // 通过p返回待删除结点的后继
    q->prior->next = p; // 修改指针，删除q所指示的结点
    p->prior = q->prior;
    if (q == L)      // 如果被删结点是头结点
        L = q->next; // 将头指针移动被删结点的后继
    free(q);
}

void Pking_k(CDLinkList &L, CDLinkList &start, int k, CDLinkList &p)
{
    // 从L中的start位置开始逆时针报数，将报到k的结点删除，并通过p返回被删结点的前驱
    CDLinkList q = start; // q指示当前报到数的结点，从start所指结点开始
    int num = 1;
    while (num != k) // 逆时针报数
    {
        q = q->prior; // 指针逆时针方向移动
        num++;
    }
    printf("%2d号猴子 出圈\n", q->data);
    p = q->prior;      // 通过p返回待删除结点q的前驱
    p->next = q->next; // 修改指针，删除q所指示的结点
    q->next->prior = p;
    if (q == L)      // 如果被删结点是头结点
        L = q->next; // 将头指针移动被删结点的后继
    free(q);
}

void Pking_Double(CDLinkList &L, int length, int m, int k)
{
    // 模拟猴子双向选王游戏，参数L为双向循环链表，length为猴子总数，m、k为顺时针和逆时针报到要出圈的数
    CDLinkList p, start = L;
    while (length > 1) // 重复双向报数，直到链表中只剩总人数的一半
    {
        Pking_m(L, start, m, p); // 顺时针报数
        length--;
        if (length > 1) // 判断当前链表中剩下的结点数是否大于1
        {
            start = p;
            Pking_k(L, start, k, p); // 逆时针报数
            start = p;
            length--;
        }
    }
    printf("\n最后当选为猴王的是：%d号猴子\n", L->data);
}

int main()
{
    CDLinkList L = NULL;
    int length, m, k; // length为总猴子数，m、k为正反向报到出圈的数
    printf("请输入总猴子数：");
    scanf("%d", &length);
    CDLinkList_create(L, length); // 创建长度为length的双向循环链表L

    printf("请输入顺时针报数到第几个要出圈:");
    scanf("%d", &m);
    printf("请输入逆时针报数到第几个要出圈:");
    scanf("%d", &k);
    Pking_Double(L, length, m, k); // 猴子双向选王游戏

    return 0;
}