#include <stdio.h>
#include <stdlib.h>
//将两递增链表进行合并，同时不另外开辟空间
//链表遍历从第二项开始，第一项不记录数据
typedef  struct node{
    char data;            // 节点存储的数据
    struct node *next;   // 指向下一个节点的指针
}linklist;

linklist *linkcreate()//创建节点
{ 
    
    linklist *r, *s;
    linklist *head;
    char ch;
    head=(linklist*)malloc(sizeof(linklist));
    r=head;//r为上一节点的指针
    head->data=ch;//链表第一项为空
    printf("输入链表数据(按#结束):\n");
    while((ch=getchar())!='#')
    {   
        s=(linklist*)malloc(sizeof(linklist));//申请空间
        s->data=ch;//读取数据
        r->next=s;//上一节点的next指针指向新建节点
        r=s;//r指针向后移
        if(r!=NULL)
        {
            r->next=NULL;
        }//确保链表next指针最后指向空不会出现无穷个数据  
    } 
    return head;//最终返回头指针
}
//(将两个递增单链表合并为一个递增单链表，不另开辟空间(单链表在程序中创建))
linklist *plus(linklist *head1,linklist *head2)
{
    linklist *p, *q, *t1, *t2;
    linklist *end;
    p=head1->next;//从链表的第二项开始遍历
    q=head2->next;//
    t1=head1;
    while((p!=NULL)&&(q!=NULL))
    {       
        if((p->data)>(q->data))
        {
            t1->next=q;//p的前继的next指向q
            t2=q->next;//q的后继储存起来方便后续进行遍历
            q->next=p;//q的后继指向p
            t1=q;//q现在已经作为原来链表的一部分因此要重新作为p的前继
            q=t2;//q在原链表中继续向后遍历
        }
        else
        {   
            t1=p;p=p->next;//如果不大于，要将p的前继保存起来并且向后遍历
        }
    }
    if(q!=NULL)
    {
        t1->next=q;
    }//遍历到最后链表二还没有遍历完，需要将链表二末项接到链表一之后
    return head1;
}
void printlinklist(linklist *head)
{
    linklist *f=head->next;//从第二项开始打印
    while(f!=NULL)
    {
        printf("%c ",f->data);
        f=f->next;//遍历链表打印data
    }
}
int main()
{   
    
    linklist *head1=linkcreate();
    linklist *head2=linkcreate();//创建两链表
    printlinklist(head1);
    printf("\n");
    printlinklist(head2);//分别展示
    printf("\n");
    printlinklist(plus(head1,head2));//重组后重新打印
}
