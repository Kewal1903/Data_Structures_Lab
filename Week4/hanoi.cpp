#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
void tower(int num, string source, string dest, string aux){
        if (num == 1){
                cout<<"\n Move from "<<source<<" to "<<dest<<"\n";
                return;}
        else{
                tower(num-1,source,aux,dest);
                cout<<"\n Move from "<<source<<" to "<<dest<<"\n";
                tower(num-1,aux,dest,source);
        }
}
int main(){
        int num;
        string a = "A";
        string b = "B";
        string c = "C";
        cout<<"\n Enter no. of disks: ";
        cin>>num;
        int moves = pow(2,num) - 1;
        cout<<"\n Number of moves are: "<<moves;
        cout<<"\n Moves are: ";
        tower(num,a,c,b);
        cout<<"\n";
}
~                                                                                                                                                                                                                                            ~                          