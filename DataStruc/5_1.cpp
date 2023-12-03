#include <stdio.h>
#include <stdlib.h>

typedef struct ptrNode
{
    char data;
    struct ptrNode *left;
    struct ptrNode *right;
} treeNode, *Node;

Node newNode(char data)
{
    Node node = (Node)malloc(sizeof(treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(Node root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

Node createTree(char *&p)
{
    if (*p == '#')
    {
        p++;
        return NULL;
    }
    else
    {
        Node root = newNode(*p);
        p++;
        root->left = createTree(p);
        root->right = createTree(p);
        return root;
    }
}

int main()
{
    char *str = "1#48##9##";
    Node root = createTree(str);
    preOrder(root);
    free(root);
    return 0;
}