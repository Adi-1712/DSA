/*
Aditya Hajare
123B1B125
Consider a student database of SY COMP class (at least 15 records). Database contains different
fields of every student like Roll No, Name and SGPA.
a. Design a roll call list, arrange list of students according to roll numbers in ascending order
using Insertion Sort
b. Arrange list of students alphabetically using shell sort
c. Arrange list of students to find out first ten toppers from a class using Radix sort
*/


#include<iostream>
#include<string.h>
using namespace std;

class Student
{
    private:
    int roll_no;
    string name;
    int sgpa;

    public:
    friend void InsertionSort(Student *s, int n);
    friend void ShellSort(Student *s, int n);
    friend void RadixSort(Student *s, int n);
    friend void CountSort(Student *s, int n, int);
    friend void get_10_toppers(Student *s);

    void setdata(string name, int roll_no, int sgpa) {
        this->name = name;
        this->roll_no = roll_no;
        this->sgpa = sgpa;
    }

    void showData()
    {
        cout<<roll_no<<"\t"<<name<<"\t"<<sgpa<<endl;
    }
};


void InsertionSort(Student s[], int n)
{
    for(int i=1; i<n; i++)
    {
        Student key = s[i];
        int j=i-1;
        while(j>=0 && s[j].roll_no > key.roll_no)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
}


void ShellSort(Student s[], int n)
{
    for(int gap = n/2; gap>0; gap/=2)
    {
        for(int j=gap; j<n; j++)
        {
            for(int i=j-gap; i>=0; i-=gap)
            {
                if(s[i+gap].name > s[i].name)
                {
                    break;
                }
                else{
                    Student temp = s[i+gap];
                    s[i+gap] = s[i];
                    s[i] = temp;
                }
            }
        }
    }
}

void CountSort(Student *s, int n, int pos)
{
    Student res[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(s[i].sgpa / pos) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        res[--count[(s[i].sgpa / pos) % 10]] = s[i];
    }
    for (int i = 0; i < n; i++)
    {
        s[i] = res[i];
    }
}

void RadixSort(Student *s, int n)
{
    Student max = s[0];
    for (int i = 0; i < n; i++)
    {
        if (s[i].sgpa > max.sgpa)
        {
            max = s[i];
        }
    }
    for (int pos = 1; max.sgpa / pos > 0; pos *= 10)
    {
        CountSort(s, n, pos);
    }
}

void get_10_toppers(Student s[])
{
    for(int i=19; i>=10; i--)
    {
        s[i].showData();
    }
}


int main()
{
    Student s[20];
    int n=20;
    
    s[0].setdata("Aditya hajare",1 , 6);
    s[1].setdata("karan jadhav", 2, 7);
    s[2].setdata("Karan kumar", 3, 8);
    s[3].setdata("sahil sinha", 5, 6);
    s[4].setdata("keya jadhav", 4, 7);
    s[5].setdata("Neha Singh", 6, 8);
    s[6].setdata("Nalini oberoi", 7, 7);
    s[7].setdata("Priya jadhav", 8, 8);
    s[8].setdata("kartik Desai", 9, 5);
    s[9].setdata("Kavyansh joshi", 10, 9);
    s[10].setdata("Vikram mehta",11, 10);
    s[11].setdata("Tanuja patil", 13, 9);
    s[12].setdata("Amit shah", 12, 6);
    s[13].setdata("Ritika sharma", 17, 8);
    s[14].setdata("anuj khandelwal", 16, 5);
    s[15].setdata("Pooja Kumar", 15, 9);
    s[16].setdata("Manish Sisodia", 14, 7);
    s[17].setdata("shravan singhania", 18, 6);
    s[18].setdata("Neha patil",20 , 6);
    s[19].setdata("Kiran Mehta", 19, 8);

    InsertionSort(s, n);
    cout<<"Student data sorted according to their roll no."<<endl;
    for(int i=0; i<n; i++)
    {
        s[i].showData();
    }
    cout<<endl;
    ShellSort(s, n);
    cout<<"Student data sorted according to their names."<<endl;
    for(int i=0; i<n; i++)
    {
        s[i].showData();
    }
    cout<<endl;
    RadixSort(s, n);
    cout<<"Student data sorted according to their sgpa."<<endl;
    for(int i=0; i<n; i++)
    {
        s[i].showData();
    }
    cout<<endl;
    cout<<"TOP 10 TOPPER'S ARE: "<<endl;
    get_10_toppers(s);
    
    return 0;
}
