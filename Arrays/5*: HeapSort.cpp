/**
* Problem link: https://www.geeksforgeeks.org/problems/heap-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
* Ref: https://www.youtube.com/watch?v=HqPJF2L5h9U
* Ref: https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
* SiftUp: Insert to a Heap. SiftDown: Delete form a Heap, Heapify, Heapsort
**/

class Solution
{
    vector<int> heap;
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      while(i < n) {
          int leftIdx = i * 2 + 1;
          int rightIdx = i * 2 + 2;
          int val = arr[i];
          int idx = i;
          if(leftIdx < n && val < arr[leftIdx]) {
              val = arr[leftIdx];
              idx = leftIdx;
          }
          if(rightIdx < n && val < arr[rightIdx]) {
              val = arr[rightIdx];
              idx = rightIdx;
          }
          
          if(idx == i) break;
          int temp = arr[i];
          arr[i] = val;
          arr[idx] = temp;
          i = idx;
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        heapSort(arr, n);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        for(int idx = (n - 1) / 2; idx >=0; idx--) {
            heapify(arr, n, idx);   
        }
        
        for(int idx = n - 1; idx >= 0; idx--) {
            int temp = arr[0];
            arr[0] = arr[idx];
            arr[idx] = temp;
            heapify(arr, idx, 0);
        }
    }
};
