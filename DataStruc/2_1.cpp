#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;

// �������
typedef struct LNode
{
    ElemType data;      // ������
    struct LNode *next; // ָ����
} LNode, *LinkList;

// β�巨����������
Status LinkList_Creat(LinkList &L)
{
    ElemType length;
    ElemType node;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    printf("�������б���\n");
    scanf("%d", &length);

    LinkList r = L;

    printf("�������б�Ԫ��\n");
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

// ���������
void LinkList_Output(LinkList L)
{
    LinkList p = L->next;
    printf("������Ϊ: \n");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * @brief ������
 *
 * @param L ����
 * @param i ����λ��
 * @param e ����Ԫ��
 */
Status LinkList_Insert(LinkList &L, int i, ElemType e)
{
    LinkList p = L, s;
    int j = 0;
    // Ѱ�ҵ�i-1�����
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;
    // ����
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * @brief ɾ�������,���ͷſռ�
 *
 * @param L ����
 * @param i ɾ��Ԫ��λ��
 * @param e ��ɾ��Ԫ��(���ڼ�¼�����)
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
 * @brief ���ҽ��λ���ϵ�Ԫ��
 *
 * @param L ����
 * @param i ����λ��
 * @param e ����Ԫ��(���ڼ�¼�����)
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
    // ����������
    LinkList L;
    LinkList_Creat(L);
    // ���������
    LinkList_Output(L);

    // ������
    int i;
    ElemType e;
    printf("���������λ��\n");
    scanf("%d", &i);
    printf("���������Ԫ��\n");
    scanf("%d", &e);
    if (LinkList_Insert(L, i, e))
        LinkList_Output(L);
    else
        printf("Insert failed!\n");

    // ɾ�����
    printf("������ɾ��λ��\n");
    scanf("%d", &i);
    if (LinkList_Delete(L, i, e))
    {
        printf("��ɾ��Ԫ��Ϊ: \n");
        LinkList_Output(L);
        printf("%d\n", e);
    }
    else
        printf("ɾ��ʧ��!\n");

    // ���ҽ��λ���ϵ�Ԫ��
    printf("���������λ��\n");
    scanf("%d", &i);
    if (LinkList_LocateElem(L, i, e))
        printf("%d ���ҳɹ�!\n", e);
    else
        printf("����ʧ��!\n");

    LinkList L1, L2;
    LinkList_Creat(L1);
    LinkList_Output(L1);
    LinkList_Creat(L2);
    LinkList_Output(L2);

    LinkList_Merge(L1, L2);
    LinkList_Output(L1);
    return 0;
}