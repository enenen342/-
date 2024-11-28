#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6  // 叶子节点数
#define M 11 // 总节点数（2N-1）

// 哈夫曼树节点
typedef struct {
    float weight;   // 权重
    int parent;     // 父节点索引
    int lchild;     // 左子节点索引
    int rchild;     // 右子节点索引
    char data;      // 数据
} hafuman;

// 哈夫曼编码表
typedef struct {
    char bit[N];    // 编码数组
    int start;      // 编码起始位置
    char data;      // 对应数据
} hafumancode;

hafumancode code[N];
hafuman tree[M];

// 构建哈夫曼树
void CreateHafuman(hafuman tree[], float weights[], char datas[]) {
    int i, j, p1, p2;
    float small1, small2;

    // 初始化哈夫曼树
    for (i = 0; i < M; i++) {
        tree[i].weight = 0.0;
        tree[i].parent = -1;
        tree[i].lchild = -1;
        tree[i].rchild = -1;
        tree[i].data = '\0';
    }

    // 初始化叶子节点
    for (i = 0; i < N; i++) {
        tree[i].weight = weights[i];
        tree[i].data = datas[i];
    }

    // 构建哈夫曼树
    for (i = N; i < M; i++) {
        small1 = small2 = 1e9; // 初始化为较大的值
        p1 = p2 = -1;

        // 找到两个权值最小的节点
        for (j = 0; j < i; j++) {
            if (tree[j].parent == -1) { // 节点未被选中
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

        // 合并节点
        tree[p1].parent = i;
        tree[p2].parent = i;
        tree[i].lchild = p1;
        tree[i].rchild = p2;
        tree[i].weight = tree[p1].weight + tree[p2].weight;
    }
}

// 哈夫曼编码
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
        code[i].bit[N] = '\0'; // 确保编码字符串以 '\0' 结尾
    }
}

// 哈夫曼译码
void HafumanDecode(hafuman tree[], char *codes) {
    int i = M - 1; // 从根节点开始
    int idx = 0;

    while (codes[idx] != '\0') {
        if (codes[idx] == '0') {
            i = tree[i].lchild;
        } else if (codes[idx] == '1') {
            i = tree[i].rchild;
        }

        // 如果是叶子节点，输出字符
        if (tree[i].lchild == -1 && tree[i].rchild == -1) {
            putchar(tree[i].data);
            i = M - 1; // 回到根节点
        }
        idx++;
    }
    putchar('\n');
}

// 打印哈夫曼编码
void PrintHufmanCodes(hafumancode code[]) {
    printf("字符 | 哈夫曼编码\n");
    printf("----------------\n");
    for (int i = 0; i < N; i++) {
        printf("  %c  | ", code[i].data);
        for (int j = code[i].start; j < N; j++) {
            putchar(code[i].bit[j]);
        }
        printf("\n");
    }
}

// 打印哈夫曼树
void PrintHufmanTree(hafuman tree[]) {
    printf("Index\tWeight\tParent\tLChild\tRChild\tData\n");
    for (int i = 0; i < M; i++) {
        printf("%d\t%.2f\t%d\t%d\t%d\t%c\n",
               i, tree[i].weight, tree[i].parent, tree[i].lchild, tree[i].rchild,
               tree[i].data ? tree[i].data : '-');
    }
}

// 主函数
int main() {
    float weights[N] = {5, 9, 12, 13, 16, 45}; // 权重
    char datas[N] = {'a', 'b', 'c', 'd', 'e', 'f'}; // 数据

    CreateHafuman(tree, weights, datas); // 创建哈夫曼树
    PrintHufmanTree(tree); // 打印哈夫曼树

    HafmanEncode(tree, code); // 编码
    PrintHufmanCodes(code); // 输出编码结果

    char encoded[] = "110011011001011110"; // 对应 "abcdef"
    printf("\n解码结果: ");
    HafumanDecode(tree, encoded); // 输出解码结果

    return 0;
}
