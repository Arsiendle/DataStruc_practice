#include <stdio.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100 // 栈初始分配空间的容量
#define STACKINCREMENT 10   // 栈增加分配空间的空量
#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
typedef char SElemType;
typedef int Status;
typedef char ElemType;
typedef struct
{
    SElemType *base; // 栈的存储空间基地址 （栈底指针）
    SElemType *top;  // 指示栈顶元素的下一存储单元的位置（栈顶指针）
    int stacksize;   // 栈当前的存储空间存储容量
} SqStack;

typedef struct LNode
{ // 单链表存储结构
    ElemType data;
    struct LNode *next;
} LNode, *LinkList; // LNode结点类型名，LinkList为指向结点的指针类型名

Status LinkList_Creat(LinkList &L)
{
    ElemType node;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%c", &node);
    LinkList r = L;
    while (node != '0')
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if (!p)
            return ERROR;
        p->data = node;
        r->next = p;
        r = p;
        scanf("%c", &node);
    }
    r->next = NULL;
    return OK;
}

void LinkList_Output(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status LinkList_LocateElem(LinkList &L, int i, ElemType &le)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j < i)
        return ERROR;
    le = p->data;
    return OK;
}

Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType)); // 分配预定义空间大小
    if (!S.base)                                                       // 如果空间分配失败
    {
        printf("OVERFLOW\n");
        return ERROR;
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

// 入栈
Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base <= S.stacksize)
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base)
        {
            printf("OVERFLOW\n");
            return ERROR;
        }
    }
    *(S.top)++ = e;
    return OK;
}

// 出栈
Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)
    {
        printf("The Stack is NULL!\n");
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

// 取栈顶元素
Status GetTop(SqStack S, SElemType &e)
{
    if (S.base == S.top)
    {
        printf("The Stack is NULL!\n");
        return ERROR;
    }
    e = *(S.top - 1);
    return OK;
}

Status StackEmpty(SqStack S)
{
    if (S.base == S.top)
        return TRUE;
    else
        return FALSE;
}

Status Display(SqStack S)
{
    SElemType *p;
    if (S.base == S.top)
    {
        printf("The Stack is NULL!\n");
        return ERROR;
    }
    printf("从栈底到栈顶：");
    for (p = S.base; p < S.top; p++)
        printf("%2c", *p);
    printf("\n");
    return OK;
}

Status DestroyStack(SqStack &S)
{
    free(S.base);
    S.top = NULL;
    S.base = NULL;
    S.stacksize = 0;
    return OK;
}

Status ClearStack(SqStack &S)
{
    SElemType e;
    while (!StackEmpty(S))
    {
        Pop(S, e);
    }
    return OK;
}

int main()
{
    LinkList L;
    int i;
    ElemType le;
    SqStack S;
    SElemType e;
    bool flag = true;

    printf("请输入链表中的字符序列,以0结束:\n");
    LinkList_Creat(L);
    printf("链表中的字符序列为：\n");
    LinkList_Output(L);
    InitStack(S);
    i = 1;
    while (LinkList_LocateElem(L, i++, le))
    {
        // test
        printf("正常进行第%d次入栈操作\n", i - 1);
        printf("%c\n", le);

        Push(S, le);
    }

    Display(S);

    i = 1;
    while (!StackEmpty(S))
    {
        Pop(S, e);
        LinkList_LocateElem(L, i, le);
        if (e != le)
        {
            flag = false;
            break;
        }
        i++;
    }

    Display(S);

    if (flag == true)
        printf("此链表中的字符序列构成回文");
    else
        printf("此链表中的字符序列不构成回文");
    return 0;
}
