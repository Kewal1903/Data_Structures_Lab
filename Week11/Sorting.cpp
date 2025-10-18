#include<iostream>
using namespace std;

class Sorter{
    private:
    int* arr;
    int size;
    
    void heapify(int N, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if(l < N && arr[l] > arr[largest])
            largest = l;
        if(r < N && arr[r] > arr[largest])
            largest = r;
        
        if(largest != i){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(N, largest);
        }
    }
    void merge(int left, int mid, int right){
        int a1 = mid - left + 1;
        int a2 = right - mid;
        
        int* leftArray = new int[a1];
        int* rightArray = new int[a2];
        for(int i = 0; i < a1; i++)
            leftArray[i] = arr[left + i];
        for(int j = 0; j < a2; j++)
            rightArray[j] = arr[mid + 1 +j];
            
        int pos_a1 = 0, pos_a2 = 0;
        int merged = left;
        while(pos_a1 < a1 && pos_a2 < a2){
            if(leftArray[pos_a1] <= rightArray[pos_a2]){
                arr[merged] = leftArray[pos_a1];
                pos_a1++;
            } else {
                arr[merged] = rightArray[pos_a2];
                pos_a2++;
            }
            merged++;
        }
        while(pos_a2 < a2){
            arr[merged] = rightArray[pos_a2];
            pos_a2++;
            merged++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }
    
    void mergeSort(int begin, int end){
        if(begin >= end)
            return;
        int mid = begin + (end-begin)/2;
        mergeSort(begin,mid);
        mergeSort(mid+1, end);
        merge(begin, mid, end);
    }
    public:
    Sorter(int arr[], int size) : arr(arr),size(size){}
    void heapSort(){
        for(int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);
        for(int i = size - 1; i > 0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(i, 0);
        }
    }
    void mergeSort(){
        mergeSort(0, size - 1);
    }
    void display(){
        cout<<"Sorted array is: ";
        for(int i = 0; i < size; ++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main(){
    int arr[5];
    cout<<"Input array of 5 elements: "<<endl;
    for(int i = 0; i < 5; i++){
        cout<<"Input element"<<i+1<<":";
        cin>>arr[i];
    }
    Sorter sorter(arr,5);
    int ch;
    cout<<"1. HEAPSORT 2. MERGESORT \n ENTER CHOICE: ";
    cin>>ch;
    if(ch == 1)
        sorter.heapSort();
    else if(ch == 2)
        sorter.mergeSort();
    else
        cout<<"Invalid option.";
    sorter.display();
    return 0;
}
