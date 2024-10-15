#include<iostream>
#include<climits>
using namespace std;

template <class T>
class stack
{
    T *a;
    int top,size;
    public:
    stack(int n =5)
    {
        a=new T[n];
        if (!a) return; // check allocation hua ki nai
        top = -1;
        size=n;
    }

    int isFullstack()
    {
        return top == size-1;
    }
    int isEmptystack()
    {
        return top == -1;
    }

    void push(T ele)
    {
        if(!isFullstack())
          a[++top]=ele;
          return;
    }

    T pop()
        {
            if(!isEmptystack())
               return a[top--];
            return INT_MAX;
        }
};

int isDigit(char c)
{ 
  if(c>='0' && c <='9')
    return 1;
  return 0;
}

int eval(int a ,int b,char opr)
{
 switch(opr)
 {
   case'+':return a+b;
   case'-':return a-b;
   case'x':return a*b;
   case'/':return a/b;   
   default: return 0;
 }
 return 0;
}

int isOperator(char op)
{
  if(op == '+' || op == '-' || op == 'x' || op == '/')
      return 1;
  return 0;
}

int main(int c,char **a)
{
 stack<int>s1(10);
 int n=0,o1,o2;
 char op;
 for(int i=1;i<c;i++)
 {
  if(isDigit(a[i][0]))
  {
   for(int j=0;a[i][j] != '\0';j++)
   {
     n=n*10+(a[i][j] - '0');
   }
    s1.push(n);
    n=0;
  }
  else
  {
   op=a[i][0];
   if(isOperator(a[i][0]))
   {
    if(!s1.isEmptystack())
    {
      o2=s1.pop();
    }
    if(!s1.isEmptystack())
    {
      o1=s1.pop();
    }
   }
  }
  cout<<s1.pop()<<endl;
  return 0;
 }
}

