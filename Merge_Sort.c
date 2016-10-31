//mergsort recursive algorithm

#include <stdio.h>
#include <stdlib.h>


void mergesort(long A[],long low, long mid, long high );
long divide(long A[], long low, long high);
void printArray(long A[], long size);


int main(void){

    long i, n;
    long size;
    long A[] = {8,6,1,7,3,2,9,4};
    long compares;

    size = sizeof(A) / sizeof(A[0]);
    printf("Array before sorting:\n");
    printArray(A, size);
    compares = divide( A, 0, size-1);
    printf("sorted array is:\n");
    printArray(A, size);
    printf("\nwith %ld steps\n", compares);
    return 0;
}

long divide(long A[], long low, long high){

    int mid; //midpoint or cut divide location

    static long counter = 0;
    
    
    
    if(low < high){ // if starting index < current index, 
                    //there are at least 2 elements left so split
        mid = (low + high) / 2; //mid is n/2
        divide(A, low, mid);
        divide(A, mid + 1, high);

        mergesort(A, low, mid, high);
        counter++;
    }

    

    return counter;

}

void mergesort( long A[], long low, long mid, long high){

    long i, m, k, l; //iterators
    long temp[high + 1]; //temp array 

    
    l = low; // save into over variables to iterate
    i = low;
    m = mid + 1; // left side 

    while( (l <= mid) && (m <= high) ){

        if( A[l] <= A[m]){
            temp[i] = A[l];
            l++;           
         }
        else{
            temp[i] = A[m];
            m++;         
        }
        i++;
    }
    if(l > mid){
        for(k = m;k <= high; k++){
            temp[i] = A[k];
            i++;
        }
    }
    else{
        for(k = l;k <= mid;k++){
            temp[i] = A[k];
            i++;
        }
    }   
    for(k = low; k <= high; k++){
        A[k] = temp[k];
    }

    return;
}

void printArray(long A[], long size){
	long i;
	for(i = 0; i < size; i++){
		printf("%ld ", A[i] );
	}
	printf("\n");
	return;
}
   