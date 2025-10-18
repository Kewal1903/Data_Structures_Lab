#include<iostream>
using namespace std;
struct poly{
    int coeff,expo;
};
int main(){
    int n1,n2,i,j,n3=1;
    cout<<"\n Enter no. of terms in the first polynomial: ";
    cin>>n1;
    poly p1[n1];
    p1[0].coeff = n1;
    for(i=1;i<=n1;i++){
        cout<<"\n Enter coefficient: ";
        cin>>p1[i].coeff;
        if(p1[i].coeff == 0)
            continue;
        else{
            cout<<"\n Enter exponent of term: ";
            cin>>p1[i].expo;
        }
    }
    cout<<"\n Enter no. of terms in the second polynomial: ";
    cin>>n2;
    poly p2[n2];
    p2[0].coeff = n2;
    for(i=1;i<=n2;i++){
        cout<<"\n Enter coefficient: ";
        cin>>p2[i].coeff;
        if(p2[i].coeff == 0)
            continue;
        else{
            cout<<"\n Enter exponent of term: ";
            cin>>p2[i].expo;
        }
    }
    cout<<"\n Displaying polynomial 1: ";
    for(i=1;i<=n1;i++){
        if(p1[i].expo !=0)
            cout<<p1[i].coeff<<"*x^"<<p1[i].expo<<"+";
        else
            cout<<p1[i].coeff;
    }
    cout<<"\n";
    cout<<"\n Displaying polynomial 2: ";
    for(i=1;i<=n2;i++){
        if(p2[i].expo !=0)
            cout<<p2[i].coeff<<"*x^"<<p2[i].expo<<"+";
        else
            cout<<p2[i].coeff;
    }
    cout<<"\n";
    cout<<"\n Adding Polynomials: ";
    i=1,j=1;
    poly p3[100];
    while(i<=n1 && j<=n2){
        if(p1[i].expo > p2[j].expo){
            p3[n3].coeff = p1[i].coeff;
            p3[n3].expo = p1[i].expo;
            n3++;
            i++;
        }
        else if(p1[i].expo == p2[j].expo){
            if(p1[i].coeff + p2[i].coeff !=0){
                p3[n3].coeff = p1[i].coeff + p2[j].coeff;
                p3[n3].expo = p2[j].expo;
                n3++;
                i++;
                j++;
            }
            else
                continue;}
        else{
            p3[n3].coeff = p2[j].coeff;
            p3[n3].expo = p2[j].expo;
            n3++;
            j++;
        }
    }
    p3[0].coeff = n3;
    for(i=1;i<n3;i++){
        if(p3[i].expo != 0)
            cout<<p3[i].coeff<<"*x^"<<p3[i].expo<<"+";
        else
            cout<<p3[i].coeff;
    }
    return 0;
}

