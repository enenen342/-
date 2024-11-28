#include <stdio.h>
#include <stdlib.h>

int DivideIntoGroup(int n, int R[n][n], int cq[], int result[n], int A[]) 
{
    int front = n - 1, rear = n - 1;//��ͷ�Ͷ�βΪͬһ��
    int group = 0, pre = 0, I, i;//groupΪ��ǩ����Ԫ�ؽ��з���
    int newr[n];//��ʶ��ǰ��������еĳ�ͻ��ϵ

    // ��ʼ��
    for (i = 0; i < n; i++) {
        newr[i] = 0;
        cq[i] = A[i];
    }
    do
    {
        front=(front+1)%n;
        I=cq[front];//��Ԫ�س��ӽ��в���
        if(I<pre)//ʶ���Ƿ��Ѿ��������
        {
            group++;
            result[I-1]=group;//���ǩ
            for(i=0;i<n;i++)
            {
                newr[i]=R[I-1][i];//��ʼ������������һ�η�����ӵĵ�һ��Ԫ�������еĳ�ͻ����
            }
        }
        else
            if(newr[I-1]!=0)
            {
                rear=(rear+1)%n;
                cq[rear]=I;
            }    
        else//����ͻ��������
        {
            result[I-1]=group;
            for(i=0;i<n;i++)
            {
                newr[i]+=R[I-1][i];//���һ��Ԫ�غ���Ҫ����Ԫ�صĳ�ͻ��ϵ����newr����
            }
        }
        pre=I;//��¼���ϴ���ӵ�Ԫ�أ�����ϴ���ӵ�Ԫ�ر��´γ��ӵ�Ԫ�ش� ˵���ϴη����Ѿ������������б���һ�飩
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


