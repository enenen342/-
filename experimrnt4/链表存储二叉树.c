#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef struct {
    char data[MAXSIZE];  // 顺序存储的数组
    int size;           // 当前树的节点数
} SeqBinaryTree;

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新节点
TreeNode* createNode(char data) {
    if (data == '@') {
        return NULL; // -1 表示空节点
    }
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void createSeqBinaryTree(SeqBinaryTree *tree) 
{
    int value, i = 1;
    char ch;
    printf("请输入节点的值 按层次顺序输入，@表示空节点，以#结束输入\n");
    while (1) 
    {
        printf("节点 %d 的值：", i);
        ch = getchar();
        getchar();
        if (ch == '#') 
            break;
        tree->data[i] = ch;
        tree->size = i + 1; // 更新树的实际大小
        i++;
    }
}

// 根据数组数据递归创建二叉树
TreeNode* createBinaryTreeFromArray(char arr[], int index, int size) {
    if (index >= size || arr[index] == '@') {
        return NULL;
    }

    TreeNode* root = createNode(arr[index]);
    root->left = createBinaryTreeFromArray(arr, 2 * index + 1, size);  // 左孩子索引 2 * index + 1
    root->right = createBinaryTreeFromArray(arr, 2 * index + 2, size); // 右孩子索引 2 * index + 2

    return root;
}

void showleftchild(SeqBinaryTree *tree)//输出所有的左子树
{
    for(int i=0;i<=tree->size;i=2*i+1)
    {
        if (tree->data[i] != '@') {
            printf("%c ", tree->data[i]);
        }
    }
}
void showrightchild(SeqBinaryTree *tree)//输出所有右子树 
{
    for(int i=1;i<=tree->size;i=2*i)
    {
        if (tree->data[i] != '@') {
            printf("%c ", tree->data[i]);
        }
    }
    printf("\n");
}

void preorderLeft(TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorderLeft(root->left);
    }
}
// 遍历左子树

// 遍历右子树
void preorderRight(TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorderRight(root->right);
    }
}

int main()
{
    SeqBinaryTree *tree = (SeqBinaryTree *)malloc(sizeof(SeqBinaryTree));
    tree->size=0;
    createSeqBinaryTree(tree) ;
    TreeNode* tree2=createBinaryTreeFromArray(tree->data,0,tree->size);
    preorderRight(tree2);
    printf("\n");
    preorderLeft(tree2);
    free(tree);
    free(tree2);
}
    







    
