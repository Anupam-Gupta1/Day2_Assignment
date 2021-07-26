/**
 * Program to check Bubble_sort runtime analysis
 *
 * Compilation : gcc -o Bubble_sort Bubble_sort.c
 * Execution : ./Bubble_sort
 *
 * Anupam Gupta and 1910990303  27/07/21
 * Assignment -> Day2_Coding_Assignment
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* Function to generate Input
* type 1-> Random Numbers
* type 2-> Sorted Numbers in Ascending Order
* type 3-> Sorted Numbers in Descending Order
*/

void input_value(int arr[],int n,int type){
    
    if(type == 1) {
        
        // random -> rand()
        for(int i = 0; i < n; i++){
            arr[i] = rand() % n + 1;
        }
        
    }
    else if(type == 2) {
        
        for(int i = 0; i < n; i++){
            arr[i] = i;
        }
        
    }
    else if(type == 3) {
        
        for(int i = 0; i < n; i++){
            arr[i] = n-i-1;
        }
        
    }
    
    
}


// Function to Swap two numbers
void swap(int arr[],int i,int j){
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}

/*
* Bubble Sort Algorithm
* In Place and Stable
* Cache friendly -> Good 
*/

void bubble_sort(int arr[],int n){
    
    bool check = false;
    
    for(int i = 0; i < n-1; i++){
        
        check = false;
        
        for(int j = 0; j <= n-i-1; j++){
            
            // checking adjacent elements
            if(arr[j] > arr[j+1]){
                swap(arr,j,j+1);
                check = true;
            }
            
        }
        
        // if swapped remains false it means array is already sorted
        if(!check)
            break;
    }
    
}

/*
* Function to calculate_time for different type of input
* intial_size -> 8000
* increment -> 4000
*/

void calculate_time(int intial_size,int increment,int type){
    struct timeval e;
    int i;
    
    for(i=0;i<8;i++){
        
        int size = intial_size + increment*i;
        int arr[size];
        
        // Calling Function for generating Input
        input_value(arr,size,type);
        
        gettimeofday(&e, NULL);
        
        // sec*1000 + microseconds/1000 == milliseconds 
        long long start_time = e.tv_sec * 1000LL + e.tv_usec / 1000;
        
        // Calling bubble_sort to sort array
        bubble_sort(arr,size);
        
        gettimeofday(&e, NULL);
        
        long long end_time = e.tv_sec * 1000LL + e.tv_usec / 1000;
        
        printf("\t %lld",end_time - start_time);
    }
    
}

int main()
{
    int intial_size = 8000;
    int increment = 4000;
    int type;
    scanf("%d", &type);
    
    printf("Time Taken");
    
    // type 1-> Random Numbers
    // type 2-> Sorted Numbers in Ascending Order 
    // type 3-> Sorted Numbers in Descending Order 
    calculate_time(intial_size,increment,type);
    
    return 0;
}
