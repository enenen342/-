#include <stdio.h>
#include <stdlib.h>

#define N 4  // ������
#define E 4  // ����

// �߽ڵ�ṹ��
typedef struct node {
    int adjvex;        // �ڽӵ�
    struct node *next; // ��һ���ڽӵ�
} edgenode;

// ����ڵ�ṹ��
typedef struct {
    char vertex;   // ��������
    edgenode *link; // �ڽӱ�ͷָ��
} vexnode;

vexnode ga[N]; // �ڽӱ�
int visited[N]; // ���ʱ������

// �����ڽӱ�
void CreateADjist(vexnode ga[], char data[]) {
    int i, j, k;
    edgenode *s;
    
    // ��ʼ������
    for (i = 0; i < N; i++) {
        ga[i].vertex = data[i];
        ga[i].link = NULL;
    }

    // ����߲������ڽӱ�
    for (k = 0; k < E; k++) {
        scanf("%d %d", &i, &j); // ����ߵ���Ϣ��1-based������
        i--; // תΪ0-based����
        j--; // תΪ0-based����

        // Ϊi��������ڽӵ�j
        s = (edgenode *)malloc(sizeof(edgenode));
        s->adjvex = j;
        s->next = ga[i].link;
        ga[i].link = s; // ͷ�巨

        // Ϊj��������ڽӵ�i������ͼ��
        s = (edgenode *)malloc(sizeof(edgenode));
        s->adjvex = i;
        s->next = ga[j].link;
        ga[j].link = s; // ͷ�巨
    }
}

// ������ȱ�����DFS��
void DFSL(int i) {
    edgenode *p;
    printf("%c ", ga[i].vertex); // �����ǰ����
    visited[i] = 1; // ��ǵ�ǰ����Ϊ�ѷ���

    p = ga[i].link;
    while (p != NULL) { // ������ǰ�ڵ�������ڽӵ�
        if (visited[p->adjvex] == 0) { // ���ڽӵ�δ������
            DFSL(p->adjvex); // �ݹ�������ȱ���
        }
        p = p->next; // ������һ���ڽӵ�
    }
}

int main() {
    char data[N] = {'A', 'B', 'C', 'D'}; // ��������
    int i;
    
    // ��ʼ�����ʱ������
    for (i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // ����ͼ
    printf("����ߵ���Ϣ (��ʽ: ������� �յ�����):\n");
    CreateADjist(ga, data);

    // ������ȱ������Ӷ���0��A����ʼ
    printf("������ȱ������:\n");
    DFSL(0);  // �ӵ�0�����㿪ʼ������A��

    return 0;
}
