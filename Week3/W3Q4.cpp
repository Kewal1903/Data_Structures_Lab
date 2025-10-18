#include<iostream>
using namespace std;
int main(){
    char a[30],b[30],c[60];
    int pos,len_a=0,len_b=0,t=0,i=0,p,x,o,tot_size;
    cout<<"\n Enter first string: ";
    cin.getline(a,30);
    cout<<"\n Enter second string: ";
    cin.getline(b,30);
    cout<<"\n Enter position for insertion of string: ";
    cin>>p;
    pos = p-1;
    for(i=0;a[i] != '\0';i++)
        len_a++;
    for(i=0;b[i] != '\0';i++)
        len_b++;
    i = 0;
    while(i<len_a){
        c[i] = a[i];
        i++;
    }
    c[i] = '\0';
    tot_size = len_a + len_b;
    o = pos + len_b;
    for(i=pos;i<tot_size;i++){
        x = c[i];
        if(t<len_b){
            a[i] = b[t];
            t = t+1;
    }
    a[o] = x;
    o = o+1;}
    cout<<"Modified string is: "<<a;
    return 0;
}    