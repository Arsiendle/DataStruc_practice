#include <stdio.h>
#include <malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCERMENT 10
#define ERROR 0
#define OK 1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType *elem; // �洢Ԫ�ص�����ָ��
    int length;     // ��ǰ����Ԫ�صĸ���
    int listsize;   // ��ǰ����Ĵ洢�ռ���������Ԫ��Ϊ��λ��
} SqList;

/**
 * @brief ����˳���
 *
 * @param L ˳������
 * @param n ��ĳ���
 * @return Status ״̬�룬OK��ʾ�ɹ���OVERFLOW��ʾ�ڴ����
 */
Status SqList_Create(SqList &L, int n)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType)); // �����ʼ�洢�ռ�
    if (!L.elem)
    {
        return OVERFLOW;
    }
    L.listsize = LIST_INIT_SIZE;
    L.length = n;
    for (int i = 0; i < L.length; i++)
    {
        scanf("%d", &L.elem[i]); // �������Ԫ�ص�ֵ
    }
    return OK;
}

/**
 * @brief ����Ԫ��
 *
 * @param L ˳������
 * @param i ����λ��
 * @param e �������Ԫ��
 * @return Status ״̬�룬OK��ʾ�ɹ���ERROR��ʾ����λ�ô���OVERFLOW��ʾ�ڴ����
 */
Status SqList_Insert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
    {
        return ERROR; // ����λ�ò��Ϸ�
    }
    if (L.length >= L.listsize)
    {
        return OVERFLOW; // �洢�ռ��������޷�����
    }
    for (int j = L.length; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j]; // ������λ�ü�֮���Ԫ�غ���һλ
    }
    L.elem[i - 1] = e; // �ڲ���λ�ò�����Ԫ��
    L.length++;        // ��������
    return OK;
}

/**
 * @brief ɾ��Ԫ��
 *
 * @param L ˳������
 * @param i ɾ��Ԫ��λ��
 * @param e ��ɾ����Ԫ�ص�ֵ
 * @return Status ״̬�룬OK��ʾ�ɹ���ERROR��ʾɾ��λ�ô���
 */
Status SqList_Delete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR; // ɾ��λ�ò��Ϸ�
    }
    e = L.elem[i - 1]; // ����ɾ����Ԫ�ص�ֵ���浽e��
    for (int j = i; j <= L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j]; // ��ɾ��λ��֮���Ԫ��ǰ��һλ
    }
    L.length--; // ���ȼ���
    return OK;
}

/**
 * @brief ����Ԫ��
 *
 * @param L ˳������
 * @param e �����ҵ�Ԫ��ֵ
 * @return int Ԫ���ڱ��е�λ�ã�0��ʾδ�ҵ�
 */
int SqList_Search(SqList L, ElemType e)
{
    int i;
    for (i = 1; i <= L.length && L.elem[i - 1] != e; i++)
        ;

    if (i <= L.length)
    {
        return i; // ����Ԫ���ڱ��е�λ��
    }
    else
        return 0; // δ�ҵ�Ԫ��
}

/**
 * @brief ���˳����е�Ԫ��
 *
 * @param L ˳������
 */
void SqList_Output(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]); // ������Ԫ�ص�ֵ
    }
    printf("\n");
}

int main()
{
    SqList L;
    int i, n;
    ElemType e;

    // �����ĳ���
    scanf("%d", &n);
    // ������L
    SqList_Create(L, n);
    // ������
    SqList_Output(L);
    // �������λ��
    scanf("%d", &i);
    // �������Ԫ��
    scanf("%d", &e);

    if (SqList_Insert(L, i, e) == 1)
    {
        SqList_Output(L);
    }
    else
        printf("Insertion failed!\n");

    scanf("%d", &i);
    // ������Ҫɾ����λ��
    if (SqList_Delete(L, i, e) == 1)
    {
        SqList_Output(L);
        printf("%d\n", e);
    }
    else
        printf("Deletion failed!\n");

    scanf("%d", &e);
    // ������Ҫ���ҵ�Ԫ��
    if (SqList_Search(L, e))
    {
        printf("%d Search succeeded!\n", SqList_Search(L, e));
    }
    else
        printf("Search failed!\n");
    return 0;
}