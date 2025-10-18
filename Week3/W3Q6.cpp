#include<iostream>
using namespace std;
int main(){
    char s1[100],s2[100],s3[100];
    cout<<"\n Enter the string: ";
    cin.getline(s1,100);
    cout<<"\n Enter substring to delete: ";
    cin.getline(s2,100);
    int i=0,j=0,k=0,n=0,l2=0,flag=0;
    for(i=0;s2[i]!='\0';i++)
        l2++;
    for(i=0;s1[i]!='\0';i++){
        k=i;
        while(s1[i] = s2[j]){
            i++;
            j++;
        }
        if(j==l2){
            flag = 1;
            break;
        }
    }
    if (flag==0)
        i=k;
    else
        flag = 0;
    s3[n++] = s1[i];
    s3[n] = '\0';
    cout<<"String after deletion: ";
    puts(s3);
    return 0;
}    