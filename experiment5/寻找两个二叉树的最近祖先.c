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
    int i = 0;
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

// 查找二叉树中的节点
TreeNode* findnode(TreeNode* root, char target) {
    if (root == NULL || root->data == target) {
        return root;
    }
    
    TreeNode* leftResult = findnode(root->left, target);
    if (leftResult != NULL) {
        return leftResult;
    }
    
    return findnode(root->right, target);
}

// 查找两个节点的最低公共祖先
TreeNode* findLowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    if (root == NULL || root == node1 || root == node2) {
        return root;
    }

    TreeNode* left = findLowestCommonAncestor(root->left, node1, node2);
    TreeNode* right = findLowestCommonAncestor(root->right, node1, node2);

    if (left != NULL && right != NULL) {
        return root;
    }

    return (left != NULL) ? left : right;
}

int main() {
    SeqBinaryTree *tree = (SeqBinaryTree *)malloc(sizeof(SeqBinaryTree));
    tree->size = 0;
    createSeqBinaryTree(tree);  // 用顺序存储建立二叉树
    
    TreeNode* tree2 = createBinaryTreeFromArray(tree->data, 0, tree->size);  // 利用顺序存储的数据建立链式二叉树
    
    printf("输入p和q:\n");
    char p, q;
    scanf(" %c %c", &p, &q);  // 确保缓冲区无干扰读取
    
    TreeNode* node1 = findnode(tree2, p);
    TreeNode* node2 = findnode(tree2, q);
    if (node1 == NULL || node2 == NULL) {
        printf("未找到节点 %c 或节点 %c\n", p, q);
        free(tree);
        freeTree(tree2);
        return 1;
    }
    
    TreeNode* result = findLowestCommonAncestor(tree2, node1, node2);
    
    if (result != NULL) {
        printf("节点 %c 和 节点 %c 的最低公共祖先是: %c\n", p, q, result->data);
    } else {
        printf("未找到公共祖先。\n");
    }
    
    free(tree);
    freeTree(tree2);  // 递归释放整个链式二叉树
    return 0;
}
