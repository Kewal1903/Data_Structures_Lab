#include<iostream>
using namespace std;
class TriDiagMatrix{
    int dm[100][100];
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
                if(i==j || (i-j) == 1 || (j-i) == 1){
                    cout<<"\n Enter matrix element: ";
                    cin>>tm[i][j];
                }
                else
                    tm[i][j] = 0;
            }
        }
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(tm[i][j] !=0){
                    arr[k] = tm[i][j];
                    k++;}
                else
                    continue;
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
            cout<<"\n Index of element is "<<(2*(row-1)+(col-1));
            cout<<"\n The element is: "<<tm[row-1][col-1];
        }
        else
            cout<<"\n The element is not in the array.";
        }
};

int main(){
    TriDiagMatrix td1;
    td1.input();
    return 0;
}