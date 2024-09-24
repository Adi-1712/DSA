#include<iostream>
using namespace std;

struct node 
{
    int Id;
    node* next;
};

class List 
{
    node *head, *tail;

public:
    List() 
    {
        head = NULL;
        tail = NULL;
    }

    void add_beg()
     {
        int id;
        cout << "Enter Entry: ";
        cin >> id;

        node* nn = new node;
        if (nn == NULL) 
        {
            cout << "Memory allocation failed!" << endl;
            return;
        }
        nn->Id = id;
        nn->next = head; 
        head = nn; 
        if (tail == NULL) 
        { 
            tail = nn;
        }
    }

    void add_end()
    {
        int id;
        cout << "Enter Entry: ";
        cin >> id;

        node* nn = new node;
        if (nn == NULL) 
        {
            cout << "Memory allocation failed!" << endl;
            return;
        }
        nn->Id = id;
        nn->next = NULL; 

        if (head == NULL) 
        { 
            head = nn;
            tail = nn;
        } else {
            tail->next = nn; 
            tail = nn; 
        }
    }

    void delete_end() 
    {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head == tail)
         { 
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next; 
        }
        delete tail; 
        tail = temp; 
        tail->next = NULL; 
    }

    void delete_beg()
    {
         if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head == tail)
        {
            head=NULL;
            tail=NULL;
            return ;
        }
        node* temp = head;
        head = head->next;
        delete temp;
        tail->next=head;
        return;
    }

    void display() {
        if (head == NULL)
       {
            cout << "List is empty!" << endl;
            return;
        }
        node* temp = head;
        while (temp != NULL) 
        {
            cout << temp->Id << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void search() 
    {
        int id;
        cout << "Enter Entry: ";
        cin >> id;

        node* temp = head;
        while (temp != NULL) 
        {
            if (temp->Id == id) 
            {
                cout << "Found: " << id << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not found: " << id << endl;
    }

    void serdel() {
        int id;
        cout << "Enter Entry: ";
        cin >> id;

        if (head == NULL) 
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->Id == id) 
        { 
            head = head->next; 
            cout << "Deleted: " << id << endl;
            return;
        }

        node* temp = head;
        while (temp->next != NULL && temp->next->Id != id) 
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Not found: " << id << endl;
        } else
         {
            node* del = temp->next;
            temp->next = del->next; 
            delete del;
            cout << "Deleted: " << id << endl;
        }
    }
};

int main() {
    int ch;
    List L1;

    while (true) 
    {
        cout << "*****Menu*****" << endl;
        cout << "1. Display" << endl;
        cout << "2. Add at Beginning" << endl;
        cout << "3. Add at End" << endl;
        cout << "4. Search" << endl;
        cout << "5. Search and Delete" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose your choice: ";
        cin >> ch;
        cout << endl;

        switch (ch) 
        {
            case 1:
                L1.display();
                break;
            case 2:
                L1.add_beg();
                break;
            case 3:
                L1.add_end();
                break;
            case 4:
                L1.search();
                break;
            case 5:
                L1.serdel();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

