#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

typedef struct {
    char data[MAXSIZE];  // ˳��洢������
    int size;           // ��ǰ���Ľڵ���
} SeqBinaryTree;

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// �����½ڵ�
TreeNode* createNode(char data) {
    if (data == '@') {
        return NULL; // -1 ��ʾ�սڵ�
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
    printf("������ڵ��ֵ �����˳�����룬@��ʾ�սڵ㣬��#��������\n");
    while (1) 
    {
        printf("�ڵ� %d ��ֵ��", i);
        ch = getchar();
        getchar();
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

void showleftchild(SeqBinaryTree *tree)//������е�������
{
    for(int i=0;i<=tree->size;i=2*i+1)
    {
        if (tree->data[i] != '@') {
            printf("%c ", tree->data[i]);
        }
    }
}
void showrightchild(SeqBinaryTree *tree)//������������� 
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
// ����������

// ����������
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
    







    