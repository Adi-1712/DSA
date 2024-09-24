/*
Aditya Hajare
123B1B125
Consider Employee database of PCCOE (at least 20 records). Database contains different fields of
every employee like EMP-ID, EMP-Name and EMP-Salary.
a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort
b. Arrange list of Employee alphabetically using Merge Sort
*/

#include<iostream>
using namespace std;

class Employee
{
    private:
    int emp_id;
    string emp_name;

    public:
    friend void Merge(Employee *e, int, int, int);
    friend void MergeSort(Employee *e, int, int);

    
    friend int Partition(Employee *e, int low, int high);
    friend void QuickSort(Employee *e, int low, int high); 

    void setdata(int emp_id, string emp_name) {
        this->emp_id = emp_id;
        this->emp_name = emp_name;  
    }

    void showData()
    {
        cout<<emp_id<<"\t"<<emp_name<<endl;
    }

};


void Merge(Employee e[], int low, int mid, int high)
{
    Employee temp[high+1];
    int k=0;
    int n=high-low+1;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high)
    {
        if(e[left].emp_name <= e[right].emp_name)
        {
            temp[k]=e[left];
            left++;
            k++;
        }
        else{
            temp[k]=e[right];
            right++;
            k++;
        }
    }

    while(left<=mid)
    {
        temp[k]=e[left];
        left++;
        k++;
    }

    while(right<=high)
    {
        temp[k]=e[right];
        right++;
        k++;
    }
    for(int i=0; i<n; i++)
    {
        e[i+low] = temp[i];
    }
}

void MergeSort(Employee e[], int low, int high)
{

    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    MergeSort(e, low, mid);
    MergeSort(e, mid+1, high);
    Merge(e, low, mid, high);
}





int Partition(Employee *e, int low, int high)
{
    Employee pivot = e[low];
    int start = low;
    int end = high;

    while(start < end)
    {
        while(e[start].emp_id <= pivot.emp_id)
        {
            start++;
        }
        while(e[end].emp_id > pivot.emp_id)
        {
            end--;
        }
        if(start<end){
            Employee temp = e[start];
            e[start] = e[end];
            e[end] = temp;
        }
    }
    Employee temp = e[low];
    e[low] = e[end];
    e[end] = temp;
    return end;
}

void QuickSort(Employee *e, int low, int high)     
{
    if(low < high)
    {
        int loc = Partition(e, low, high);
        QuickSort(e, low, loc-1);
        QuickSort(e, loc+1, high);
    }
}

int main()
{
    Employee e[20];
    int n=20;
    

    e[0].setdata(1012,"Aditya hajare");
    s[1].setdata("karan jadhav");
    s[2].setdata("Karan kumar");
    s[3].setdata("sahil sinha");
    s[4].setdata("keya jadhav");
    s[5].setdata("Neha Singh");
    s[6].setdata("Nalini oberoi");
    s[7].setdata("Priya jadhav");
    s[8].setdata("kartik Desai");
    s[9].setdata("Kavyansh joshi");
    s[10].setdata("Vikram mehta");
    s[11].setdata("Tanuja patil");
    s[12].setdata("Amit shah");
    s[13].setdata("Ritika sharma");
    s[14].setdata("anuj khandelwal" );
    s[15].setdata("Pooja Kumar" );
    s[16].setdata("Manish Sisodia");
    s[17].setdata("shravan singhania");
    s[18].setdata("Neha patil");
    s[19].setdata("Kiran Mehta");

    e[1].setdata(1002, "Aditya Hajare");
    e[2].setdata(1015, "Ravi Shastri");
    e[3].setdata(1013, "Soniya sheikh");
    e[4].setdata(1016, "ali abdul");
    e[5].setdata(1017, "Ritesh patil");
    e[6].setdata(1007, "Arjun ramarao");
    e[7].setdata(1019, "priya patel");
    e[8].setdata(1020, "Yash sinha");
    e[9].setdata(1010, "rama rao");
    e[10].setdata(1011, "narendra singh");
    e[11].setdata(1001, "tritya patel");
    e[12].setdata(1004, "Shreya mahajan");
    e[13].setdata(1014, "gadeen Shah");
    e[14].setdata(1003, "Ankit kapoor");
    e[15].setdata(1005, "Pooja sivakumar");
    e[16].setdata(1006, "suresh kapoor");
    e[17].setdata(1018, "mugdha poonawalla");
    e[18].setdata(1008, "Neha sharma");
    e[19].setdata(1009, "anushka sinha");




    MergeSort(e, 0, n-1);
    // QuickSort(e, 0, n);
    for(int i=0; i<n; i++)
    {
        e[i].showData();
    }

    return 0;
}
