#include <stdio.h>
#include <stdlib.h>

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

// 创建邻接表
void CreateADjist(vexnode ga[], char data[]) {
    int i, j, k;
    edgenode *s;
    
    // 初始化顶点
    for (i = 0; i < N; i++) {
        ga[i].vertex = data[i];
        ga[i].link = NULL;
    }

    // 输入边并建立邻接表
    for (k = 0; k < E; k++) {
        scanf("%d %d", &i, &j); // 输入边的信息（1-based索引）
        i--; // 转为0-based索引
        j--; // 转为0-based索引

        // 为i顶点插入邻接点j
        s = (edgenode *)malloc(sizeof(edgenode));
        s->adjvex = j;
        s->next = ga[i].link;
        ga[i].link = s; // 头插法

        // 为j顶点插入邻接点i（无向图）
        s = (edgenode *)malloc(sizeof(edgenode));
        s->adjvex = i;
        s->next = ga[j].link;
        ga[j].link = s; // 头插法
    }
}

// 深度优先遍历（DFS）
void DFSL(int i) {
    edgenode *p;
    printf("%c ", ga[i].vertex); // 输出当前顶点
    visited[i] = 1; // 标记当前顶点为已访问

    p = ga[i].link;
    while (p != NULL) { // 遍历当前节点的所有邻接点
        if (visited[p->adjvex] == 0) { // 若邻接点未被访问
            DFSL(p->adjvex); // 递归深度优先遍历
        }
        p = p->next; // 遍历下一个邻接点
    }
}

int main() {
    char data[N] = {'A', 'B', 'C', 'D'}; // 顶点数据
    int i;
    
    // 初始化访问标记数组
    for (i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // 创建图
    printf("输入边的信息 (格式: 起点索引 终点索引):\n");
    CreateADjist(ga, data);

    // 深度优先遍历，从顶点0（A）开始
    printf("深度优先遍历结果:\n");
    DFSL(0);  // 从第0个顶点开始遍历（A）

    return 0;
}
