#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100
typedef struct 
{
    char ch[MAXSIZE];
    int len;
}seqstring;

void getnext(seqstring *t,int next[MAXSIZE])
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<=t->len)
    {
        if(j==-1||t->ch[i]==t->ch[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}//��ȡnext����

int getlen(seqstring *s)//��ȡ����
{
    int cnt=0;
    char *p=s->ch;
    while(*p!='\0')
    {
        p++;
        cnt++;
    }
    return cnt;
}

int main()
{
    seqstring *s = (seqstring *)malloc(sizeof(seqstring));
    seqstring *t = (seqstring *)malloc(sizeof(seqstring));
    strcpy(s->ch, "abbacdcabd");
    strcpy(t->ch, "cdca"); //����ģʽ����ƥ�䴮
    s->len = getlen(s);
    t->len = getlen(t);
    int next[MAXSIZE];
    getnext(t,next);
    for(int i=0;i<t->len;i++)
    {
        printf("%d ",next[i]);
    }
    printf("\n");
    int i=0,j=0;
    while (i<s->len&&j<t->len)
    {
        if(j==-1||s->ch[i]==t->ch[j])
        {
            i++;
            j++;
        }
        else//�����ƥ�� ��next�����е�jֵ����j����s->len[j]���¿�ʼƥ��
        {
            j=next[j];
        }
    }
    if(j==t->len)
    {
        printf("%d\n",i-t->len);
    }
    else
    {
        printf("could not find!");
    }
}
