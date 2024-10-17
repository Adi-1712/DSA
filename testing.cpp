#include <iostream>
using namespace std;

struct node 
{
    int data;
    node* next;
    node* prev;

    node()
    {
     data=0;
     next=NULL;
     prev=NULL;
    }
    node(int d)
    { 
     data=d;
     next=NULL;
     prev=NULL;
    }
};   

class CLL 
{
public:
    node* header;
    node* tail;

CLL() 
 { 
  header=NULL;
  tail=NULL; 
 }
void add(int a) 
    {
        node* nn = new node(a); 
        if (header == NULL) 
        {
            
            header = nn;
            tail = nn;
            nn->next = header;
            nn->prev = header;  
        }
        else 
        {
            
            tail->next = nn; 
            nn->prev = tail; 
            nn->next = header;
            header->prev = nn;
            tail = nn; 
        }
    }

void print() 
    {
        if (header == NULL) {
            cout << "List is Empty" << endl;
            return;
        }

        node* curr = header;
        do {
            cout << curr->data<<"->";
            curr = curr->next; 
        } while (curr != header);
        cout <<"NULL"<<endl;
    }
    
void reversal()
{
  node *curr=header;
  node *temp=NULL;
  if(header== NULL)
  {
    cout<<"List is Empty";
    return;
  }
  do
  {
    temp=curr->prev;
    curr->prev=curr->next;
    curr->next=temp;
    curr=curr->prev;
   } 
   while(curr != header); 
   header=header->next;
}
};

int main() 
{
    CLL o1;
    o1.add(1);
    o1.add(2);
    o1.add(3);
    o1.add(4);
    o1.add(5);
    o1.add(6);
    o1.add(7);
    o1.add(8);
    o1.print();
    o1.reversal();
    o1.print();
    return 0;
}

  
  


