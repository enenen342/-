//1、给定一个只包括 ‘(’，’)’，’{’，’}’，’[’，’]’ 的字符串，判断字符串是否有效。
//有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。注意空字符串可被认为是有效字符串。
//示例 1:
//输入: “()[]{}”
//输出: true
//示例 2:
//输入: “(]”
//输出: false
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

bool isvalid(char *s)
{   
    Stack stack;
    initStack(&stack);
    char mapping[1000];
    mapping[')']='(';
    mapping['}']='{';
    mapping[']']='[';
    for(int i=0;s[i]!='\0';i++)
    {
        char current=s[i];
        if(current==')'||current=='}'||current==']')//将栈顶进行出栈，然后进行匹配，不匹配和栈底元素出栈后返回false
        {
            if (isEmpty(&stack)||pop(&stack)!= mapping[current]) 
            {
                return false;
            }
        }
        else//左括号入栈
        {
            push(&stack, current);        
        }
    }
    return isEmpty(&stack);
}
int main()
{
    char* str1="({[]})";
    if(isvalid(str1))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}
