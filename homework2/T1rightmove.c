//����˳��洢�ṹ���һ���㷨������һ��������㣬ʵ�ֽ����Ա��еĽ��ѭ������kλ�����㣬�������㷨��ʱ�临�Ӷȡ�
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef char datatype;
typedef struct 
{
    datatype data[1024];
    int cnt;
}sequenlist;//�����ڶ��庯��ʱ������дһ��struct

sequenlist *L;

sequenlist *create()//����˳���
{
    int i=0;
    char ch;
    L=(sequenlist*)malloc(sizeof(sequenlist));
    L->cnt=-1;
    printf("����˳��������(#��������\n");
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
}//��ӡ˳�����������

sequenlist *rightmove1(int k,sequenlist *L)//����L->cnt-k���ڵ�͸�������
{   
    int temp[1024];
    for(int i=0;i<=L->cnt-k;i++)//ǰn-k�������ݴ���������
    {
        temp[i]=L->data[i];
        
    }
    for(int i=0,j=L->cnt-k+1;i<=L->cnt;i++,j++)//����K�����Ƶ�ǰk�����ݴ�
    {
        L->data[i]=L->data[j];
    }
    
    for(int i=0,j=k;j<=L->cnt;j++,i++)//ǰn-k�����ݴ��ԭ����˳���
    {
        L->data[j]=temp[i];
    }

}//���������鴢�����ݣ�ֻ��Ҫ����˳�����

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
    reverse(0,L->cnt,L->data);//��ת��������
    reverse(0,k-1,L->data);//��תǰk������
    reverse(k,L->cnt,L->data);//��ת��������
}//�ڽ��з�ת����ʱ������һ�����飬Ҳ���ǽ���n�β��������ʱ�临�Ӷ�ΪO(n)


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
}//�����»Ὣ˳��������������Σ�Ҳ���ǽ���n��ƽ�����ƶ���ʱ�临�Ӷ�ΪO��n����

int main()
{
    sequenlist *list=create();
    int k;
    printf("��������λ��k:\n");
    scanf("%d",&k);
    rightmove1(k,L);
    //rightmove2(k,L);
    //rightmove3(k,L);
    output(list);
}













