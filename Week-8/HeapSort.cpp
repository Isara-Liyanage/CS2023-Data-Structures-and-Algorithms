#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root; // largest element is assumed to be root
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    // if left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    //if right child is larger than the root and the left child
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != root)
    {
        // swap root with largest element
        swap(arr[root], arr[largest]);
        
        // recursion call
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // extracting elements from heap and placing at the end
    for (int i = n-1; i > 0; i--)
    {

        swap(arr[0], arr[i]);
        
        // call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// print contents of array 
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
       cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int n;
   cout << "Enter the size of array: ";
   cin >> n;
   int heap_arr[n];
   cout << "Enter the elements of array: ";
   for (int i = 0; i < n; i++)
   {
       cin >> heap_arr[i];
   }
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   return 0;

}
