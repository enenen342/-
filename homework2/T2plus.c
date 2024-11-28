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

sequenlist *create()//����˳���
{   //getchar();
    int i=0;
    char ch;
    L=(sequenlist*)malloc(sizeof(sequenlist));
    L->cnt=-1;
    printf("����˳��������(��#��������\n");
    while((ch=getchar())!='#')
    {
        L->data[i++]=ch;
        L->cnt++;
    }
    return L;
}

void output(sequenlist *L)//��ӡ˳�����������
{
    for(int i=0;i<=L->cnt;i++)
    {
        printf("%c ",L->data[i]);
    }
    printf("\n");
}
//�㷨һ
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
}//ð������ ʱ�临�Ӷ�ΪO(n��)

sequenlist *join(sequenlist *A,sequenlist *B)
{
    for(int i=A->cnt+1,j=0;j<=B->cnt;i++,j++)
    {
        A->data[i]=B->data[j];
    }
    A->cnt+=B->cnt+1;
    return A;
}//��B������ֱ�Ӵ洢��A˳����


//**************************************************** */
//�㷨��
sequenlist *plus(sequenlist *A,sequenlist *B)
{   
    sequenlist *C=(sequenlist*)malloc(sizeof(sequenlist));
    int i=0,j=0,k=0;
    C->cnt=-1;
    while(i<=A->cnt&&j<=B->cnt)//����һ�������β֮ǰ��˳�����б���
    //����һ������ĩβʱ��������һ�αȽϽ���С��¼����˳���
    {
        if(A->data[i]<B->data[j])//���ݱ��и�С���������Ƚ�����˳���
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
    //���������ĳһ˳�����ǰ�ߵ�ĩβ������һ˳�������������������������ݱ�
    while(j<=B->cnt)//���������ĳһ˳������β����û�б�¼���±���Ҫ�ٽ���һ�β���//�˲�����δ�ﵽ��β�Ĳ�����һ����ͬ
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
}//ʱ�临�Ӷ�ΪO��n��


int main()
{
    sequenlist *list1=create();
    sequenlist *list2=create();
    output(list1);
    output(list2);
    //�㷨1��ֱ������˳�������ð������
    //sequenlist *list=join(list1,list2);
    //bubblesort(list1);
    //output(list);
    //�㷨2������˳������ݽ��бȽϣ���С�����ȴ洢����˳���
    sequenlist *list=plus(list1,list2);
    output(list);

    free(list);
    free(list1);
    free(list2);//�ͷ��ڴ�
    

}
    