#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 4  // 顶点数
#define E 4  // 边数

// 边节点结构体
typedef struct node {
    int adjvex;        // 邻接点
    struct node *next; // 下一个邻接点
} edgenode;

// 顶点节点结构体
typedef struct {
    char vertex;   // 顶点数据
    edgenode *link; // 邻接表头指针
} vexnode;

vexnode ga[N]; // 邻接表
int visited[N]; // 访问标记数组

// 创建邻接表(有向图)
void CreateADjist(vexnode ga[], char data[]) {
    int i, j, k;
    edgenode *s;
    
    // 初始化顶点
    for (i = 0; i < N; i++) {
        ga[i].vertex = data[i];
        ga[i].link = NULL;
    }

    // 输入边并建立有向图邻接表
    for (k = 0; k < E; k++) {
        scanf("%d %d", &i, &j); // 输入边的信息（1-based索引）
        i--; // 转为0-based索引
        j--; // 转为0-based索引

        // 为i顶点插入邻接点j
        s = (edgenode *)malloc(sizeof(edgenode));
        s->adjvex = j;
        s->next = ga[i].link;
        ga[i].link = s; // 头插法
    }
}

bool search(int node,int end)
{
    if(node==end)
    {
        return true;
    }
    visited[node] = 1; // 标记当前顶点为已访问
    edgenode *p;
    p = ga[node].link;
    

    while (p != NULL) 
    { // 遍历当前节点的所有邻接点
        if (visited[p->adjvex] == 0)// 若邻接点未被访问 
        { 
            if(search(p->adjvex,end))
            {
                return true;//如果邻接点是end则找到路径返回true
            }; // 递归深度优先遍历
        }
        p = p->next; // 遍历下一个邻接点
    }
    return false;

}

int main() {

    char data[N] = {'A', 'B', 'C', 'D'}; // 顶点数据
    int i;

    // 创建图
    printf("输入边的信息 (格式: 起点索引 终点索引):\n");
    CreateADjist(ga, data);
    //输入信息
    printf("输入查找的两个节点索引:\n");
    int start,end;
    scanf("%d %d",&start,&end);

    // 初始化访问标记数组
    for (i = 0; i < N; i++) {
        visited[i] = 0;
    }
    //输出结果
    if(search(start-1,end-1))
    {
        printf("寻找到路径");
    }
    else
    {
        printf("未寻找到路径");
    }
   
    // 释放邻接表内存
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



