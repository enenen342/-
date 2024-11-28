#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �ݹ鹹�������������� -1 ��ʾ�սڵ�
TreeNode* createBinaryTree() {
    char data;
    printf("����ڵ����� @��ʾ�սڵ㣩��");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    TreeNode* node = createNode(data);
    printf("���� %d �����ӽڵ�\n", data);
    node->left = createBinaryTree();
    printf("���� %d �����ӽڵ�\n", data);
    node->right = createBinaryTree();

    return node;
}



int main() {
    TreeNode* root = NULL;

    printf("��ʼ������������\n");
    root = createBinaryTree();

    printf("ǰ����������");
    
    printf("\n");

    

    return 0;
}
