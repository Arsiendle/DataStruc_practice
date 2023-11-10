#include <stdio.h>
#include <malloc.h>

#define EXTEND_SIZE 5

/* 列表类简易实现 */
typedef struct
{
    int *arr;       // 数组（存储列表元素）
    int capacity;   // 列表容量
    int size;       // 列表大小
} MyList, *List;

/* 构造函数 */
List newMyList()
{
    List list = (List)malloc(sizeof(MyList));
    list->capacity = 5;
    list->arr = (int *)malloc(sizeof(int) * list->capacity);
    list->size = 0;
    return list;
}

/* 列表扩容 */
void extendCapacity(List list)
{
    // 先分配空间
    int newCapacity = list->capacity + EXTEND_SIZE;
    int *newArr = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = list->arr;

    // 拷贝旧数据到新数据
    for (int i = 0; i < list->size; i++)
        newArr[i] = list->arr[i];

    // 释放旧数据
    free(temp);

    // 更新新数据
    list->arr = newArr;
    list->capacity = newCapacity;
}

/* 析构函数 */
void delList(List list)
{
    free(list->arr);
    free(list);
}

/* 访问元素 */
int get(List list, int index)
{
    return list->arr[index];
}

/* 更新元素 */
void set(List list, int index, int num)
{
    list->arr[index] = num;
}

/* 尾部添加元素 */
void add(List list, int num)
{
    if (list->size == list->capacity)
    {
        extendCapacity(list); // 扩容
    }
    list->arr[list->size] = num;
    list->size++;
}

/* 中间插入元素 */
void insert(List list, int index, int num)
{
    // 元素数量超出容量时，触发扩容机制
    if (list->size == list->capacity)
    {
        extendCapacity(list); // 扩容
    }
    for (int i = list->size; i > index; --i)
    {
        list->arr[i] = list->arr[i - 1];
    }
    list->arr[index] = num;
    list->size++;
}

/* 删除元素 */
int delItem(List list, int index)
{
    int num = list->arr[index];
    for (int i = index; i < list->size - 1; i++)
    {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
    return num;
}

/* 将列表转换为 Array 用于打印 */
void printList(List list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d\n", list->arr[i]);
    }
}

int main()
{
    List list = newMyList();

    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);

    printf("size: %d, capacity: %d\n", list->size, list->capacity);
    printf("get(2): %d\n", get(list, 2));

    set(list, 2, 10);
    printf("get(2): %d\n", get(list, 2));

    insert(list, 2, 20);
    printf("size: %d, capacity: %d\n", list->size, list->capacity);
    printf("get(2): %d\n", get(list, 2));

    delItem(list, 2);
    printf("size: %d, capacity: %d\n", list->size, list->capacity);
    printf("get(2): %d\n", get(list, 2));

    printList(list);

    delList(list);
    return 0;
}
