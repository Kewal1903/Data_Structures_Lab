#include<iostream>
using namespace std;
int main(){
    char a[50],b[50];
    cout<<"\n Enter first string: ";
    cin>>a;
    cout<<"\n Enter second string: ";
    cin>>b;
    int flag=1,i=0,len_a=0,len_b=0;
    for(i=0; a[i] != '\0';i++)
        len_a++;
    for(i=0; b[i] != '\0';i++)
        len_b++;
    if(len_a != len_b){
        flag = 0;
    }
    else{
        for(i=0;i<len_a;i++){
            if(a[i] != b[i]){
                flag = 0;
                break;
            }
        }
    }
    if (flag == 0)
        cout<<"\n Strings are not the same.";
    else
        cout<<"\n Strings are the same.";
    return 0;
}