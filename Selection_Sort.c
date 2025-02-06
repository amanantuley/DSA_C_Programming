/*          Name : Antuley Aman Siraj.
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : Implementation Of Selection Sort.
*/ 

#include<stdio.h>

void inputArray(int *a , int n){
    for(int k = 0 ; k < n ; k++)
    {
        printf("Element %d ::" , k + 1);
        scanf("%d" ,&a[k]);
    }
}

void printArray(int a[] , int n){
    for(int k = 0 ; k < n ; k++)
    {
        printf("%d" , a[k]);
    }
} 

void selectionSort(int *a, int n){
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int min = i;
        for(int j = i + 1 ; j < n ; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }

        printf("\nPass %d :: ", i + 1);
        for(int j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }

    }
}

int main() {

    int n;

    printf("Enter The Number of Elements :: ");
    scanf("%d", &n);

    int a[n];

    inputArray(a, n);

    printf("\nUnsorted Array Is :: \n");
    printArray(a, n);

    printf("\n");

    selectionSort(a, n);

    printf("\n\nSorted Array Is :: \n");
    printArray(a, n);

    printf("\n");

    return 0;
}


/* Time complexity : O(n)
    Best Case : O(n^2)
    Worst case : O(n^2)
    Average case : O(n^2)

*/

/*
Enter The Number of Elements :: 8
Element 1 ::9
Element 2 ::7
Element 3 ::1
Element 4 ::0
Element 5 ::6
Element 6 ::9
Element 7 ::3
Element 8 ::2

Unsorted Array Is :: 
97106932

Pass 1 :: 0 7 1 9 6 9 3 2 
Pass 2 :: 0 1 7 9 6 9 3 2 
Pass 3 :: 0 1 2 9 6 9 3 7 
Pass 4 :: 0 1 2 3 6 9 9 7 
Pass 5 :: 0 1 2 3 6 9 9 7
Pass 6 :: 0 1 2 3 6 7 9 9
Pass 7 :: 0 1 2 3 6 7 9 9

Sorted Array Is ::
01236799

*/

/*
Conclusion :
Selection Sort efficiently selects the minimum element and places it in its correct position, but has a relatively high time complexity of O(n²) in all cases.
*/