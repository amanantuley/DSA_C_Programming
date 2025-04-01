/*          Name : Antuley Aman Siraj.
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : Implementation Of Sum of Subset.

            Theory : The Sum of Subset problem is a classic combinatorial problem that involves finding subsets of a given set whose sum is equal to a specified target value. It is often solved using Backtracking or Dynamic Programming.

            Algorithm : 
                Sort the given set (optional but helps in pruning).

                Use recursion to explore all subsets by including or excluding each element.

                Check constraints (sum should not exceed S).

                Backtrack if adding an element exceeds S.

                Print the valid subset when the sum equals S.
           

        
*/ 

#include <stdio.h>

void sum_of_subset_backtracking(int arr[], int n, int target, int index, int current_sum, int subset[], int subset_size) {
    if (current_sum == target) {
        printf("Subset found: ");
        for (int i = 0; i < subset_size; i++) {
            printf("%d ", arr[subset[i]]);
        }
        printf("\n");
        return;
    }

    if (index >= n || current_sum > target) {
        return;
    }

    subset[subset_size] = index;
    sum_of_subset_backtracking(arr, n, target, index + 1, current_sum + arr[index], subset, subset_size + 1);

    sum_of_subset_backtracking(arr, n, target, index + 1, current_sum, subset, subset_size);
}

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int subset[n];
    sum_of_subset_backtracking(arr, n, target, 0, 0, subset, 0);

    return 0;
}
/*

OUTPUT :-
Enter the number of elements in the array: 5
Enter the elements of the array:
4
2
1
3
5
Enter the target sum: 5
Subset found: 4 1 
Subset found: 2 3 
Subset found: 5 

Time Complexity: 
Best Case : O(2^n)
Average Case : O(2^n)
Worst Case : O(2^n)

Conclusion : Successfully implemented sum of subset using backtracking.

*/
