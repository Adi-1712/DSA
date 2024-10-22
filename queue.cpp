#include <iostream>
using namespace std;

struct node {
    int id;
    string name;
    int size;
    node *next;

    node(int id)
    { 
      id=id;
      next=NULL;
    }
};

class queue {
    node *front = NULL;
    node *rear = NULL;

public:
    void waitlist(int id) {
        node *nn = new node(id);
        cout << "Enter Details: Name and Size of Party: ";
        cin >> nn->name >> nn->size;

        if (rear) {
            rear->next = nn;
        } else {
            front = nn;
        }
        rear = nn;
        cout << "You have been added to the Waitlist.\n";
    }

    void seat() {
        if (front == NULL) {
            cout << "There's nobody waiting.\n";
            return;
        }
        node *temp = front;
        cout << temp->name << " has been seated.\n";
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
    }

    void show() {
        if (front == NULL) {
            cout << "There's nobody waiting.\n";
            return;
        }

        cout << "Currently Waiting:\n";
        node *current = front;
        while (current) {
            cout << current->name << " (Party Size: " << current->size << ")\n";
            current = current->next;
        }
    }
};

int main() {
    queue q1; 
    int choice;
    int id = 1; 

    cout << "Welcome to Regalis\n";
    do {
        cout << "Please select the action of your choice:\n"
             << "1. Waitlist next Person\n"
             << "2. Seat Next Person\n"
             << "3. Display Waitlist\n"
             << "4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                q1.waitlist(id++);
                break;
            case 2:
                q1.seat();
                break;
            case 3:
                q1.show();
                break;
            case 4:
                cout << "Thank you for visiting.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
  
