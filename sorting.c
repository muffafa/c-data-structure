#include <stdio.h>
#include <stdlib.h>

int const ARRAY[5] = {3,1,5,4,2};
int const SIZE = sizeof(ARRAY)/sizeof(ARRAY[0]);

void printSection(){
printf("--------------------\n");
}

void printSorting(){
printf("array is sorting:\n");
}

void resetArr(int arr[], int n){
    printf("array reseting...\n");
    int i;
    for(i = 0; i<n; i++)
        arr[i] = ARRAY[i];

}

void printArr(int arr[], int n){
    int i;
    printSection();
    printf("array is:\n");
    for(i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
    printSection();
}

void resetPrint(int arr[], int n){
    resetArr(arr, n);
    printArr(arr , n);
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}
void selectionSort(int arr[], int n){
    printSorting();
    printf("selection sort\n");
    for(int i = 0; i<n; i++){
        int min_idx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
              min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
    printArr(arr, n);
}

void insertionSort(int arr[], int n){
    printSorting();
    printf("insertion sort\n");
    int i,j, key;
    for(i = 1; i<n; i++){
        key = arr[i];
        for(j = i-1; j >=0 && key < arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
     printArr(arr, n);
}

void bubleSort(int arr[], int n){
    printSorting();
    printf("buble sort\n");
    int i, j;
    for(i = 0; i<n-1 ;i ++){
        for(j = 0;j < n -1 - i; j ++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printArr(arr, n);
}

void mergeSort(int arr[], int n){
    printSorting();
    printf("merge sort\n");
    mergeSortDvide(arr,0, n);
    printArr(arr, n);
}

void merge(int arr[],int left,int k,int right){
    int i, j, l = 0;
    int array[SIZE];

    i = left;
    j = k+1;

    while(i<=k && j<=right){
        if(arr[i]<= arr[j]){
            array[l] = arr[i];
            i++;
        }else{
            array[l] = arr[j];
            j++;
        }
        l++;
    }

    while(i<=k){
        array[l] = arr[i];
        i++;
        l++;
    }

    while(j<=right){
        array[l] = arr[j];
        j++;
        l++;
    }

    for (i = left, l = 0; i <= right; i++, l++)
      arr[i] = array[l];

}

void mergeSortDvide(int arr[], int left, int right){
    int k;
    if(left < right){
        k = (left + right)/2;
        mergeSortDvide(arr, left, k);
        mergeSortDvide(arr, k+1, right);

        merge(arr, left, k, right);
    }
}

void quickSort(int arr[], int n){
    printSorting();
    printf("quick sort\n");
    quickSortDvide(arr,0, n);
    printArr(arr, n);
}

void quickSortDvide(int arr[], int left, int right){
    int i, j, k, temp;

    //partition the array into two parts
   i = left;
   j = right;

   k = arr[(left+right)/2];   //pivot

    do{
    while ((arr[i] < k) && (i < right))
        i++;
    while ((arr[j] > k) && (j > left))
        j--;
    if (i <= j) { //exchange arr[i] & arr[j]
        swap(&arr[i], &arr[j]);
        i++;
        j--;
      }
   }while(i <= j);

    // Sort each part using quicksort
   if (left < j)
      quickSortDvide(arr, left, j);
   if (i < right)
      quickSortDvide(arr, i, right);
 }

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    printSorting();
    printf("heap sort\n");
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
    printArr(arr,n);
}

int main()
{
    int n = SIZE;
    int arr[n];
    printf("Size of array is: %d\n",n);
    resetPrint(arr, n);

    selectionSort(arr, n);
    resetPrint(arr, n);

    insertionSort(arr, n);
    resetPrint(arr, n);

    bubleSort(arr, n);
    resetPrint(arr, n);

    mergeSort(arr, n);
    resetPrint(arr, n);

    quickSort(arr, n);
    resetPrint(arr, n);

    heapSort(arr, n);

    return 0;
}


