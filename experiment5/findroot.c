#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef struct {
    char data[MAXSIZE];  // ˳��洢������
    int size;            // ��ǰ���Ľڵ���
} SeqBinaryTree;

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;  // �������ڵ�

// �����½ڵ�
TreeNode* createNode(char data) {
    if (data == '@') {
        return NULL; // '@' ��ʾ�սڵ�
    }
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �����ͷ������������Ľڵ�
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ˳��洢�Ķ���������
void createSeqBinaryTree(SeqBinaryTree *tree) {
    int i = 0;
    char ch;
    printf("������ڵ��ֵ �����˳�����룬@��ʾ�սڵ㣬��#��������\n");
    while (1) {
        printf("�ڵ� %d ��ֵ��", i + 1);
        ch = getchar();
        getchar();  // ��ȡ���������з�����ֹ����������
        if (ch == '#') 
            break;
        tree->data[i] = ch;
        tree->size = i + 1; // ��������ʵ�ʴ�С
        i++;
    }
}

// �����������ݵݹ鴴��������
TreeNode* createBinaryTreeFromArray(char arr[], int index, int size) {
    if (index >= size || arr[index] == '@') {
        return NULL;
    }

    TreeNode* root = createNode(arr[index]);
    root->left = createBinaryTreeFromArray(arr, 2 * index + 1, size);  // �������� 2 * index + 1
    root->right = createBinaryTreeFromArray(arr, 2 * index + 2, size); // �Һ������� 2 * index + 2

    return root;
}

// ���Ҷ������еĽڵ�
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

// ���������ڵ����͹�������
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
    createSeqBinaryTree(tree);  // ��˳��洢����������
    
    TreeNode* tree2 = createBinaryTreeFromArray(tree->data, 0, tree->size);  // ����˳��洢�����ݽ�����ʽ������
    
    printf("����p��q:\n");
    char p, q;
    scanf(" %c %c", &p, &q);  // ȷ���������޸��Ŷ�ȡ
    
    TreeNode* node1 = findnode(tree2, p);
    TreeNode* node2 = findnode(tree2, q);
    if (node1 == NULL || node2 == NULL) {
        printf("δ�ҵ��ڵ� %c ��ڵ� %c\n", p, q);
        free(tree);
        freeTree(tree2);
        return 1;
    }
    
    TreeNode* result = findLowestCommonAncestor(tree2, node1, node2);
    
    if (result != NULL) {
        printf("�ڵ� %c �� �ڵ� %c ����͹���������: %c\n", p, q, result->data);
    } else {
        printf("δ�ҵ��������ȡ�\n");
    }
    
    free(tree);
    freeTree(tree2);  // �ݹ��ͷ�������ʽ������
    return 0;
}
