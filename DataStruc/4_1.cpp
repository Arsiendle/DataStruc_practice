#include <stdio.h>
#include <malloc.h>

/* 基于环形数组实现的队列 */
typedef struct
{
    int *nums;    // 用于存储队列元素的数组
    int front;    // 队首指针，指向队首元素
    int rear;     // 尾指针
    int Size;     // 长度
    int Capacity; // 队列容量
} ArrayQueue, *AQueue;

/* 构造函数 */
AQueue newArrayQueue(int capacity)
{
    AQueue queue = (AQueue)malloc(sizeof(ArrayQueue));
    // 初始化数组
    queue->Capacity = capacity;
    queue->nums = (int *)malloc(sizeof(int) * queue->Capacity);
    queue->rear = queue->front = queue->Size = 0;
    return queue;
}

/* 析构函数 */
void delArrayQueue(AQueue queue)
{
    free(queue->nums);
    free(queue);
}

/* 判断队列是否为空 */
bool empty(AQueue queue)
{
    return queue->Size == 0;
}

/* 访问队首元素 */
int peek(AQueue queue)
{
    if (queue->front == queue->rear)
    {
        printf("the Queue is NULL!\n");
        return -1;
    }
    return queue->nums[queue->front];
}

/* 入队 */
void push(AQueue queue, int num)
{
    if (queue->Size == queue->Capacity)
    {
        int *newArray = (int *)malloc((queue->Capacity + 100) * sizeof(int));
        int j = 0;
        for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->Capacity)
        {
            newArray[j] = queue->nums[i];
            j++;
        }
        newArray[j] = queue->nums[queue->rear];

        queue->Capacity += 100;
        queue->front = 0;
        queue->rear = j;

        free(queue->nums);
        queue->nums = newArray;
        return;
    }

    // 将 num 添加至队尾
    queue->nums[queue->rear] = num;
    queue->Size++;
    // 通过取余操作，实现 rear 越过数组尾部后回到头部
    queue->rear = (queue->rear + 1) % queue->Capacity;
}

/* 出队 */
int pop(AQueue queue)
{
    int num = peek(queue);
    // 队首指针向后移动一位，若越过尾部则返回到数组头部
    queue->front = (queue->front + 1) % queue->Capacity;
    queue->Size--;
    return num;
}

/* 打印队列 */
void printArrayQueue(AQueue queue)
{
    int arr[queue->Size];
    // 拷贝
    for (int i = 0, j = queue->front; i < queue->Size; i++, j++)
    {
        arr[i] = queue->nums[j % queue->Capacity];
        printf("%d\n", arr[i]);
    }
}

/* 链表节点结构体 */
/**
 * @brief 创建对象 单个子节点
 * @param key 值
 * @param next 指向下一节点的指针
 */
typedef struct ListNode
{
    int key;               // 节点值
    struct ListNode *next; // 指向下一节点的指针
} ListNode, *LNode;

/* 构造函数 */
/**
 * @brief 实例化对象 子节点
 *
 * @param key 值
 * @param node 指向当前节点的指针
 * @param next 指向下一节点的指针
 * @return LNode node
 */
LNode newListNode(int key)
{
    LNode node, *next;
    node = (LNode)malloc(sizeof(ListNode));
    node->key = key;
    node->next = NULL;
    return node;
}

/* 基于链表实现的队列 */
/**
 * @brief 创建对象 队列
 * @param front 头指针
 * @param rear 尾指针
 */
typedef struct
{
    LNode front, rear;
    int queSize;
} LinkedListQueue, *LQueue;

/* 构造函数 */
/**
 * @brief 实例化对象 队列
 * @param queue 基地址
 * @return LinkedListQueue* queue
 */
LQueue newLinkedListQueue()
{
    LQueue queue = (LQueue)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

/* 析构函数 */
void delLinkedListQueue(LQueue queue)
{
    // 释放所有节点
    for (int i = 0; i < queue->queSize && queue->front != NULL; i++)
    {
        LNode tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    // 释放 queue 结构体
    free(queue);
}

/* 获取队列的长度 */
int size(LQueue queue)
{
    return queue->queSize;
}

/* 判断队列是否为空 */
bool empty(LQueue queue)
{
    return (size(queue) == 0);
}

/* 入队 */
void push(LQueue queue, int num)
{
    // 尾节点处添加 node
    LNode node = newListNode(num);
    // 如果队列为空，则令头、尾节点都指向该节点
    if (queue->front == NULL)
    {
        queue->front = node;
        queue->rear = node;
    }
    // 如果队列不为空，则将该节点添加到尾节点后
    else
    {
        queue->rear->next = node;
        queue->rear = node;
        queue->rear->next = queue->front;
    }
    queue->queSize++;
}

/* 访问队首元素 */
int peek(LQueue queue)
{
    if (queue->front == queue->rear)
    {
        printf("the Queue is NULL!\n");
        return -1;
    }
    return queue->front->key;
}

/* 出队 */
int pop(LQueue queue)
{
    int num = peek(queue);
    LNode tmp = queue->front;
    queue->front = queue->front->next;
    queue->rear->next = queue->front;
    free(tmp);
    queue->queSize--;
    return num;
}

/* 打印队列 */
void printLinkedListQueue(LQueue queue)
{
    int arr[queue->queSize];
    // 拷贝链表中的数据到数组
    int i;
    LNode node;
    for (i = 0, node = queue->front; i < queue->queSize; i++)
    {
        printf("%d\n", node->key);
        node = node->next;
    }
}

int main()
{
    int n, e;

    // 根据输入的队列队列长度 n
    //  和各元素值e建立一个循环顺序表表示的循环队列
    printf("建立一个循环顺序队列\n");
    scanf("%d", &n);
    AQueue aque = newArrayQueue(20);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        push(aque, e);
    }
    // 输出队列中各元素值
    printf("第一次遍历\n");
    printArrayQueue(aque);
    // 将数据元素 e 入队
    printf("请输入e:\n");
    scanf("%d", &e);
    push(aque, e);
    // 输出入队后的队列中各元素值
    printf("第二次遍历\n");
    printArrayQueue(aque);
    // 将循环队列的队首元素出队
    printf("出队元素:");
    printf("%d\n", pop(aque));
    // 输出出队元素的值和出队后队列中各元素值
    printf("第三次遍历\n");
    printArrayQueue(aque);
    printf("判空:\n;");
    printf("%d\n", empty(aque));

    printf("建立一个仅用尾指针标识的循环链队\n");
    // 根据输入的队列长度n
    // 和各元素值 n 建立一个带头结点的循环链表表示的队列（循环链队列）
    scanf("%d", &n);
    LQueue queue = newLinkedListQueue();
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        push(queue, e);
    }
    // 输出队列中各元素值
    printf("第一次遍历\n");
    printLinkedListQueue(queue);
    //  将数据元素e入队
    printf("请输入e:\n");
    scanf("%d", &e);
    push(queue, e);
    // 输出入队后的队列中各元素值
    printf("第二次遍历\n");
    printLinkedListQueue(queue);
    // 将循环链队列的队首元素出队
    printf("出队元素:");
    printf("%d\n", pop(queue));
    // 输出出队元素的值和出队后队列中各元素值
    printf("第三次遍历\n");
    printLinkedListQueue(queue);
}