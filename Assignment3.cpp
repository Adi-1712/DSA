/*
Aditya Hajare
123B1B125
Consider the playlist in a music player. Implement a playlist feature in music player application 
using singly linked list. Each song in the playlist is represented as a node in the linked list. Each 
node contains information about the song (such as title or artist or duration, etc.).  
The playlist should allow users to:  
a. Add songs 
b. Remove songs 
c. Display the entire playlist 
d. Play specific songs 
*/

#include<iostream>
using namespace std;

struct node{
    int songId;
    string title;
    // string artist;
    node* next;
};

class SongList{
    node* head;
    public:
    SongList()
    {
        head = NULL;
    }

    void showSong(node* temp)
    {
        cout<<temp->songId<<"\t"<<temp->title<<endl;
    }

    void AddSong(int id, string t){
        node* nn = new node;
        if(nn == NULL)
        {
            return;
        }
        nn->songId = id;
        nn->title = t;
        nn->next = NULL;
        if(head == NULL)
        {
            head = nn;
            return;
        }
        node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;

    }

    void RemoveSong()
    {
        node* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    
    }

    void removebytitle(string t)
    {
        if(head == NULL)
        {
            cout<<"No song in the list"<<endl;
            return;
        }
        node* temp = head;
        if(temp->title == t)
        {
            free(temp);
            head = head->next;
            return;
        }
        while(temp->next != NULL)
        {
            if(temp->next->title != t)
            {
                free(temp->next);
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        
        
    }

    void PlayAll(){
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        node* temp = head;
        while(temp != NULL)
        {
            showSong(temp);
            temp = temp->next;
        }
    }

    void count()
    {
        int cnt=0;
        node* temp = head;
        while(temp!=NULL)
        {
            temp = temp->next;
            cnt++;
        }
        cout<<"Total no of songs in list are "<<cnt<<endl;
    }

    int rec_count(node *p)
    {
        if(!p) return 0;
        return 1+ rec_count(p->next);
    }

    int count1()
    {
        return rec_count(head);
    }

    void ShufflePlay()
    {
        int c = count1();
        int done[c] = {0};

    }


    void search(string t)
    {
        node* temp = head;
        int flag=0;
        while(temp != NULL)
        {
            if(temp->title==t)
            {
                cout<<"Song found"<<endl;
                showSong(temp);
                flag=1;
                break;
            }
            temp = temp->next;
        }
        if(flag==0)
        {
            cout<<"Song not found"<<endl;
        }
        
    }

};

int main()
{
    SongList l1, l2;
    l1.AddSong(1, "Summer");
    l1.AddSong(2, "Winter");
    l1.AddSong(3, "Monsoon");
    // l1.RemoveSong();
    // l1.removebytitle("Winter");

    l1.PlayAll();
    l1.count();
    int cnt = l1.count1();
    cout<<cnt<<endl;
    // l2.AddSong(1, "Spring");
    // l2.PlayAll();
    l1.search("Winter");
    return 0;
}
