#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6  // Ҷ�ӽڵ���
#define M 11 // �ܽڵ�����2N-1��

// ���������ڵ�
typedef struct {
    float weight;   // Ȩ��
    int parent;     // ���ڵ�����
    int lchild;     // ���ӽڵ�����
    int rchild;     // ���ӽڵ�����
    char data;      // ����
} hafuman;

// �����������
typedef struct {
    char bit[N];    // ��������
    int start;      // ������ʼλ��
    char data;      // ��Ӧ����
} hafumancode;

hafumancode code[N];
hafuman tree[M];

// ������������
void CreateHafuman(hafuman tree[], float weights[], char datas[]) {
    int i, j, p1, p2;
    float small1, small2;

    // ��ʼ����������
    for (i = 0; i < M; i++) {
        tree[i].weight = 0.0;
        tree[i].parent = -1;
        tree[i].lchild = -1;
        tree[i].rchild = -1;
        tree[i].data = '\0';
    }

    // ��ʼ��Ҷ�ӽڵ�
    for (i = 0; i < N; i++) {
        tree[i].weight = weights[i];
        tree[i].data = datas[i];
    }

    // ������������
    for (i = N; i < M; i++) {
        small1 = small2 = 1e9; // ��ʼ��Ϊ�ϴ��ֵ
        p1 = p2 = -1;

        // �ҵ�����Ȩֵ��С�Ľڵ�
        for (j = 0; j < i; j++) {
            if (tree[j].parent == -1) { // �ڵ�δ��ѡ��
                if (tree[j].weight < small1) {
                    small2 = small1;
                    p2 = p1;
                    small1 = tree[j].weight;
                    p1 = j;
                } else if (tree[j].weight < small2) {
                    small2 = tree[j].weight;
                    p2 = j;
                }
            }
        }

        // �ϲ��ڵ�
        tree[p1].parent = i;
        tree[p2].parent = i;
        tree[i].lchild = p1;
        tree[i].rchild = p2;
        tree[i].weight = tree[p1].weight + tree[p2].weight;
    }
}

// ����������
void HafmanEncode(hafuman tree[], hafumancode code[]) {
    int i, c, p;

    for (i = 0; i < N; i++) {
        code[i].start = N;
        code[i].data = tree[i].data;
        c = i;
        p = tree[c].parent;

        while (p != -1) {
            code[i].start--;
            if (tree[p].lchild == c) {
                code[i].bit[code[i].start] = '0';
            } else {
                code[i].bit[code[i].start] = '1';
            }
            c = p;
            p = tree[p].parent;
        }
        code[i].bit[N] = '\0'; // ȷ�������ַ����� '\0' ��β
    }
}

// ����������
void HafumanDecode(hafuman tree[], char *codes) {
    int i = M - 1; // �Ӹ��ڵ㿪ʼ
    int idx = 0;

    while (codes[idx] != '\0') {
        if (codes[idx] == '0') {
            i = tree[i].lchild;
        } else if (codes[idx] == '1') {
            i = tree[i].rchild;
        }

        // �����Ҷ�ӽڵ㣬����ַ�
        if (tree[i].lchild == -1 && tree[i].rchild == -1) {
            putchar(tree[i].data);
            i = M - 1; // �ص����ڵ�
        }
        idx++;
    }
    putchar('\n');
}

// ��ӡ����������
void PrintHufmanCodes(hafumancode code[]) {
    printf("�ַ� | ����������\n");
    printf("----------------\n");
    for (int i = 0; i < N; i++) {
        printf("  %c  | ", code[i].data);
        for (int j = code[i].start; j < N; j++) {
            putchar(code[i].bit[j]);
        }
        printf("\n");
    }
}

// ��ӡ��������
void PrintHufmanTree(hafuman tree[]) {
    printf("Index\tWeight\tParent\tLChild\tRChild\tData\n");
    for (int i = 0; i < M; i++) {
        printf("%d\t%.2f\t%d\t%d\t%d\t%c\n",
               i, tree[i].weight, tree[i].parent, tree[i].lchild, tree[i].rchild,
               tree[i].data ? tree[i].data : '-');
    }
}

// ������
int main() {
    float weights[N] = {5, 9, 12, 13, 16, 45}; // Ȩ��
    char datas[N] = {'a', 'b', 'c', 'd', 'e', 'f'}; // ����

    CreateHafuman(tree, weights, datas); // ������������
    PrintHufmanTree(tree); // ��ӡ��������

    HafmanEncode(tree, code); // ����
    PrintHufmanCodes(code); // ���������

    char encoded[] = "110011011001011110"; // ��Ӧ "abcdef"
    printf("\n������: ");
    HafumanDecode(tree, encoded); // ���������

    return 0;
}
