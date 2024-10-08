#include<limits.h>
#include"stack.h"

stack::stack()
    {
        a=new int[5];
        if (!a) return; // check allocation hua ki nai
        top = -1;
        size=5;
    }


stack::stack(int n)
    {
        a=new int[n];
        if (!a) return; // check allocation hua ki nai
        top = -1;
        size=n;
    }


    int stack::isFull()
    {
        return top == size-1;
    }
    int stack::isEmpty()
    {
        return top == -1;
    }

    void stack::push(int operand)
    {
        if(top==size-1)
           return;
        a[++top]=operand;
          return;
    }

    int stack::pop()
        {
            if(top==-1)
               return INT_MAX; 
            return a[top--];
        }

