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
int main()
{
/*
   stack <int>s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);
   s.push(60);
   s.push(70);
   s.push(80);
   s.push(90);
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   cout<<s.pop<<endl;
   return 1;
*/

   stack <char>s(9);
   s.push('a');
   s.push('b');
   s.push('c');
   s.push('d');
   s.push('e');
   s.push('f');
   s.push('g');
   s.push('h');
   s.push('i');
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;  
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;
   if(!s.isEmptystack())
     cout<<s.pop()<<endl;    
   return 1;
 

}