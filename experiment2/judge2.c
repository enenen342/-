#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000  // 定义栈的最大大小

// 定义栈结构
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1;  // 栈为空
}

// 检查栈是否为空
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 入栈操作
bool push(Stack* stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        
        stack->items[++stack->top] = item;
        // 入栈
        return true;
    }
    return false;  // 栈满
}

// 出栈操作
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        char tmp;
        tmp=stack->items[stack->top];
         stack->top--;
         return tmp;
         // 出栈
    }
    return '\0';  // 如果栈为空，返回空字符
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