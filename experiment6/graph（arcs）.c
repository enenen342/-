#include <stdio.h>
#include <stdlib.h>

#define N 4  // ������

#define E 4  // ������ȫ�ֱ����������޸�

// ͼ���ڽӾ���洢�ṹ
typedef struct {
    char vex[N];       // ��������
    int arcs[N][N];    // �ڽӾ���
} Graph;

int visited[N];  // ���ʱ������

// ��������ͼ
void CreateGraph(Graph* g, char data[]) {
    int i, j, k;
    int v1, v2;

    // ��ʼ����������
    for (i = 0; i < N; i++) {
        g->vex[i] = data[i];
    }

    // ��ʼ���ڽӾ���
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            g->arcs[i][j] = 0;  // �ޱ�ʱȨֵΪ 0
        }
    }

    // ����ߵ���Ϣ
    
    printf("����ߵ���Ϣ (��ʽ: ������� �յ�����):\n");
    for (k = 0; k < E; k++) {
        scanf("%d %d", &v1, &v2);
        v1--;
        v2--;
        g->arcs[v1][v2] = 1;  // ����ͼ�ԳƸ�ֵ
        g->arcs[v2][v1] = 1;
    }
}

// ������ȱ���
void DFS(Graph* g, int i) {
    printf("%c ", g->vex[i]);  // �����ǰ����
    visited[i] = 1;           // ����ѷ���

    // ���������ڽӵ�
    for (int j = 0; j < N; j++) {
        if ((g->arcs[i][j] == 1) && (visited[j]==0)) {  // ���ڱ���δ����
            DFS(g, j);  // �ݹ����
        }
    }
}

int main() {
    char data[N] = {'A', 'B', 'C', 'D'};  // ��������
    Graph g;

    // ��ʼ�����ʱ������
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // ��������ͼ
    CreateGraph(&g, data);

    // ������ȱ���
    printf("������ȱ������: ");
    DFS(&g, 0);  // �ӵ�0�����㿪ʼ����

    return 0;
}
