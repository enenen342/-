#include <stdio.h>
#include <stdlib.h>
//��������������кϲ���ͬʱ�����⿪�ٿռ�
//��������ӵڶ��ʼ����һ���¼����
typedef  struct node{
    char data;            // �ڵ�洢������
    struct node *next;   // ָ����һ���ڵ��ָ��
}linklist;

linklist *linkcreate()//�����ڵ�
{ 
    
    linklist *r, *s;
    linklist *head;
    char ch;
    head=(linklist*)malloc(sizeof(linklist));
    r=head;//rΪ��һ�ڵ��ָ��
    head->data=ch;//�����һ��Ϊ��
    printf("������������(��#����):\n");
    while((ch=getchar())!='#')
    {   
        s=(linklist*)malloc(sizeof(linklist));//����ռ�
        s->data=ch;//��ȡ����
        r->next=s;//��һ�ڵ��nextָ��ָ���½��ڵ�
        r=s;//rָ�������
        if(r!=NULL)
        {
            r->next=NULL;
        }//ȷ������nextָ�����ָ��ղ���������������  
    } 
    return head;//���շ���ͷָ��
}
//(����������������ϲ�Ϊһ�����������������ٿռ�(�������ڳ����д���))
linklist *plus(linklist *head1,linklist *head2)
{
    linklist *p, *q, *t1, *t2;
    linklist *end;
    p=head1->next;//������ĵڶ��ʼ����
    q=head2->next;//
    t1=head1;
    while((p!=NULL)&&(q!=NULL))
    {       
        if((p->data)>(q->data))
        {
            t1->next=q;//p��ǰ�̵�nextָ��q
            t2=q->next;//q�ĺ�̴�����������������б���
            q->next=p;//q�ĺ��ָ��p
            t1=q;//q�����Ѿ���Ϊԭ�������һ�������Ҫ������Ϊp��ǰ��
            q=t2;//q��ԭ�����м���������
        }
        else
        {   
            t1=p;p=p->next;//��������ڣ�Ҫ��p��ǰ�̱�����������������
        }
    }
    if(q!=NULL)
    {
        t1->next=q;
    }//����������������û�б����꣬��Ҫ�������ĩ��ӵ�����һ֮��
    return head1;
}
void printlinklist(linklist *head)
{
    linklist *f=head->next;//�ӵڶ��ʼ��ӡ
    while(f!=NULL)
    {
        printf("%c ",f->data);
        f=f->next;//���������ӡdata
    }
}
int main()
{   
    
    linklist *head1=linkcreate();
    linklist *head2=linkcreate();//����������
    printlinklist(head1);
    printf("\n");
    printlinklist(head2);//�ֱ�չʾ
    printf("\n");
    printlinklist(plus(head1,head2));//��������´�ӡ
}
