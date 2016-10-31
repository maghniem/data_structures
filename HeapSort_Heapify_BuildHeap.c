//Malek Maghnie

//program showcases Heapify algorithm and buildheap
//and heapsort

//will fill an array of size 500 with random integers
//and will build a heap and sort it

//outputs sorted array

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))



void swap ( int *x, int *y ){
    
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int i, int j)
{
    //i is the index of the element to heapify, 
    //j is the indext of the last element

    int k; 

    if (2*i +  2 <= j ){
        if(arr[2*i + 1] > arr[2*i + 2]){
            k = 2*i + 1;
        }
        if(arr[2*i + 1] <= arr[2*i + 2]){
            k = 2*i + 2;
        }
    }
    else if (2*i + 1 <= j){
        k = 2*i + 1;
    }
    else{
        return;
    }

    if( arr[i] < arr[k]){
        swap(&arr[i], &arr[k]);
    }

    heapify(arr, k, j);
}

void buildheap( int arr[], int size){

    int i;
    for(i = size/2 - 1; i >= 0; i-- ){
        heapify(arr, i, size-1);
    }
}

void printArr( int * A, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void heapsort( int arr[], int size){

    int i;
    buildheap(arr, size);
    for(i = size-1; i >= 1; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i-1);
    }    
}

void fillArr(int arr[], int size){
    time_t t;
    int i;
    srand((unsigned) time(&t));

    //buildheap(arr, size);
    for( i = 0; i < size; i++){
        arr[i] = rand() % size;
    }
}

int main(void){

    int A[500] = {0};    
    fillArr(A, 500);    
    heapsort(A, 500);

    printArr(A, 500);

    return 0;
}