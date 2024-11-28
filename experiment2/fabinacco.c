#include <stdio.h>
int fibnacco(int n)
{   
    int fib;
    if(n==0) fib=0;
    else
    {
        if(n==1) fib=1;
        else  fib=fibnacco(n-1)+fibnacco(n-2);
    }
    return fib;

}
int main()
{   
    int n=6;
    n=fibnacco(n);
    printf("%d",n);
}
