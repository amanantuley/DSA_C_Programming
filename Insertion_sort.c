/*          Name : Antuley Aman Siraj
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : Implementation Of Insertion Sort.
*/ 

#include <stdio.h>

void inputArray(int *a, int n) {
    for (int k = 0; k < n; k++) {
        printf("Element %d:: ", k + 1);
        scanf("%d", &a[k]);
    }
}

void printArray(int a[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);  // Added space for better formatting
    }
    printf("\n");
}

void insertionSort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
        printf("\nPass %d :: ", i);  // Fixed incorrect pass number
        printArray(a, n);  // Used printArray function for better output
    }
}

int main() {
    int n;

    printf("Enter the Number of Elements: ");
    scanf("%d", &n);  // Removed the unnecessary newline

    int a[n];

    // Input Array Function is called
    inputArray(a, n);

    // Printing the Unsorted Array
    printf("Unsorted Array is:\n");
    printArray(a, n);

    // Insertion Sort Array is Called
    insertionSort(a, n);

    printf("\nSorted Array is:\n");
    printArray(a, n);

    return 0;
}

/*
Time Complexity:
- Best Case: O(n) (when the array is already sorted)  
- Average and Worst Case: O(n²) (when the array is in reverse order)
*/

/*
Conclusion:
Insertion Sort is a simple comparison-based sorting algorithm that builds the sorted array one element at a time.
*/