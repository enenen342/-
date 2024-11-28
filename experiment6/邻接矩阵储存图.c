#include <stdio.h>
#include <stdlib.h>

#define N 4  // 顶点数

#define E 4  // 边数，全局变量，方便修改

// 图的邻接矩阵存储结构
typedef struct {
    char vex[N];       // 顶点数组
    int arcs[N][N];    // 邻接矩阵
} Graph;

int visited[N];  // 访问标记数组

// 创建无向图
void CreateGraph(Graph* g, char data[]) {
    int i, j, k;
    int v1, v2;

    // 初始化顶点数组
    for (i = 0; i < N; i++) {
        g->vex[i] = data[i];
    }

    // 初始化邻接矩阵
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            g->arcs[i][j] = 0;  // 无边时权值为 0
        }
    }

    // 输入边的信息
    
    printf("输入边的信息 (格式: 起点索引 终点索引):\n");
    for (k = 0; k < E; k++) {
        scanf("%d %d", &v1, &v2);
        v1--;
        v2--;
        g->arcs[v1][v2] = 1;  // 无向图对称赋值
        g->arcs[v2][v1] = 1;
    }
}

// 深度优先遍历
void DFS(Graph* g, int i) {
    printf("%c ", g->vex[i]);  // 输出当前顶点
    visited[i] = 1;           // 标记已访问

    // 遍历所有邻接点
    for (int j = 0; j < N; j++) {
        if ((g->arcs[i][j] == 1) && (visited[j]==0)) {  // 存在边且未访问
            DFS(g, j);  // 递归访问
        }
    }
}

int main() {
    char data[N] = {'A', 'B', 'C', 'D'};  // 顶点数据
    Graph g;

    // 初始化访问标记数组
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    // 创建无向图
    CreateGraph(&g, data);

    // 深度优先遍历
    printf("深度优先遍历结果: ");
    DFS(&g, 0);  // 从第0个顶点开始遍历

    return 0;
}
