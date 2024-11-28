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
}//获取next数组

int getlen(seqstring *s)//获取长度
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
    strcpy(t->ch, "cdca"); //定义模式串和匹配串
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
        else//如果不匹配 将next数组中的j值赋给j，从s->len[j]重新开始匹配
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
