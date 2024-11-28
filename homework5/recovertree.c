#include <stdio.h>
#include <stdlib.h>

// �������ڵ�ṹ
typedef struct TreeNode {
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// ���������������µ����ڵ�
TreeNode* createNode(char val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// �����������ĵݹ麯��
TreeNode* buildTree(char* inorder, char* postorder, int inorderStart, int inorderEnd, int* postIndex) {
    // �������
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // ������������һ��Ԫ���ǵ�ǰ���ĸ��ڵ�
    char rootVal = postorder[*postIndex];
    (*postIndex)--;  // �ƶ������������
    TreeNode* root = createNode(rootVal);

    // ����������в��Ҹ��ڵ��λ��
    int rootIndex;
    for (rootIndex = inorderStart; rootIndex <= inorderEnd; rootIndex++) {
        if (inorder[rootIndex] == rootVal) {
            break;
        }
    }

    // ������������������
    root->right = buildTree(inorder, postorder, rootIndex + 1, inorderEnd, postIndex);
    root->left = buildTree(inorder, postorder, inorderStart, rootIndex - 1, postIndex);

    return root;
}

// ���������������������֤���
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c ", root->val);
    inorderTraversal(root->right);
}

// ���������������������֤���
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->val);
}

// �����������Զ���������
int main() {
    char inorder[] = {'D', 'G', 'B', 'A', 'E', 'C', 'H', 'F'};
    char postorder[] = {'G', 'D', 'B', 'E', 'H', 'F', 'C', 'A'};
    int postIndex = sizeof(postorder) / sizeof(postorder[0]) - 1;

    TreeNode* root = buildTree(inorder, postorder, 0, postIndex, &postIndex);

    printf("�����Ķ��������������: ");
    inorderTraversal(root);
    printf("\n");

    printf("�����Ķ������ĺ������: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
