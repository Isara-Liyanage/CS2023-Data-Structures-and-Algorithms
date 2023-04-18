#include <iostream>
#include <chrono>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    int L[left_size], R[right_size];
    
    for (int i = 0; i < left_size; i++) {
        L[i] = arr[left + i];
    }
    
    for (int i = 0; i < right_size; i++) {
        R[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < left_size) {
        arr[k++] = L[i++];
    }
    
    while (j < right_size) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int n) {
    int curr_size;
    int left_start;
    
    for (curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right);
        }
    }
}

int main() {
    //int arr[] = {5, 3, 1, 4, 2};
    int input_arr[] = {100,1000,2500,5000,10000};
    for (int count : input_arr){
    int arr[count];
        for(int i=0;i<count;i++){
            arr[count-1] = i;
        }
    int duration0;

    //int size = sizeof(arr) / sizeof(arr[0]);
    int size = count;
   // cout << "Original array: ";
    //for (int i = 0; i < size; i++) {
     //   cout << arr[i] << " ";
    //}
    //cout << endl;
    for(int j=0;j<5;j++){
    auto t_start = chrono::high_resolution_clock::now();
    
    mergeSort(arr, size - 1);

    auto t_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t_end - t_start).count();
    duration0 = duration0 + duration;

    }
    cout << "Size of array - " << size <<"\n";
    cout << "Time taken (Avg) - " <<(duration0/5) <<"\n";
    
    //cout << "Sorted array: ";
    //for (int i = 0; i < size; i++) {
     //   cout << arr[i] << " ";
    //}
    //cout << endl;
    }
    return 0;
}