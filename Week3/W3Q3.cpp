#include<iostream>
using namespace std;
int main(){
    char str1[50], str2[50], str3[100];
    int i=0,j=0;
    cout<<"\n Enter first string: ";
    cin.getline(str1,50);
    cout<<"\n Enter second string: ";
    cin.getline(str2,50);
    for(i=0;str1[i] != '\0';i++)
        str3[i] = str1[i];
    while(str2[j] != '\0'){
        str3[i] = str2[j];
        j++;
        i++;
    }
    str3[i] = '\0';
    cout<<"\n Concatenated string is :"<<str3;
    return 0;
}
