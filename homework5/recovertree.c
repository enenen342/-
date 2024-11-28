#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构
typedef struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 辅助函数：创建新的树节点
TreeNode* createNode(char val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 构建二叉树的递归函数
TreeNode* buildTree(char* inorder, char* postorder, int inorderStart, int inorderEnd, int* postIndex) {
    // 基本情况
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // 后序遍历的最后一个元素是当前树的根节点
    char rootVal = postorder[*postIndex];
    (*postIndex)--;  // 移动后序遍历索引
    TreeNode* root = createNode(rootVal);

    // 在中序遍历中查找根节点的位置
    int rootIndex;
    for (rootIndex = inorderStart; rootIndex <= inorderEnd; rootIndex++) {
        if (inorder[rootIndex] == rootVal) {
            break;
        }
    }

    // 构建右子树和左子树
    root->right = buildTree(inorder, postorder, rootIndex + 1, inorderEnd, postIndex);
    root->left = buildTree(inorder, postorder, inorderStart, rootIndex - 1, postIndex);

    return root;
}

// 辅助函数：中序遍历，验证结果
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c ", root->val);
    inorderTraversal(root->right);
}

// 辅助函数：后序遍历，验证结果
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->val);
}

// 主函数：测试二叉树构建
int main() {
    char inorder[] = {'D', 'G', 'B', 'A', 'E', 'C', 'H', 'F'};
    char postorder[] = {'G', 'D', 'B', 'E', 'H', 'F', 'C', 'A'};
    int postIndex = sizeof(postorder) / sizeof(postorder[0]) - 1;

    TreeNode* root = buildTree(inorder, postorder, 0, postIndex, &postIndex);

    printf("构建的二叉树的中序遍历: ");
    inorderTraversal(root);
    printf("\n");

    printf("构建的二叉树的后序遍历: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
