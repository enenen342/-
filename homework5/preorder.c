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
    int i = 0;  // ��0��ʼ���
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

// ǰ�����
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
    
    // ����˳��洢����
    createSeqBinaryTree(tree);

    // ��˳��洢��������ת��Ϊ��ʽ������
    TreeNode* tree2 = createBinaryTreeFromArray(tree->data, 0, tree->size);

    // ���ǰ��������
    printf("ǰ����������\n");
    preorder(tree2);
    printf("\n");

    // �ͷ��ڴ�
    free(tree);
    freeTree(tree2);
    
    return 0;
}
