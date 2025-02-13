/*          
            Aim : Implementation Of Quick Sort.

            Theory : 
            1) Consider 1st element of the list as pivot
            2) Define two variables 'i' and 'j' 
            set 'i' and 'j' to first and last elements of list respectively
            3) Increment 'i' until list[i]>pivot then stop
            4) Decrement 'j' until list[j]<pivot then stop
            5) if i<j swap list[i] and list[j]
            6) repeat steps 3,4,5 until i>j
            7) Exchange the pivot element  with list[j] element.
*/ 

#include <stdio.h>
void input(int arr[], int n);
void quicksort(int arr[], int i, int j);
int partition(int arr[], int i, int j);
void swap(int arr[], int i, int j);

void input(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the element for index %d : ", i);
        scanf("%d", &arr[i]);
    }
}

void quicksort(int arr[], int i, int j) {
    int p;
    if (i < j) {
        p = partition(arr, i, j);
        quicksort(arr, i, p - 1);
        quicksort(arr, p + 1, j);
    }
}

int partition(int arr[], int i, int j) {
    int pivot = arr[i];
    int I = i;
    int J = j;
    while (I < J) {
        while (arr[I] <= pivot && I < j) {  // Move right pointer
            I++;
        }
        while (arr[J] > pivot && J > i) {  // Corrected: Changed `>=` to `>` to prevent unnecessary swaps
            J--;
        }
        if (I < J) {
            swap(arr, I, J);
        }
    }
    swap(arr, i, J);
    return J;
}

void swap(int arr[], int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 
    input(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
Enter the number of elements: 7
Enter the element for index 0 : 4
Enter the element for index 1 : 7
Enter the element for index 2 : 2
Enter the element for index 3 : 8
Enter the element for index 4 : 1
Enter the element for index 5 : 4
Enter the element for index 6 : 3
Sorted array: 1 2 3 4 4 7 8 
*/

/*
Time Complexity :
            Best Case : O(nlogn)
            Average Case : O(nlogn)
            Worst Case : O(n^2)
*/


/*
Conclusion : Successfully understand and Implemented Quick Sort
*/
