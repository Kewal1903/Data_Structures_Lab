#include<iostream>
using namespace std;
int main(){
    char a[50];
    int i,c=0;
    cout<<"\n Enter a string: ";
    cin.getline(a,50);
    for(i=0;a[i] != '\0';i++)
        c++;
    cout<<"\n Length of string is: "<<c;
    return 0;
}