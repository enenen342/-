#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 递归构建二叉树，输入 -1 表示空节点
TreeNode* createBinaryTree() {
    char data;
    printf("输入节点数据 @表示空节点）：");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    TreeNode* node = createNode(data);
    printf("输入 %d 的左子节点\n", data);
    node->left = createBinaryTree();
    printf("输入 %d 的右子节点\n", data);
    node->right = createBinaryTree();

    return node;
}



int main() {
    TreeNode* root = NULL;

    printf("开始创建二叉树：\n");
    root = createBinaryTree();

    printf("前序遍历结果：");
    
    printf("\n");

    

    return 0;
}
