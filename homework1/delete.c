#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef char datatype;
typedef struct 
{
    datatype data[15];
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

void delete(sequenlist *L,int len,char k)
{
    int i=len;
    for(;i>0;i--)
    {
        if(L->data[i]==k)
        {
            L->cnt--;
        }
        if((L->data[i]!=k)&&(L->data[i-1]==k))
        {
            L->data[i-1]=L->data[i];
            L->cnt--;
        }
    }
}

void output(sequenlist *L)
{
    for(int i=0;i<=L->cnt;i++)
    {
        printf("%c ",L->data[i]);
    }
}//��ӡ˳�����������

int main()
{
    sequenlist *L;
    L=create();
    printf("������Ҫɾ����Ԫ�أ�");
    getchar();
    char k;
    scanf("%c",&k);
    delete(L,L->cnt,k);
    output(L);
}