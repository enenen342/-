#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef struct {
    char data[MAXSIZE];  // 顺序存储的数组
    int size;            // 当前树的节点数
} SeqBinaryTree;

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;  // 二叉树节点

// 创建新节点
TreeNode* createNode(char data) {
    if (data == '@') {
        return NULL; // '@' 表示空节点
    }
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 用于释放整个二叉树的节点
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 顺序存储的二叉树创建
void createSeqBinaryTree(SeqBinaryTree *tree) {
    int i = 0;  // 从0开始填充
    char ch;
    printf("请输入节点的值 按层次顺序输入，@表示空节点，以#结束输入\n");
    while (1) {
        printf("节点 %d 的值：", i + 1);
        ch = getchar();
        getchar();  // 读取并丢弃换行符，防止缓冲区干扰
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

// 前序遍历
void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    SeqBinaryTree *tree = (SeqBinaryTree *)malloc(sizeof(SeqBinaryTree));
    tree->size = 0;
    
    // 创建顺序存储的树
    createSeqBinaryTree(tree);

    // 将顺序存储的树数据转换为链式二叉树
    TreeNode* tree2 = createBinaryTreeFromArray(tree->data, 0, tree->size);

    // 输出前序遍历结果
    printf("前序遍历结果：\n");
    preorder(tree2);
    printf("\n");

    // 释放内存
    free(tree);
    freeTree(tree2);
    
    return 0;
}
