#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    int freq;
    struct node *prior,*next;
}dlinklist;

dlinklist *create()
{  
    dlinklist *r, *s;
    dlinklist *head;
    char ch;
    head=(dlinklist*)malloc(sizeof(dlinklist));
    r=head;//r为上一节点的指针
    //链表第一项为空
    head->next=NULL;
    head->prior=NULL;
    printf("输入链表数据(按#结束):\n");
    while((ch=getchar())!='#')
    { 
         
        s=(dlinklist*)malloc(sizeof(dlinklist));//申请空间
        if(head->next==NULL)//判断第一项后继是否为空，为空向内存入数据
        {
            head->data=ch;
            head->next=s;
            head->freq=0;
            s->prior=head;
            continue;
        }
        s->data=ch;//读取数据
        s->freq=0;
        r->next=s;//上一节点的next指针指向新建节点
        s->prior=r;
        r=s;//r指针向后移动
    }
    if(r!=NULL)
    {
        r->next=NULL;
    } 
    return head;//最终返回头指针
}

void printlinklist(dlinklist *head)
{
    dlinklist *f=head;//初始化 
   do{
        printf("%c ",f->data);
        f=f->next;//遍历链表打印data
    }while(f!=NULL);
    
    printf("\n");
}

dlinklist *Locate(dlinklist *head,char k)
{   
    dlinklist *p;
    p=head;
    while(p->data!=k)
    {
        p=p->next;
    }
    p->freq++;
    dlinklist *q, *s, *r;
    q=p->prior;//q为p的前趋
    q=p->prior;//q为p的前趋
    s=p->next;//s为p的后继
    r=q->prior;//r为q的前趋
    while(q->freq<p->freq)//前趋的访问次数比节点小 二者交换
    {   
        if(r==NULL)//前趋为表头
        {
            q->next=s;s->prior=q;//s的前趋变为q
            p->next=q;q->prior=p;//p的后继变为q
            p->prior=NULL;//p此时作为表头
            head=p;//需要更新表头
            break;
        }
        if(s==NULL)//p为表尾
        {
            r->next=p;p->prior=r;//r的后继变为p
            p->next=q;q->prior=p;//p的后继变为q
            q->next=NULL;//更新表尾以便继续前移
            //更新pqrs
            q=p->prior;//q为p的前趋
            s=p->next;//s为p的后继
            r=q->prior;//r为q的前趋
            continue;
        }
        //交换
        r->next=p;p->prior=r;//r的后继变为p
        q->next=s;s->prior=q;//s的前趋变为q
        p->next=q;q->prior=p;//p的后继变为q
        //更新pqrs
        q=p->prior;//q为p的前趋
        s=p->next;//s为p的后继
        r=q->prior;//r为q的前趋
    }
    return head;
}


int main()
{
    dlinklist *s=create();
    printlinklist(s);
    char ch;
    do
    {
        printf("输入需要定位的数据：");
        char k;
        scanf(" %c",&k);
        s=Locate(s,k);
        printlinklist(s);
        printf("要继续吗?(y/n)\n");
        getchar();
        ch=getchar();
    } while (ch=='y');   
}