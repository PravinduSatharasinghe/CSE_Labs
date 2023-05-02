#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int largest = root; // Initialize largest as current root
    int left = 2 * root + 1; // left child of root
    int right = 2 * root + 2; // right child of root

    // If left child is larger than current root
    if (left < n && arr[left] > arr[largest]) 
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) 
    {
        largest = right;
    }

    // If largest is not root
    if (largest != root) 
    {
        // swap arr[root] with arr[largest]
        swap(arr[root], arr[largest]);

        // recursive part
        heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--) 
   {
      heapify(arr, n, i);
   }
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) 
   {
      // move current root to end
      swap(arr[0], arr[i]);

      // call max heapify on the reduced heap
      heapify(arr, i, 0);
   }
}


/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   /*int heap_arr[] = {4,17,3,12,9,6};*/
   const int MAX_SIZE = 10;
   int heap_arr[MAX_SIZE];

    srand(time(NULL)); // Seed the random number generator

    // Fill the array with random integers between 1 and 100
    for (int i = 0; i < MAX_SIZE; i++) {
        heap_arr[i] = rand() % 100 + 1;
    }
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}