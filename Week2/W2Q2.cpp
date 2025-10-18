#include<iostream>
using namespace std;
class LTMatrix{
    int ltm[100][100];
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
        for(j=0;j<cols;j++){
            for(i=0;i<rows;i++){
                if(j>=i){
                    cout<<"\n Enter matrix element: ";
                    cin>>tm[i][j];
                }
                else
                    tm[i][j] = 0;
            }
        }
        for(j=0;j<cols;j++){
            for(i=0;i<rows;i++){
                if(tm[i][j] !=0){
                    arr[k] = tm[i][j];
                    k++;}
                else
                    continue;
            }
        }
        int new_size = k;
        cout<<"\n 2D Matrix: \n";
        for(j=0;j<cols;j++){
            for(i=0;i<rows;i++){
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
        cout<<"\n Enter column for retrieval element: ";
        cin>>col;
        if(row>=col && row<=rows && col<=cols){
            cout<<"\n Index of element is "<<(((row-1)*row)/2)+(col-1);
            cout<<"\n The element is: "<<tm[row-1][col-1];
        }
        else
            cout<<"\n The element is not in the array.";
        }
};

int main(){
    LTMatrix l1;
    l1.input();
    return 0;
}