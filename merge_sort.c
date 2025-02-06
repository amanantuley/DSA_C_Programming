/*          Name : Antuley Aman Siraj.
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : Implementation Of Binary Search.
*/ 

#include<stdio.h>

void input(int arr[] , int n){
    for (int i = 0 ; i < n ; i++){
        printf("Enter the %d Elements ::" , i+1);
        scanf("%d" , &arr[i]);
    }
}

void merge(int arr[], int lb, int mid, int ub){
    int i = lb;
    int j = mid +1;
    int k = lb;
    int b[ub + 1];

    while(i <= mid && j <=  ub){
        if(arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= ub){
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while (i <= mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k = lb ; k <= ub ; k++){
        arr[k] = b[k];
    }
}

void merge_sort(int arr[], int lb, int ub){
    if(lb < ub){
        int mid = (lb + ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    input(arr, n);
    merge_sort(arr, 0, n - 1);
    printArray(arr, n);
    
    return 0;
}









/*
Time-Complexity :
Best Case: O(n log n)
Worst Case: O(n log n)
Average Case: O(n log n)
*/

/*
Conclusion :Merge Sort is a divide-and-conquer algorithm with a time complexity of O(n log n) in all cases, making it more efficient than algorithms like Bubble Sort or Insertion Sort for large datasets, though it requires extra space for the temporary arrays used in merging.
*/