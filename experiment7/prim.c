#include <stdio.h>
#include <stdlib.h>

#define N 4  // ������
#define E 4  // ������ȫ�ֱ����������޸�

// ͼ���ڽӾ���洢�ṹ
typedef struct {
    char vex[N];       // ��������
    float arcs[N][N];    // �ڽӾ���
} Graph;

typedef struct edge
{
    int fromvex,endvex;//��ʼ�ڵ����ֹ�ڵ�
    float weight;//�ߵ�Ȩ��
}edge;//�ߵĴ洢�ṹ

Graph* g; //ͼ
edge T[N-1];//�ߵĴ洢


// ��������
void CreateGraph(Graph* g, char data[]) {
    int i, j, k;
    int v1, v2;
    float l;

    // ��ʼ����������
    for (i = 0; i < N; i++) {
        g->vex[i] = data[i];
    }

    // ��ʼ���ڽӾ���
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            g->arcs[i][j] = 100000;  // �ޱ�ʱȨֵΪ max100000
        }
    }

    // ����ߵ���Ϣ
    
    printf("����ߵ���Ϣ (��ʽ: ������� �յ����� Ȩ��):\n");
    for (k = 0; k < E; k++) {
        scanf("%d %d %f", &v1, &v2,&l);
        v1--;
        v2--;
        g->arcs[v1][v2] = l;
        g->arcs[v2][v1] = l;
        
    }
}

void prim(int i)
{   
    int j,k,m,v;
    float min,max=100000;
    float d;
    edge e;
    v=i;
    for(j=0;j<=N-2;j++)
    {
        T[j].fromvex=v;
        if(j>=v)//j>vʱ��Ҫ��һλ�����Խ���
        {
            T[j].endvex=j+1;
            T[j].weight=g->arcs[v][j+1];
        }
        else//�ֿ���ֵȷ���±���ȷ������
        {
            T[j].endvex=j;
            T[j].weight=g->arcs[v][j];
        }
    }

    for(k=0;k<N-1;k++)
    {
        min=max;
        for(j=k;j<N-1;j++)//Ѱ��Ȩ����С�ı�
        {
            if(T[j].weight<min)
            {
                min=T[j].weight;
                m=j;
            }
        }
        //������
        e=T[m];
        T[m]=T[k];
        T[k]=e;
        v=T[k].endvex;//v��Ϊ�¼ӽ�ȥ�Ľڵ�����
        //���´洢�ı�Ȩֵ
        for(j=k+1;j<N-1;j++)
        {
            d=g->arcs[v][T[j].endvex];
            if(d<T[j].weight)
            {
                T[j].weight=d;
                T[j].fromvex=v;
            }//���¼ӽ�ȥ�Ľڵ���Ϊ�µ���� ��ԭ���洢�ıߵļ����и���Ȩֵ��С�ı� ����Խ��Ȩֵ��С�ı߲��� ���Խ���ȫ��Ѱ��
        }
    }
}
int main()
{
    char data[N] = {'A', 'B', 'C', 'D'};  // ��������
    g = (Graph *)malloc(sizeof(Graph));
    // ��������ͼ
    CreateGraph(g, data);
    prim(0);
    for(int i=0;i<N-1;i++)
    {
        printf("%d %d\n",T[i].fromvex+1,T[i].endvex+1);//�����ֵ
    }

}