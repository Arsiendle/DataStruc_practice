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

typedef struct linkedListStack
{
    Node top;
    int size;
} myStack, *Stack;

Stack newStack()
{
    Stack stack = (Stack)malloc(sizeof(myStack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

bool push(Stack stack, int val)
{
    Node node = newNode(val);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    return true;
}

int pop(Stack stack)
{
    if (stack->size == 0)
        return -1;
    Node temp = stack->top;
    stack->top = temp->next;
    int val = temp->data;
    free(temp);
    stack->size--;
    return val;
}

int main()
{
    Stack stack = newStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    return 0;
}