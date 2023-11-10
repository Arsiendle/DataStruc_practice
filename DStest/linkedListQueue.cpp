#include <stdio.h>
#include <malloc.h>

typedef struct Nodeptr
{
    int data;
    struct Nodeptr *next;
} myNode, *Node;

Node newNode(int val)
{
    Node node = (Node)malloc(sizeof(myNode));
    node->data = val;
    node->next = NULL;
    return node;
}

typedef struct linkedListQueue
{
    Node top;
    int size;
} myQueue, *Queue;

Queue newQueue()
{
    Queue queue = (Queue)malloc(sizeof(myQueue));
    queue->top = NULL;
    queue->size = 0;
    return queue;
}

bool push(Queue queue, int val)
{
    Node node = newNode(val);
    node->next = queue->top;
    queue->top = node;
    queue->size++;
    return true;
}

int pop(Queue queue)
{
    if (queue->size == 0)
        return -1;
    Node temp = queue->top;
    queue->top = temp->next;
    int val = temp->data;
    free(temp);
    queue->size--;
    return val;
}

int main()
{
    Queue queue = newQueue();
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    printf("%d\n", pop(queue));
    printf("%d\n", pop(queue));
    printf("%d\n", pop(queue));
    printf("%d\n", pop(queue));
    return 0;
}