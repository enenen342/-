#include <stdio.h>
#include <stdlib.h>

#define N 4  // 顶点数
#define E 4  // 边数，全局变量，方便修改

// 图的邻接矩阵存储结构
typedef struct {
    char vex[N];       // 顶点数组
    float arcs[N][N];    // 邻接矩阵
} Graph;

typedef struct edge
{
    int fromvex,endvex;//起始节点和终止节点
    float weight;//边的权重
}edge;//边的存储结构

Graph* g; //图
edge T[N-1];//边的存储


// 创建网络
void CreateGraph(Graph* g, char data[]) {
    int i, j, k;
    int v1, v2;
    float l;

    // 初始化顶点数组
    for (i = 0; i < N; i++) {
        g->vex[i] = data[i];
    }

    // 初始化邻接矩阵
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            g->arcs[i][j] = 100000;  // 无边时权值为 max100000
        }
    }

    // 输入边的信息
    
    printf("输入边的信息 (格式: 起点索引 终点索引 权重):\n");
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
        if(j>=v)//j>v时需要加一位跳过对角线
        {
            T[j].endvex=j+1;
            T[j].weight=g->arcs[v][j+1];
        }
        else//分开赋值确保下标正确索引到
        {
            T[j].endvex=j;
            T[j].weight=g->arcs[v][j];
        }
    }

    for(k=0;k<N-1;k++)
    {
        min=max;
        for(j=k;j<N-1;j++)//寻找权重最小的边
        {
            if(T[j].weight<min)
            {
                min=T[j].weight;
                m=j;
            }
        }
        //交换边
        e=T[m];
        T[m]=T[k];
        T[k]=e;
        v=T[k].endvex;//v作为新加进去的节点索引
        //更新存储的边权值
        for(j=k+1;j<N-1;j++)
        {
            d=g->arcs[v][T[j].endvex];
            if(d<T[j].weight)
            {
                T[j].weight=d;
                T[j].fromvex=v;
            }//以新加进去的节点作为新的起点 在原来存储的边的集合中更新权值更小的边 并且越来权值更小的边不变 可以进行全局寻找
        }
    }
}
int main()
{
    char data[N] = {'A', 'B', 'C', 'D'};  // 顶点数据
    g = (Graph *)malloc(sizeof(Graph));
    // 创建无向图
    CreateGraph(g, data);
    prim(0);
    for(int i=0;i<N-1;i++)
    {
        printf("%d %d\n",T[i].fromvex+1,T[i].endvex+1);//输出边值
    }

}