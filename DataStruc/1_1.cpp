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
    ElemType *elem; // 存储元素的数组指针
    int length;     // 当前表中元素的个数
    int listsize;   // 当前分配的存储空间容量（以元素为单位）
} SqList;

/**
 * @brief 建立顺序表
 *
 * @param L 顺序表对象
 * @param n 表的长度
 * @return Status 状态码，OK表示成功，OVERFLOW表示内存溢出
 */
Status SqList_Create(SqList &L, int n)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType)); // 分配初始存储空间
    if (!L.elem)
    {
        return OVERFLOW;
    }
    L.listsize = LIST_INIT_SIZE;
    L.length = n;
    for (int i = 0; i < L.length; i++)
    {
        scanf("%d", &L.elem[i]); // 逐个读入元素的值
    }
    return OK;
}

/**
 * @brief 插入元素
 *
 * @param L 顺序表对象
 * @param i 插入位置
 * @param e 待插入的元素
 * @return Status 状态码，OK表示成功，ERROR表示插入位置错误，OVERFLOW表示内存溢出
 */
Status SqList_Insert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
    {
        return ERROR; // 插入位置不合法
    }
    if (L.length >= L.listsize)
    {
        return OVERFLOW; // 存储空间已满，无法插入
    }
    for (int j = L.length; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j]; // 将插入位置及之后的元素后移一位
    }
    L.elem[i - 1] = e; // 在插入位置插入新元素
    L.length++;        // 表长度增加
    return OK;
}

/**
 * @brief 删除元素
 *
 * @param L 顺序表对象
 * @param i 删除元素位置
 * @param e 被删除的元素的值
 * @return Status 状态码，OK表示成功，ERROR表示删除位置错误
 */
Status SqList_Delete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR; // 删除位置不合法
    }
    e = L.elem[i - 1]; // 将被删除的元素的值保存到e中
    for (int j = i; j <= L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j]; // 将删除位置之后的元素前移一位
    }
    L.length--; // 表长度减少
    return OK;
}

/**
 * @brief 查找元素
 *
 * @param L 顺序表对象
 * @param e 待查找的元素值
 * @return int 元素在表中的位置，0表示未找到
 */
int SqList_Search(SqList L, ElemType e)
{
    int i;
    for (i = 1; i <= L.length && L.elem[i - 1] != e; i++)
        ;

    if (i <= L.length)
    {
        return i; // 返回元素在表中的位置
    }
    else
        return 0; // 未找到元素
}

/**
 * @brief 输出顺序表中的元素
 *
 * @param L 顺序表对象
 */
void SqList_Output(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]); // 逐个输出元素的值
    }
    printf("\n");
}

int main()
{
    SqList L;
    int i, n;
    ElemType e;

    // 输入表的长度
    scanf("%d", &n);
    // 创建表L
    SqList_Create(L, n);
    // 遍历表
    SqList_Output(L);
    // 输入插入位置
    scanf("%d", &i);
    // 输入插入元素
    scanf("%d", &e);

    if (SqList_Insert(L, i, e) == 1)
    {
        SqList_Output(L);
    }
    else
        printf("Insertion failed!\n");

    scanf("%d", &i);
    // 输入需要删除的位置
    if (SqList_Delete(L, i, e) == 1)
    {
        SqList_Output(L);
        printf("%d\n", e);
    }
    else
        printf("Deletion failed!\n");

    scanf("%d", &e);
    // 输入需要查找的元素
    if (SqList_Search(L, e))
    {
        printf("%d Search succeeded!\n", SqList_Search(L, e));
    }
    else
        printf("Search failed!\n");
    return 0;
}