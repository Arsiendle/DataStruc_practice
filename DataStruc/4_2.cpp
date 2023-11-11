#include <malloc.h>
#include <stdio.h>
typedef struct
{
    int *data;
    int size, bottom, top, capacity;
} myLine, *Line;

Line newLine(int n)
{
    Line line = (Line)malloc(sizeof(myLine));
    line->data = (int *)malloc(sizeof(int) * n);
    line->top = line->bottom = 0;
    line->capacity = n;
    line->size = 0;
    return line;
}

bool push(Line line, int val)
{
    line->data[(line->top++) % line->capacity] = val;
    line->size++;
    return true;
}

int pop_Stack(Line line)
{
    if (line->size == 0)
        return -1;
    line->size--;
    return line->data[--line->top];
}

int pop_Queue(Line line)
{
    if (line->size == 0)
        return -1;
    line->size--;
    return line->data[(line->bottom++) % (line->capacity)];
}

int matching(Line Stack, Line Queue)
{
    int temp1, temp2, index = Stack->size;
    while (Stack->size && index)
    {
        temp1 = pop_Stack(Stack);
        temp2 = pop_Queue(Queue);
        if (temp1 == temp2)
        {
            index = Stack->size;
            continue;
        }
        else
        {
            push(Stack, temp1);
            push(Queue, temp2);
            index--;
        }
    }
    return Stack->size;
}

int main()
{
    int n;
    scanf("%d", &n);
    Line Queue = newLine(n);
    printf("初始化学生队列\n");
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(Queue, temp);
    }
    Line Stack = newLine(n);
    printf("初始化面包栈\n");
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(Stack, temp);
    }
    switch (matching(Stack, Queue))
    {
    case 0:
        printf("所有同学都吃到午餐\n");
        break;
    default:
        printf("还有%d位同学没吃到午餐\n", Stack->size);
        break;
    }
}