//1������һ��ֻ���� ��(������)������{������}������[������]�� ���ַ������ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺�����ű�������ͬ���͵������űպϡ������ű�������ȷ��˳��պϡ�ע����ַ����ɱ���Ϊ����Ч�ַ�����
//ʾ�� 1:
//����: ��()[]{}��
//���: true
//ʾ�� 2:
//����: ��(]��
//���: false
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
        if(current==')'||current=='}'||current==']')//��ջ�����г�ջ��Ȼ�����ƥ�䣬��ƥ���ջ��Ԫ�س�ջ�󷵻�false
        {
            if (isEmpty(&stack)||pop(&stack)!= mapping[current]) 
            {
                return false;
            }
        }
        else//��������ջ
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
