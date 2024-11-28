#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef char datatype;
typedef struct 
{
    datatype data[1024];
    int cnt;
}sequenlist;

sequenlist *L;

sequenlist *create()//创建顺序表
{   //getchar();
    int i=0;
    char ch;
    L=(sequenlist*)malloc(sizeof(sequenlist));
    L->cnt=-1;
    printf("输入顺序表的数据(以#结束）：\n");
    while((ch=getchar())!='#')
    {
        L->data[i++]=ch;
        L->cnt++;
    }
    return L;
}

void output(sequenlist *L)//打印顺序表所有数据
{
    for(int i=0;i<=L->cnt;i++)
    {
        printf("%c ",L->data[i]);
    }
    printf("\n");
}
//算法一
void bubblesort(sequenlist *A)
{   int flag=0;
    for(int i=0;i<A->cnt;i++)
    {
        for(int j=0;j<A->cnt-i;j++)
        {
            if(A->data[j]>A->data[j+1])
            {
                char tmp=A->data[j];
                A->data[j]=A->data[j+1];
                A->data[j+1]=tmp;
                flag=1;
            }
        }
        if(flag==0) break;
        
    }
}//冒泡排序 时间复杂度为O(n方)

sequenlist *join(sequenlist *A,sequenlist *B)
{
    for(int i=A->cnt+1,j=0;j<=B->cnt;i++,j++)
    {
        A->data[i]=B->data[j];
    }
    A->cnt+=B->cnt+1;
    return A;
}//将B中数据直接存储到A顺序表后


//**************************************************** */
//算法二
sequenlist *plus(sequenlist *A,sequenlist *B)
{   
    sequenlist *C=(sequenlist*)malloc(sizeof(sequenlist));
    int i=0,j=0,k=0;
    C->cnt=-1;
    while(i<=A->cnt&&j<=B->cnt)//任意一方到达表尾之前对顺序表进行遍历
    //其中一方到达末尾时会进行最后一次比较将较小者录入新顺序表
    {
        if(A->data[i]<B->data[j])//数据表中更小的数据优先进入新顺序表
        {
            C->data[k]=A->data[i];
            C->cnt++;
            i++;
            k++; 
        }
        if(A->data[i]>B->data[j])
        {
            C->data[k]=B->data[j];
            C->cnt++;
            j++;
            k++;
        }  
    }
    //特殊情况：某一顺序表提前走到末尾，则将另一顺序表后面的所有项继续存入新数据表
    while(j<=B->cnt)//特殊情况：某一顺序表到达表尾但是没有被录入新表，需要再进行一次操作//此操作与未达到表尾的操作第一步相同
         {
            C->data[k]=B->data[j];
            C->cnt++;
            j++;
          
         }
        while(i<=A->cnt)
         {
            C->data[k]=A->data[i];
            C->cnt++;
            i++;
              
         }
    C->cnt=k;
    return C;
}//时间复杂度为O（n）


int main()
{
    sequenlist *list1=create();
    sequenlist *list2=create();
    output(list1);
    output(list2);
    //算法1：直接连接顺序表并进行冒泡排序
    //sequenlist *list=join(list1,list2);
    //bubblesort(list1);
    //output(list);
    //算法2：将两顺序表数据进行比较，较小者优先存储进新顺序表
    sequenlist *list=plus(list1,list2);
    output(list);

    free(list);
    free(list1);
    free(list2);//释放内存
    

}
    