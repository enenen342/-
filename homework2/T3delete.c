#include <stdio.h>
#include <stdlib.h>
//假设在长度大于1的单循环链表中，既无头结点也无头指针,s为指向链表中某个结点的指针，试编写算法删除结点*s的直接前趋结点。
typedef  struct node{
    char data;            // 节点存储的数据
    struct node *next;   // 指向下一个节点的指针
}linklist;

linklist *linkcreate()//创建循环链表
{ 
    
    linklist *r, *s;
    linklist *head;
    char ch;
    head=(linklist*)malloc(sizeof(linklist));
    r=head;//r为上一节点的指针
    head->data=ch;//链表第一项为空
    head->next=NULL;
    printf("输入链表数据(按#结束):\n");
    while((ch=getchar())!='#')
    { 
         
        s=(linklist*)malloc(sizeof(linklist));//申请空间
        if(head->next==NULL)//判断第一项后继是否为空，为空向内存入数据
        {
            head->data=ch;
            head->next=s;
            continue;
        }
        s->data=ch;//读取数据
        r->next=s;//上一节点的next指针指向新建节点
        r=s;//r指针向后移动
    } 
   r->next=head;//链表尾节点指向头部  
    return head;//最终返回头指针
}

linklist *find(linklist *head,char k)
{
    linklist *s=head;
    while(s->data!=k)
    {
        s=s->next;
    }
    return s;
}//实际测试时无法直接给出指针进行删除，因此利用特定的数据查找到指针后再进行删除操作

linklist *delete(linklist *s)//不能使用头指针
{   
    linklist *p=s;
    while(p->next->next!=s)
    {
        p=p->next;
    }//p为s节点直接前趋的前趋
    
    p->next=s;//更改指针指向
    return s;
}

void printlinklist(linklist *head)
{
    linklist *f=head;//从第二项开始打印
    
   do{
        printf("%c ",f->data);
        f=f->next;//遍历链表打印data
    }while(f!=head);
    
    printf("\n");
}
int main()
{
    linklist *list1=linkcreate();
    printlinklist(list1);
    linklist *r, *t;
    printf("请输入需要进行操作的节点数据：");
    char k;
    scanf(" %c",&k);
    r=find(list1,k);
    t=delete(r);
    printlinklist(t);
    free(list1);
    free(r);
    free(t);
}