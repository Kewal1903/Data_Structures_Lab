#include<iostream>
using namespace std;
class Sorter{
    private:
    int* arr;
    int size;
    public:
    Sorter(int arr[], int size) : arr(arr), size(size){}
    void selectionSort(){
        int min;
        for(int i = 0; i < size - 1; i++){
            min = i;
            for(int j = i+1; j < size; j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    void bubbleSort(){
        bool sorted = false;
        for(int i = 0; i < size - 1 && !sorted; i++){
            sorted = true;
            for(int j = size - 1; j > i; j--){
                if(arr[j] < arr[j-1]){
                    sorted = false;
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
    }
    int partition(int low, int high) {
    int pivot = arr[high];  // Use the last element as pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;            // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Place pivot element at its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  // Return partition point
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);  // Partition the array

        quickSort(low, pi - 1);         // Sort left part
        quickSort(pi + 1, high);        // Sort right part
    }
}

    void insertionSort(){
        for(int i = 1; i < size; i++){
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    void display(){
        for(int  i = 0; i < size; i++){
            cout << arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int arr[5];
    cout<<"Input array of 5 elements: "<<endl;
    for(int i = 0; i < 5; i++){
        cout<<"Input element: "<< i+1<<":";
        cin>>arr[i];
    }
    Sorter sorter(arr, 5);
    int choice;
    cout<<"1. Selection Sort 2. Bubble Sort 3. Quick Sort 4. Insertion Sort \n Enter choice: ";
    cin>>choice;
    switch(choice){
        case 1:
        sorter.selectionSort();
        break;
        case 2:
        sorter.bubbleSort();
        break;
        case 3:
        sorter.quickSort(0,4);
        break;
        case 4:
        sorter.insertionSort();
        break;
        default:
        cout<<"Invalid choice"<<endl;
        return 0;
    }
    cout<<"Sorted array: ";
    sorter.display();
    return 0;
}