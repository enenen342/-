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
    r=head;//rΪ��һ�ڵ��ָ��
    //�����һ��Ϊ��
    head->next=NULL;
    head->prior=NULL;
    printf("������������(��#����):\n");
    while((ch=getchar())!='#')
    { 
         
        s=(dlinklist*)malloc(sizeof(dlinklist));//����ռ�
        if(head->next==NULL)//�жϵ�һ�����Ƿ�Ϊ�գ�Ϊ�����ڴ�������
        {
            head->data=ch;
            head->next=s;
            head->freq=0;
            s->prior=head;
            continue;
        }
        s->data=ch;//��ȡ����
        s->freq=0;
        r->next=s;//��һ�ڵ��nextָ��ָ���½��ڵ�
        s->prior=r;
        r=s;//rָ������ƶ�
    }
    if(r!=NULL)
    {
        r->next=NULL;
    } 
    return head;//���շ���ͷָ��
}

void printlinklist(dlinklist *head)
{
    dlinklist *f=head;//��ʼ�� 
   do{
        printf("%c ",f->data);
        f=f->next;//���������ӡdata
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
    q=p->prior;//qΪp��ǰ��
    q=p->prior;//qΪp��ǰ��
    s=p->next;//sΪp�ĺ��
    r=q->prior;//rΪq��ǰ��
    while(q->freq<p->freq)//ǰ���ķ��ʴ����Ƚڵ�С ���߽���
    {   
        if(r==NULL)//ǰ��Ϊ��ͷ
        {
            q->next=s;s->prior=q;//s��ǰ����Ϊq
            p->next=q;q->prior=p;//p�ĺ�̱�Ϊq
            p->prior=NULL;//p��ʱ��Ϊ��ͷ
            head=p;//��Ҫ���±�ͷ
            break;
        }
        if(s==NULL)//pΪ��β
        {
            r->next=p;p->prior=r;//r�ĺ�̱�Ϊp
            p->next=q;q->prior=p;//p�ĺ�̱�Ϊq
            q->next=NULL;//���±�β�Ա����ǰ��
            //����pqrs
            q=p->prior;//qΪp��ǰ��
            s=p->next;//sΪp�ĺ��
            r=q->prior;//rΪq��ǰ��
            continue;
        }
        //����
        r->next=p;p->prior=r;//r�ĺ�̱�Ϊp
        q->next=s;s->prior=q;//s��ǰ����Ϊq
        p->next=q;q->prior=p;//p�ĺ�̱�Ϊq
        //����pqrs
        q=p->prior;//qΪp��ǰ��
        s=p->next;//sΪp�ĺ��
        r=q->prior;//rΪq��ǰ��
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
        printf("������Ҫ��λ�����ݣ�");
        char k;
        scanf(" %c",&k);
        s=Locate(s,k);
        printlinklist(s);
        printf("Ҫ������?(y/n)\n");
        getchar();
        ch=getchar();
    } while (ch=='y');   
}