/*
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

void QuickSort(Employee *e, int low, int high)     // Worst case TC = O(n^2) and best case TC = O(nlogn)
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
    

    e[0].setdata(1012, "Aarav Patel");
    e[1].setdata(1002, "Maya Sharma");
    e[2].setdata(1015, "Ravi Kumar");
    e[3].setdata(1013, "Sanya Verma");
    e[4].setdata(1016, "Ishaan Gupta");
    e[5].setdata(1017, "Ritesh Patil");
    e[6].setdata(1007, "Arjun Rao");
    e[7].setdata(1019, "Aary Potdar");
    e[8].setdata(1020, "Yash Gavali");
    e[9].setdata(1010, "Kavya Reddy");
    e[10].setdata(1011, "Vikram Joshi");
    e[11].setdata(1001, "Tanuja Rao");
    e[12].setdata(1004, "Shreya Patil");
    e[13].setdata(1014, "Ritika Shah");
    e[14].setdata(1003, "Ankit Patil");
    e[15].setdata(1005, "Pooja Kumar");
    e[16].setdata(1006, "Jijai Surve");
    e[17].setdata(1018, "Sneha Agarwal");
    e[18].setdata(1008, "Nitin Patel");
    e[19].setdata(1009, "Kiran Mehta");




    MergeSort(e, 0, n-1);
    // QuickSort(e, 0, n);
    for(int i=0; i<n; i++)
    {
        e[i].showData();
    }

    return 0;
}
