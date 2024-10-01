/* #include<iostream>
#include<string.h>
using namespace std;

struct node
{
int coeff;
int expo;
node*next;
node*prev;
};

class polynomial
{
    private:
    node*head;
    public:
    polynomial(){
        head=NULL;
        tail=NULL;
    }
     void add(int coeff,int expo)
     {
        node*nn = new node;
        if(!=nn)
        return;
     }
        nn->coeff;
        nn->expo;
        nn->next;
        nn->prev;
        if(head==NULL)
        {
            head=nn;
            tail=nn;
        }
        else
        {
            tail->next=nn;
            nn->prev=tail;
            tail=nn;
        }

void display()
{
    node*temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->coeff<<"x^"<<temp->expo<<"";
        temp=temp->next;
        return;
    }
}
 void init()
{
    int ch =1;
    node *p,*q=NULL;
    node *nn;
    int pow,c;
    do{
        p=head;
        nn=new node;
        if(!nn) return;
        cout<<"enter c and p\n";
        cin>>c>>pow;
        nn->coef=c;
        nn->expo=pow;
        nn->next=NULL;
        if(!head)
        head=nn;
        else
        {}
            while(p && p->expo>pow)
            {
                q=p;
                p=p->next;

            }
        if(!q)
        {
              nn->next =head;
              head=nn;
        }
}
}
                
void display()
{
    node*temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->coeff<<"x^"<<temp->expo<<"+";
        temp=temp->next;
    }
    cout<<endl;
}
};

*/
#include <iostream>
using namespace std;

struct node 
{
    int coeff;
    int expo;
    node* next;
    node* prev;
};

class polynomial 
{
private:
    node* head;
    node* tail; 

public:
    polynomial() 
    {
        head = NULL;
        tail = NULL;
    }

   
    void add(int coeff, int expo) 
    {
    
        node* nn = new node;
        if (!nn) return; 

        nn->coeff = coeff;
        nn->expo = expo;
        nn->next = nullptr;
        nn->prev = nullptr;

        if (head == nullptr) 
        {
            head = nn;
            tail = nn;
        } else
        {
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
    }

   
    void display() 
    {
        node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->coeff << "x^" << temp->expo;
            if (temp->next != nullptr) 
            {
                cout << " + "; 
            }
            temp = temp->next;
        }
        cout << endl;
    }

    
    void init()
     {
        int ch = 1;
        while (ch) 
        {
            int c, pow;
            cout << "Enter coefficient and exponent : ";
            cin >> c >> pow;
            if (c == 0 && pow == 0) break; 
            add(c, pow);
        }
    }
    
      polynomial addition(const polynomial& other) 
      {
        polynomial result;
        node* p1 = head;
        node* p2 = other.head;

        while (p1 != nullptr || p2 != nullptr) 
        {
            if (p1 != nullptr && (p2 == nullptr || p1->expo > p2->expo)) 
            {
                result.add(p1->coeff, p1->expo);
                p1 = p1->next;
            } else if (p2 != nullptr && (p1 == nullptr || p2->expo > p1->expo)) 
            {
                result.add(p2->coeff, p2->expo);
                p2 = p2->next;
            } else 
            {
                int sumCoeff = p1->coeff + p2->coeff;
                result.add(sumCoeff, p1->expo);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }
};

int main() {
    polynomial p1, p2;
    cout << "Input for first polynomial:" << endl;
    p1.init();
    cout << "The first polynomial is: ";
    p1.display();

    cout << "Input for second polynomial:" << endl;
    p2.init();
    cout << "The second polynomial is: ";
    p2.display();

    polynomial sum = p1.addition(p2);
    cout << "The sum of the polynomials is: ";
    sum.display();

    return 0;
}


    

    
     


           
                

    
        

        
     
    


