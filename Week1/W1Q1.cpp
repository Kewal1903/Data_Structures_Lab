#include<iostream>
using namespace std;
class Employee{
    int Emp_no;
    char name[20];
    int Basic_Salary;
    float DA;
    float Gross;
    float IT;
    float Net;
    public:
    void input(){
        cout<<"\n Enter employee number: ";
        cin>>Emp_no;
        cout<<"\n Enter employee name: ";
        cin>>name;
        cout<<"\n Enter basic salary: ";
        cin>>Basic_Salary;
        DA = Basic_Salary*(0.12);
        Gross = Basic_Salary+DA;
        IT = Gross*(0.18);
        Net = Gross - IT;
    }
    void display(){
        cout<<"\n The gross salary is: "<<Gross;
        cout<<"\n The net salary is: "<<Net;        
    }
};
int main(){
    int i,n;
    cout<<"\n Enter number of employees: ";
    cin>>n;
    Employee e1[n];
    for(i=0;i<n;i++){
        e1[i].input();
        e1[i].display();
    }
    return 0;
}