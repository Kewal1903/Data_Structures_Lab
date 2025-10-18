#include<iostream>
using namespace std;
class CMMatrix{
    int cm[100][100];
    int arr[10000];
    public:
    void input(){
        int rows,cols,i,j,k = 0;
        cout<<"\n Enter no. of rows: ";
        cin>>rows;
        cout<<"\n Enter no. of columns: ";
        cin>>cols;
        int tm[rows][cols];
        int size = rows*cols;
        int arr[size];
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                    cout<<"\n Enter matrix element: ";
                    cin>>tm[i][j];
        }}
        for(j=0;j<cols;j++){
            for(i=0;i<rows;i++){
                arr[k] = tm[i][j];
                k++;
            }
        }
        int new_size = k;
        cout<<"\n 2D Matrix: \n";
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                cout<<tm[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n 1D Array: ";
        for(i=0;i<new_size;i++)
            cout<<arr[i]<<" ";
        int row,col;
        cout<<"\n Enter row for retrieval element: ";
        cin>>row;
        cout<<"Enter column for retrieval element: ";
        cin>>col;
        if(row<=rows && col<=cols){
            cout<<"\n Index of element is "<<((col-1)*rows + (row-1));
            cout<<"\n The element is: "<<tm[row-1][col-1];
        }
        else
            cout<<"\n The element is not in the array.";
        }
};

int main(){
    CMMatrix cm1;
    cm1.input();
    return 0;
}