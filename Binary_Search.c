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

int binary_search(int arr[] ,int n , int key , int low , int high){
    // For Ascending Order
    if(arr[0] < arr[n-1]){
    if(low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(key == arr[mid]){
        return mid;
    }
    else if(key > arr[mid]){
        binary_search(arr,n,key,low+1,high);
    }
    else{
        binary_search(arr,n,key,low,mid-1);
    }
    }
    // For Descending order
    else{
    if(low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(key == arr[mid]){
        return mid;
    }
    else if(key < arr[mid]){
        binary_search(arr,n,key,low+1,high);
    }
    else{
        binary_search(arr,n,key,low,mid-1);
    }
    }


}


int main(){
    int n;
    printf("Enter the Number of Elements ::");
    scanf("%d" , &n);

    int arr[n];
    input(arr,n);
    int key;
    printf("Enter the Element to Search ::");
    scanf("%d" , &key);
    binary_search(arr,n,key,0,n-1);
    if(binary_search(arr,n,key,0,n-1) == -1){
        printf("Element Not Found.");
    }
    else{
        printf("Element Found at array index :%d" , binary_search(arr,n,key,0,n-1));
    }
}


 /*
Best Case: O(1) 
Worst Case: O(log n) 
Average Case: O(log n) 
*/

/*
Conclusion :Binary Search is an efficient search algorithm for sorted arrays, offering a logarithmic time complexity of O(log n), making it much faster than linear search, especially for large datasets.
*/