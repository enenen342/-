#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000  // ����ջ������С

// ����ջ�ṹ
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// ��ʼ��ջ
void initStack(Stack* stack) {
    stack->top = -1;  // ջΪ��
}

// ���ջ�Ƿ�Ϊ��
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// ��ջ����
bool push(Stack* stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        
        stack->items[++stack->top] = item;
        // ��ջ
        return true;
    }
    return false;  // ջ��
}

// ��ջ����
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        char tmp;
        tmp=stack->items[stack->top];
         stack->top--;
         return tmp;
         // ��ջ
    }
    return '\0';  // ���ջΪ�գ����ؿ��ַ�
}

bool issym(char *s,int n)
{   int i=0;
    Stack* stack;
    initStack(stack);
    for(i=0;i<=(n-1)/2;i++)
    {
        char current=s[i];
        push(stack, current);
    }
    for(i=(n-1)/2+1;i<=n;i++)
    {
        char current=s[i];
        if(pop(stack)!=s[i])
        return false;
    }
    if(isEmpty(stack))
    {
        return true;
    }
} 

int main()
{
    char* str="xyzyyx";
    int n=6;
    if(issym(str,n))
    {
        printf("ture\n");
    }
    else
    {
        printf("false\n");
    }
}