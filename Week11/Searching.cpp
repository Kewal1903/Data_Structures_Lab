#include <iostream>
using namespace std;

class Searcher {
private:
    int* arr; // Array to be searched
    int size; // Size of the array

public:
    // Constructor to initialize array and size
    Searcher(int arr[], int size) : arr(arr), size(size) {}

    // Function to perform linear search
    void linearSearch(int find) {
        int foundIndex = -1; // Initialize foundIndex to -1 (indicates not found)

        // Loop through each element in the array
        for (int i = 0; i < size; i++) {
            if (arr[i] == find) {
                foundIndex = i;
                break; // Element found, exit loop
            }
        }

        // Output result based on foundIndex
        if (foundIndex != -1)
            cout << "Found at: " << foundIndex << endl;
        else
            cout << "Not found" << endl;
    }

    // Function to perform binary search
    void binarySearch(int find) {
        int low = 0, high = size - 1;
        bool found = false; // Flag to indicate if element is found

        // Binary search algorithm
        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == find) {
                cout << "Found at: " << mid << endl;
                found = true;
                break;
            }
            else if (arr[mid] > find)
                high = mid - 1; // Move to the left half
            else
                low = mid + 1;  // Move to the right half
        }

        // If element was not found in the array
        if (!found)
            cout << "Not found" << endl;
    }
};

int main() {
    int arr[5];
    cout << "Input array of 5 elements: (sorted elements if Binary search)" << endl;
    
    // Take array input from the user
    for (int i = 0; i < 5; i++) {
        cout << "Input element " << i + 1 << ": ";
        cin >> arr[i];
    }

    Searcher searcher(arr, 5); // Create Searcher object with array and size

    int ch, find;
    cout << "1. LINEAR SEARCH 2. BINARY SEARCH\nENTER CHOICE: ";
    cin >> ch;

    cout << "Enter element to be found: ";
    cin >> find;

    // Perform search based on user choice
    if (ch == 1)
        searcher.linearSearch(find);
    else if (ch == 2)
        searcher.binarySearch(find);

    return 0;
}
