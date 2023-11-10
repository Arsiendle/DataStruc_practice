#include <stdio.h>
#include <malloc.h>
typedef struct
{
    int *data, size, capacity;
} arrayStack, *Stack;

Stack newStack()
{
    Stack stack = (Stack)malloc(sizeof(arrayStack));
    stack->capacity = 5;
    stack->data = (int *)malloc(sizeof(int) * stack->capacity);
    stack->size = 0;
    return stack;
}

void extendCapacity(Stack stack)
{
    int newCapacity = stack->capacity + 5;
    int *newData = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = stack->data;
    for (int i = 0; i < stack->size; i++)
        newData[i] = stack->data[i];
    free(temp);
    stack->data = newData;
    stack->capacity = newCapacity;
}

bool push(Stack stack, int val)
{
    if (stack->size == stack->capacity)
        extendCapacity(stack);
    stack->data[stack->size++] = val;
    return true;
}

int pop(Stack stack)
{
    if (stack->size == 0)
        return -1;
    return stack->data[--stack->size];
}

void iter(Stack stack)
{
    for (int i = 0; i < stack->size; i++)
        printf("%d ", stack->data[i]);
    printf("\n");
}

int main()
{
    Stack stack = newStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    printf("%d\n", pop(stack));
    iter(stack);
    return 0;
}