#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// �����ڽӱ�(����ͼ)
void CreateADjist(vexnode ga[], char data[]) {
    int i, j, k;
    edgenode *s;
    
    // ��ʼ������
    for (i = 0; i < N; i++) {
        ga[i].vertex = data[i];
        ga[i].link = NULL;
    }

    // ����߲���������ͼ�ڽӱ�
    for (k = 0; k < E; k++) {
        scanf("%d %d", &i, &j); // ����ߵ���Ϣ��1-based������
        i--; // תΪ0-based����
        j--; // תΪ0-based����

        // Ϊi��������ڽӵ�j
        s = (edgenode *)malloc(sizeof(edgenode));
        s->adjvex = j;
        s->next = ga[i].link;
        ga[i].link = s; // ͷ�巨
    }
}

bool search(int node,int end)
{
    if(node==end)
    {
        return true;
    }
    visited[node] = 1; // ��ǵ�ǰ����Ϊ�ѷ���
    edgenode *p;
    p = ga[node].link;
    

    while (p != NULL) 
    { // ������ǰ�ڵ�������ڽӵ�
        if (visited[p->adjvex] == 0)// ���ڽӵ�δ������ 
        { 
            if(search(p->adjvex,end))
            {
                return true;//����ڽӵ���end���ҵ�·������true
            }; // �ݹ�������ȱ���
        }
        p = p->next; // ������һ���ڽӵ�
    }
    return false;

}

int main() {

    char data[N] = {'A', 'B', 'C', 'D'}; // ��������
    int i;

    // ����ͼ
    printf("����ߵ���Ϣ (��ʽ: ������� �յ�����):\n");
    CreateADjist(ga, data);
    //������Ϣ
    printf("������ҵ������ڵ�����:\n");
    int start,end;
    scanf("%d %d",&start,&end);

    // ��ʼ�����ʱ������
    for (i = 0; i < N; i++) {
        visited[i] = 0;
    }
    //������
    if(search(start-1,end-1))
    {
        printf("Ѱ�ҵ�·��");
    }
    else
    {
        printf("δѰ�ҵ�·��");
    }
   
    // �ͷ��ڽӱ��ڴ�
    for (int i = 0; i < N; i++) 
    {
        edgenode *p = ga[i].link;
        while (p != NULL) {
            edgenode *temp = p;
            p = p->next;
            free(temp);
        }
    }
    
    return 0;
}



