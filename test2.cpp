#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树结点结构体
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 根据先根遍历序列和中根遍历序列构建二叉树
TreeNode *buildTree(char *preOrder, char *inOrder, int length)
{
    if (length <= 0)
    {
        return NULL;
    }

    // 创建根结点
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = preOrder[0];
    root->left = NULL;
    root->right = NULL;

    // 在中根遍历序列中找到根结点的位置
    int rootIndex = 0;
    while (rootIndex < length && inOrder[rootIndex] != preOrder[0])
    {
        rootIndex++;
    }

    // 递归构建左子树和右子树
    root->left = buildTree(preOrder + 1, inOrder, rootIndex);
    root->right = buildTree(preOrder + rootIndex + 1, inOrder + rootIndex + 1, length - rootIndex - 1);

    return root;
}

// 输出二叉树的正向树型结构
void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // 创建一个队列用于层次遍历
    TreeNode **queue = (TreeNode **)malloc(sizeof(TreeNode *) * 1000);
    int front = -1;
    int rear = -1;

    // 将根结点入队
    queue[++rear] = root;
    int currentLevelNodeCount = 1;
    int nextLevelNodeCount = 0;

    while (front != rear)
    {
        TreeNode *currentNode = queue[++front];

        // 输出空格，使得节点相对于其父节点对齐
        for (int i = 0; i < front; i++)
        {
            printf("    ");
        }

        printf("%c", currentNode->data);

        // 将当前结点的左右子结点入队
        if (currentNode->left != NULL)
        {
            queue[++rear] = currentNode->left;
            nextLevelNodeCount++;
        }
        if (currentNode->right != NULL)
        {
            queue[++rear] = currentNode->right;
            nextLevelNodeCount++;
        }

        // 当前层级的结点已经全部输出
        if (--currentLevelNodeCount == 0)
        {
            printf("\n");
            currentLevelNodeCount = nextLevelNodeCount;
            nextLevelNodeCount = 0;
        }
    }

    free(queue);
}

// 输出二叉树的逆时针旋转90度的树型结构
void printTreeRotated(TreeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    // 输出右子树
    printTreeRotated(root->right, level + 1);

    // 输出当前结点
    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%c\n", root->data);

    // 输出左子树
    printTreeRotated(root->left, level + 1);
}

// 输出二叉树中的所有叶结点
void printLeafNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        printf("%c ", root->data);
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// 查找指定叶结点到根结点的路径
int findPath(TreeNode *root, char target, char *path, int index)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == target)
    {
        path[index] = root->data;
        return 1;
    }

    if (findPath(root->left, target, path, index + 1) || findPath(root->right, target, path, index + 1))
    {
        path[index] = root->data;
        return 1;
    }

    return 0;
}

// 层次遍历打印树形结构
void printTreeLevel(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // 创建一个队列用于存储结点
    TreeNode *queue[100];
    int front = 0;
    int rear = 0;

    // 根结点入队
    queue[rear++] = root;

    while (front < rear)
    {
        // 出队并打印结点
        TreeNode *node = queue[front++];
        printf("%c ", node->data);

        // 左子树入队
        if (node->left != NULL)
        {
            queue[rear++] = node->left;
        }

        // 右子树入队
        if (node->right != NULL)
        {
            queue[rear++] = node->right;
        }
    }
}

int main()
{
    int n;
    printf("请输入二叉树的结点总数：");
    scanf("%d", &n);

    char preOrder[n];
    char inOrder[n];

    printf("请输入二叉树的先根遍历序列：");
    scanf("%s", preOrder);

    printf("请输入二叉树的中根遍历序列：");
    scanf("%s", inOrder);

    TreeNode *root = buildTree(preOrder, inOrder, n);

    printf("二叉树的正向树型结构：\n");
    printTree(root);

    printf("二叉树的逆时针旋转90度的树型结构：\n");
    printTreeRotated(root, 0);

    printf("二叉树中的所有叶结点：");
    printLeafNodes(root);
    printf("\n");

    printf("层次遍历打印树形结构：\n");
    printTreeLevel(root);
    printf("\n");

    char target;
    printf("请输入要查询的叶结点的数据域值：");
    scanf(" %c", &target);

    char path[n];
    int found = findPath(root, target, path, 0);
    if (found)
    {
        printf("指定叶结点到根结点的路径：");
        for (int i = 0; i < n; i++)
        {
            if (path[i] != '\0')
            {
                printf("%c ", path[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("指定的叶结点不存在或不是叶结点。\n");
    }

    return 0;
}