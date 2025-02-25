
/*          Name : Antuley Aman Siraj.
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : Implementation Of Fractional Knapsack.

            Theory : The Fractional Knapsack Problem is a Greedy Algorithm used to maximize profit by selecting items based on their value-to-weight ratio. Unlike the 0/1 Knapsack Problem, where an item can either be taken fully or left, in the Fractional Knapsack Problem, we can take fractions of items.
            We first sort the items based on their profit-to-weight ratio in descending order and then pick items until the knapsack is full.


            Algorithm : 
            1) Input: Number of items, their weights, profits, and knapsack capacity.
            2) Compute the profit-to-weight ratio for each item.
            3) Sort the items in descending order of their profit-to-weight ratio.
            4) Pick items one by one:
                If the item fits completely, add its full profit.
                Otherwise, take the fraction that fits and add the corresponding fraction of profit.
            5) Output the maximum profit.
           

        
*/ 


#include <stdio.h>

void sortItems(int n, int weight[], int profit[], float ratio[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap weight
                int temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                // Swap profit
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                // Swap ratio
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;
            }
        }
    }
}

float knapsack(int n, int weight[], int profit[], int capacity) {
    float ratio[n], totalProfit = 0.0;
    
    // Calculate profit-to-weight ratio
    for (int i = 0; i < n; i++)
        ratio[i] = (float)profit[i] / weight[i];

    // Sort items by profit-to-weight ratio
    sortItems(n, weight, profit, ratio);

    // Pick items
    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {  // Take full item
            totalProfit += profit[i];
            capacity -= weight[i];
        } else {  // Take fraction
            totalProfit += ratio[i] * capacity;
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];
    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Maximum Profit: %.2f\n", knapsack(n, weight, profit, capacity));
    return 0;
}


/*
Time-Complexity :
Best Case: Ω(nlogn)
Worst Case: O(nlogn)
Average Case: Θ(nlogn)
*/

/*
Conclusion : The Fractional Knapsack Problem follows a greedy approach, selecting items based on their profit-to-weight ratio. It has a time complexity of O(n log n), ensuring an overall efficient solution. 
*/