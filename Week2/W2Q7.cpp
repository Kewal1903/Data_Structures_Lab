#include<iostream>
using namespace std;
void reconstructSparseMatrix(int values[],int rowIndices[],int colIndices[], int m, int n, int nonZero, int matrix[][100]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrix[i][j] = 0;
        }
    }
    for(int i=0;i<nonZero;i++){
        int value = values[i];
        int row = rowIndices[i];
        int col = colIndices[i];
        matrix[row][col] = value;
    }
}
int main(){
    int m,n,nonZero;
    cout<<"\n Enter no. of rows and columns: ";
    cin>>m>>n;
    cout<<"\n Enter no. of non zero elements: ";
    cin>>nonZero;
    int values[nonZero];
    int rowIndices[nonZero];
    int colIndices[nonZero];
    cout<<"\n Enter non zero elements, their row indices and column indices: ";
    for(int i = 0;i<nonZero;i++){
        cout<<"\n Element"<<i+1<<": value, row index, column index: ";
        cin>>values[i]>>rowIndices[i]>>colIndices[i];
    }
    int matrix[m][100];
    reconstructSparseMatrix(values,rowIndices,colIndices,m,n,nonZero,matrix);
    cout<<"\n Reconstructed matrix: \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}