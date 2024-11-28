//试用顺序存储结构设计一个算法，仅用一个辅助结点，实现将线性表中的结点循环右移k位的运算，并分析算法的时间复杂度。
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef char datatype;
typedef struct 
{
    datatype data[1024];
    int cnt;
}sequenlist;//这样在定义函数时可以少写一个struct

sequenlist *L;

sequenlist *create()//创建顺序表
{
    int i=0;
    char ch;
    L=(sequenlist*)malloc(sizeof(sequenlist));
    L->cnt=-1;
    printf("输入顺序表的数据(#结束）：\n");
    while((ch=getchar())!='#')
    {
        L->data[i++]=ch;
        L->cnt++;
    }
    return L;

}

void output(sequenlist *L)
{
    for(int i=0;i<=L->cnt;i++)
    {
        printf("%c ",L->data[i]);
    }
}//打印顺序表所有数据

sequenlist *rightmove1(int k,sequenlist *L)//利用L->cnt-k处节点和辅助数组
{   
    int temp[1024];
    for(int i=0;i<=L->cnt-k;i++)//前n-k个数据暂存在数组里
    {
        temp[i]=L->data[i];
        
    }
    for(int i=0,j=L->cnt-k+1;i<=L->cnt;i++,j++)//将后K个数移到前k个数据处
    {
        L->data[i]=L->data[j];
    }
    
    for(int i=0,j=k;j<=L->cnt;j++,i++)//前n-k个数据存回原来的顺序表
    {
        L->data[j]=temp[i];
    }

}//创建新数组储存数据，只需要遍历顺序表即可

void reverse(int start,int end,char a[1024])
{   int temp;
    while(start<end)
    {
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}  
sequenlist *rightmove2(int k,sequenlist *L)
{
    reverse(0,L->cnt,L->data);//反转整个数组
    reverse(0,k-1,L->data);//反转前k个数据
    reverse(k,L->cnt,L->data);//反转后续数据
}//在进行反转操作时最多遍历一次数组，也就是进行n次操作，因此时间复杂度为O(n)


sequenlist *rightmove3(int k,sequenlist *L)
{
    while(k>0)
    {
        
        char temp=L->data[L->cnt];
        for(int i=L->cnt;i>0;i--)
        {
            L->data[i]=L->data[i-1];
        }
        L->data[0]=temp;
        k--;
    }
}//最坏情况下会将顺序表完整遍历两次，也就是进行n的平方次移动，时间复杂度为O（n方）

int main()
{
    sequenlist *list=create();
    int k;
    printf("输入右移位数k:\n");
    scanf("%d",&k);
    rightmove1(k,L);
    //rightmove2(k,L);
    //rightmove3(k,L);
    output(list);
}













