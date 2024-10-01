#include<iostream>
using namespace std;

struct node{
    int Id;
    node* next;
};

class List{
    node *head,*tail;
    public:
    List()
    {
        head = NULL;
        tail=NULL;
    }

    void add_beg()
    {   cout<<"Enter Entry"<<endl;
        cin>>id;
        node* nn = new node;
        if(nn == NULL)
        {
            return;
        }
        nn->Id = id;
        nn->next = NULL;
        if(head == NULL)
        {
            head = nn;
            tail=nn;
            
            return;
        }
        node* temp = head;
        while(temp->next != temp)
        {
            temp = temp->next;
        }
        temp->next = nn;

    }
    
    void add_end()
    { 
      cout<<"Enter Entry"<<endl;
      cin>>id;
        
    }
    void delete_end()
    {
        node* temp = head;
        while(temp->next->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        temp=tail;
    
    }

    void display(){
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        while(temp!=tail)
        {
            show(temp);
            temp = temp->next;
        }
    }
    
    void search()
    {
      cout<<"Enter Entry"<<endl;
      cin>>id;
      if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        if(temp==id)
        {
          cout<<"Found";
        } 
        else
        {
            temp = temp->next;
        }
    }
    void serdel()
    {
      cout<<"Enter Entry"<<endl;
      cin>>id;
      if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        if(temp->next==id)
        {
          cout<<"Found";
          temp->next=temp->next->next;
          cout<<"Deleted";    
        } 
        else
        {
            temp = temp->next;
        }
    }
};

int main()
{ int ch;
  List L1;
  while(1)
  {
    cout<<"*****Menu*****";
    cout<<"1.Display";
    cout<<"2.Add at Beginning";
    cout<<"3.Add at End";
    cout<<"4.Search";    
    cout<<"5.Search and Delete";
    cout<<"6.Exit";    
    cout<<"Choose your choice ";
    cin>>ch;
    cout<<endl;
    switch(ch)
    {
       case 1:L1.display();
              break;
       case 2:L1.add_beg();
       case 3:L1.add_end();
       case 4:L1.search();
       case 5:L1.serdel();
       case 6:return 0;
       default:return 0;
    }
   }      
              
              
