#include <stdio.h>
#include <stdlib.h>
//�����ڳ��ȴ���1�ĵ�ѭ�������У�����ͷ���Ҳ��ͷָ��,sΪָ��������ĳ������ָ�룬�Ա�д�㷨ɾ�����*s��ֱ��ǰ����㡣
typedef  struct node{
    char data;            // �ڵ�洢������
    struct node *next;   // ָ����һ���ڵ��ָ��
}linklist;

linklist *linkcreate()//����ѭ������
{ 
    
    linklist *r, *s;
    linklist *head;
    char ch;
    head=(linklist*)malloc(sizeof(linklist));
    r=head;//rΪ��һ�ڵ��ָ��
    head->data=ch;//�����һ��Ϊ��
    head->next=NULL;
    printf("������������(��#����):\n");
    while((ch=getchar())!='#')
    { 
         
        s=(linklist*)malloc(sizeof(linklist));//����ռ�
        if(head->next==NULL)//�жϵ�һ�����Ƿ�Ϊ�գ�Ϊ�����ڴ�������
        {
            head->data=ch;
            head->next=s;
            continue;
        }
        s->data=ch;//��ȡ����
        r->next=s;//��һ�ڵ��nextָ��ָ���½��ڵ�
        r=s;//rָ������ƶ�
    } 
   r->next=head;//����β�ڵ�ָ��ͷ��  
    return head;//���շ���ͷָ��
}

linklist *find(linklist *head,char k)
{
    linklist *s=head;
    while(s->data!=k)
    {
        s=s->next;
    }
    return s;
}//ʵ�ʲ���ʱ�޷�ֱ�Ӹ���ָ�����ɾ������������ض������ݲ��ҵ�ָ����ٽ���ɾ������

linklist *delete(linklist *s)//����ʹ��ͷָ��
{   
    linklist *p=s;
    while(p->next->next!=s)
    {
        p=p->next;
    }//pΪs�ڵ�ֱ��ǰ����ǰ��
    
    p->next=s;//����ָ��ָ��
    return s;
}

void printlinklist(linklist *head)
{
    linklist *f=head;//�ӵڶ��ʼ��ӡ
    
   do{
        printf("%c ",f->data);
        f=f->next;//���������ӡdata
    }while(f!=head);
    
    printf("\n");
}
int main()
{
    linklist *list1=linkcreate();
    printlinklist(list1);
    linklist *r, *t;
    printf("��������Ҫ���в����Ľڵ����ݣ�");
    char k;
    scanf(" %c",&k);
    r=find(list1,k);
    t=delete(r);
    printlinklist(t);
    free(list1);
    free(r);
    free(t);
}