/*
Aditya Hajare
123B1B125
Implement a simple text editor application using a doubly linked list to manage the text buffer. 
Text editor should support the following functionalities:  
a. Insert text 
b. Delete text 
c. Display text 
d. Search text 
e. Print text in reverse */

#include<iostream>
using namespace std;

class node{
    public:

    string data;
    node* next;
    node* prev;

    node(string val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }

};


class TextBuffer
{    
    public:

    node* head = NULL;
    node* tail = NULL;

    void insertatTail()
    {
        string val;
        cout<<"Enter string: ";
        cin>>val;
        node* nn = new node(val);
        if(head==NULL)
        {
            head = nn;
            tail = nn;
            return;
        }
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }

    void DeleteAtTail()
    {
        if(head == NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        tail = tail->prev;
        tail->next = NULL;
        free(tail->next);
    }

    void Display()
    {
        if(head == NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp = head;
        while(temp != NULL) 
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void DisplayusingTail()
    {
        if(head == NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp = tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }

    void DisplayusingPrev()
    {
        if(head == NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }

    void Deleteword(string word)
    {
        if(head->data==word)
        {
            node* temp = head;
            head = head->next;
            free(temp);
            return;
        }
       else
        {
          cout<<"Entry Not Found"
        }
        node* temp = head;
        while(temp->next->data!=word)
        {
            temp = temp->next;
        }
        node* curr = temp->next;
        temp->next=temp->next->next;
        free(curr);
    }

};


int main()
{
    TextBuffer t;
    t.insertatTail();
    t.insertatTail();
    t.insertatTail();
    t.insertatTail();
    t.insertatTail();
    t.Display();
    t.DeleteAtTail();
    t.Display();
    t.DisplayusingPrev();
    t.DisplayusingTail();
    t.Deleteword("Aditya");
    t.Display();
    return 0;
}
