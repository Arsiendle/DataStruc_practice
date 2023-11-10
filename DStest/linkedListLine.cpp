#include <stdio.h>
#include <malloc.h>

typedef struct Nodeptr
{
    int data;
    struct Nodeptr *next;
    struct Nodeptr *last;
} myNode, *Node;

Node newNode(int val)
{
    Node node = (Node)malloc(sizeof(myNode));
    node->data = val;
    node->next = NULL;
    node->last = NULL;
    return node;
}

typedef struct linkedListLine
{
    Node top;
    Node bottom;
    int size;
} myLine, *Line;

/**
 * @brief 创建对象Line
 * @param top 栈顶
 * @param bottom 栈底
 * @return Line
 */
Line newLine()
{
    Line line = (Line)malloc(sizeof(myLine));
    line->bottom = (Node)malloc(sizeof(myNode));
    line->bottom->last = NULL;
    line->top = line->bottom;
    line->size = 0;
    return line;
}

bool push(Line line, int val)
{
    Node node = newNode(val);
    node->next = line->top;
    line->top->last = node;
    line->top = node;
    line->size++;
    return true;
}

// /**
//  * @brief 栈 pop
//  * @return int
//  */
// int pop(Line line)
// {
//     if (line->size == 0)
//     {
//         printf("line is empty\n");
//         return -1;
//     }
//     Node temp = line->top;
//     line->top = line->top->next;
//     int val = temp->data;
//     free(temp);
//     line->size--;
//     return val;
// }

/**
 * @brief 队列 pop
 * @return int
 */
int pop(Line line)
{
    if (line->size == 0)
    {
        printf("line is empty\n");
        return -1;
    }
    Node temp = line->bottom->last;
    line->bottom->last = line->bottom->last->last;
    int val = temp->data;
    free(temp);
    line->size--;
    return val;
}

int main()
{
    Line line = newLine();
    push(line, 1);
    push(line, 2);
    push(line, 3);
    printf("%d\n", pop(line));
    printf("%d\n", pop(line));
    printf("%d\n", pop(line));
    printf("%d\n", pop(line));
    return 0;
}