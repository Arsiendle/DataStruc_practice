#include <stdio.h>
#include <stdlib.h>

// 二叉树结点的定义
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建二叉树
TreeNode *createBinaryTree()
{
    TreeNode *root = NULL;
    char ch;
    scanf(" %c", &ch); // 读取输入的字符

    if (ch != '#')
    {
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->data = ch;
        root->left = createBinaryTree();  // 递归创建左子树
        root->right = createBinaryTree(); // 递归创建右子树
    }

    return root;
}

// 先根遍历
void preorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 中根遍历
void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

// 后根遍历
void postorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c ", root->data);
    }
}

// 复制二叉树
TreeNode *copyBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    TreeNode *newRoot = (TreeNode *)malloc(sizeof(TreeNode));
    newRoot->data = root->data;
    newRoot->left = copyBinaryTree(root->left);
    newRoot->right = copyBinaryTree(root->right);

    return newRoot;
}

// 判断两棵二叉树是否相等
int isBinaryTreeEqual(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }

    if (root1->data != root2->data)
    {
        return 0;
    }

    return isBinaryTreeEqual(root1->left, root2->left) && isBinaryTreeEqual(root1->right, root2->right);
}

// 计算二叉树中叶子结点的个数
int countLeaves(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

// 计算二叉树的深度
int calculateDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

// 在二叉树中查找指定字符的结点
TreeNode *findNode(TreeNode *root, char target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        return root;
    }

    TreeNode *leftResult = findNode(root->left, target);
    if (leftResult != NULL)
    {
        return leftResult;
    }

    TreeNode *rightResult = findNode(root->right, target);
    if (rightResult != NULL)
    {
        return rightResult;
    }

    return NULL;
}

int main()
{
    int choice;
    TreeNode *root = NULL;
    TreeNode *copiedTree = NULL;

    do
    {
        printf("\n二叉树运算:\n");
        printf("1. 创建二叉树\n");
        printf("2. 复制二叉树\n");
        printf("3. 检查两棵二叉树是否相等\n");
        printf("4. 计算二叉树中的叶子\n");
        printf("5. 计算二叉树的深度\n");
        printf("6. 在二叉树中查找节点\n");
        printf("0. 退出\n");
        printf("输入您的选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("输入用于创建二叉树的字符（空节点使用“#”）:\n");
            root = createBinaryTree();
            printf("先根遍历: ");
            preorderTraversal(root);
            printf("\n中根遍历: ");
            inorderTraversal(root);
            printf("\n后根遍历: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 2:
            copiedTree = copyBinaryTree(root);
            printf("二叉树（副本） 后根遍历: ");
            postorderTraversal(copiedTree);
            printf("\n");
            break;
        case 3:
            if (isBinaryTreeEqual(root, copiedTree))
            {
                printf("这两棵树是相等的，复制操作成功\n");
            }
            else
            {
                printf("这两棵树是不相等的，复制操作不成功\n");
            }
            break;
        case 4:
            printf("二叉树中的叶子数: %d\n", countLeaves(root));
            break;
        case 5:
            printf("二叉树的深度: %d\n", calculateDepth(root));
            break;
        case 6:
        {
            char target;
            printf("在二叉树中输入要搜索的字符: ");
            scanf(" %c", &target);
            TreeNode *foundNode = findNode(root, target);
            if (foundNode != NULL)
            {
                printf("OK\n");
            }
            else
            {
                printf("ERROR\n");
            }
        }
        break;
        case 0:
            printf("正在退出程序...\n");
            break;
        default:
            printf("选择无效，请重试。\n");
        }
    } while (choice != 0);

    return 0;
}