/*          Name : Antuley Aman Siraj
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : To implement naive string matching algorithm.

            Theory : The Naive String Matching algorithm is the simplest and most straight forward approach to find occurrences of a pattern within a text. It operates on the fundamental principle of brute-force comparison.


            Algorithm : 
            Iterate: Slide the pattern across the text, considering each possible starting position for the pattern within the text.
            Compare: At each starting position, compare the characters of the pattern with the corresponding characters in the text.
            Match: If all characters of the pattern match the current substring in the text, a match is found at the current starting position.
            Match: If any character mismatch occurs during the comparison, shift the pattern one position to the right in the text.
            Record: Store the starting indices where a full match of the pattern is found in the text.
            
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void naive_string(char input[] , char pattern[]){
    int n = strlen(input);
    int m = strlen(pattern);

    if(m > n){
        printf("Pattern Not Found");
        return ;
    }
    for(int i = 0 ; i <= n - m ; i++){
        int j;
        for ( j = 0; j < m; j++){
            if(input[i+j] != pattern[j]){
                break;
            }
        }
        if (j == m)
        {
            printf("Pattern Found at Index : %d\n" , i);
        }
        
    }


}


int main() {

   char input[20];
   char pattern[10];

    printf("Enter the String :");
    scanf("%s" , input);


    printf("Enter the Pattern :");
    scanf("%s" , pattern);

    naive_string(input , pattern);
    return 0;
}



/*
Time Complexity: 
Worst Case : O(m*n)
Best Case : O(n)
Average Case : O(m*n) 

*/

/*
Conclusion: Simple to implement but inefficient for large inputs, the Naive String Matching algorithm is often outperformed by more sophisticated methods.

*/