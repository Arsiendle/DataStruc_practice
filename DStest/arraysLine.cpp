// 做栈时候,引入base,base++往后读

#include <stdio.h>
#include <malloc.h>
typedef struct
{
    int *data, size, capacity, base;
} arraysLine, *Line;

Line newLine()
{
    Line line = (Line)malloc(sizeof(arraysLine));
    line->capacity = 5;
    line->data = (int *)malloc(sizeof(int) * line->capacity);
    line->base = 0;
    line->size = 0;
    return line;
}

void extendCapacity(Line line)
{
    int newCapacity = line->capacity + 5;
    int *newData = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = line->data;
    for (int i = 0; i < line->size; i++)
        newData[i] = line->data[i];
    free(temp);
    line->data = newData;
    line->capacity = newCapacity;
}

bool push(Line line, int val)
{
    if (line->size == line->capacity)
        extendCapacity(line);
    line->data[line->size++] = val;
    return true;
}

// /**
//  * @brief 栈 pop
//  * @param stack
//  * @return int
//  */
// int pop(Line line)
// {
//     if (line->size == 0)
//         return -1;
//     return line->data[--line->size];
// }

/**
 * @brief 队列 pop
 * @param queue
 * @return int
 */
int pop(Line line)
{
    if (line->size == 0)
        return -1;
    return line->data[line->base++];
}

void iter(Line line)
{
    for (int i = 0; i < line->size; i++)
        printf("%d ", line->data[i]);
    printf("\n");
}

int main()
{
    Line line = newLine();
    push(line, 1);
    push(line, 2);
    push(line, 3);
    push(line, 4);
    push(line, 5);
    push(line, 6);
    printf("%d\n", pop(line));
    iter(line);
    return 0;
}