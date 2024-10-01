#include<iostream>
using namespace std; 
class student
{
  private:
  string name;
  string PRN;
  float marks;
  public:
  void getdata()
  { cout<<"Enter Name -";
    cin>>name;
    cout<<"Enter PRN -";
    cin>>PRN;
    cout<<"Enter CGPA -";
    cin>>marks;
  }  
  void showdata()
  { cout<<"Name-"<<name<<"\n";
    cout<<"PRN-"<<PRN<<"\n";
    cout<<"CGPA-"<<marks<<"\n";
  } 
  void show()
  { cout<<name<<" "<<PRN<<" "<<marks<<"\n";
  } 
};
 int main()
 {
   int n;
   cout<<"Enter No. of Students :";
   cin>>n; 
  student s[n];
  for(int i=0;i<n;i++)
  {
    s[i].getdata();
    cout<<"Next Student: \n";
  }  
  for(int i=0;i<n;i++)
  {
     s[i].showdata();
     cout<<"Next Student: \n";
  }
   for(int i=0;i<n;i++)
  {
     s[i].show();
  }
  return 0;
 }   
  
