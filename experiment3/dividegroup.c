#include <stdio.h>
#include <stdlib.h>

int DivideIntoGroup(int n, int R[n][n], int cq[], int result[n], int A[]) 
{
    int front = n - 1, rear = n - 1;//队头和队尾为同一处
    int group = 0, pre = 0, I, i;//group为标签，对元素进行分组
    int newr[n];//标识当前组别所具有的冲突关系

    // 初始化
    for (i = 0; i < n; i++) {
        newr[i] = 0;
        cq[i] = A[i];
    }
    do
    {
        front=(front+1)%n;
        I=cq[front];//将元素出队进行操作
        if(I<pre)//识别是否已经分组完毕
        {
            group++;
            result[I-1]=group;//打标签
            for(i=0;i<n;i++)
            {
                newr[i]=R[I-1][i];//初始化分组结束或第一次分组出队的第一个元素所具有的冲突数组
            }
        }
        else
            if(newr[I-1]!=0)
            {
                rear=(rear+1)%n;
                cq[rear]=I;
            }    
        else//不冲突添加入分组
        {
            result[I-1]=group;
            for(i=0;i<n;i++)
            {
                newr[i]+=R[I-1][i];//添加一个元素后需要将新元素的冲突关系加入newr数组
            }
        }
        pre=I;//记录下上次入队的元素，如果上次入队的元素比下次出队的元素大 说明上次分组已经结束（将队列遍历一遍）
    } while (rear!=front);
return group;
}//dividegroup

int main() {
    int n = 5;
    int R[5][5] = { 
        {0, 1, 0, 1, 0}, 
        {1, 0, 1, 0, 1}, 
        {0, 1, 0, 1, 0}, 
        {1, 0, 1, 0, 1}, 
        {0, 1, 0, 1, 0} 
    };
    int A[5] = {1, 2, 3, 4, 5};
    int cq[5], result[5] = {0};
    int k=0,group;
    group=DivideIntoGroup(n, R, cq, result, A);
    for(int i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }
    printf("\n");
    while(k<=group)
    {
         for(int i=0;i<n;i++)
        {
            if(result[i]==k)
            {
                printf("%d ",A[i]);
            }
        }
        printf("\n");
        k++;
    }
   

    return 0;
}


