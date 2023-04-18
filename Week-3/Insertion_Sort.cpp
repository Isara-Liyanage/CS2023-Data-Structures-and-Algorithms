
#include <iostream>
#include <chrono>

void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int in[] = {1,3,5,7,15,20};
  for(int loop:in){
  int* arr = new int[loop];
  for (int i = 0; i < loop; ++i) {
    arr[i] = loop - i;
  }

  auto start_time = std::chrono::high_resolution_clock::now();

  insertion_sort(arr, loop);

  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();

    std::cout <<"total elements in array: " <<loop <<"\n";
  std::cout << "time taken is " << duration*1000000 << " micro seconds." << std::endl;

  delete[] arr;
  }
  return 0;
}