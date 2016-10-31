// program showing insertion sort

#include <stdio.h>
#include <stdlib.h>

long insertsort(long A[], long size);
void printArray(long A[], long size);

int main(void){

	long compares;
	long size;
	long A[] = {3,1,5,4,2};
	size = sizeof(A) / sizeof(A[0]);
	printf("Array before sorting:\n");
	printArray(A, size);
	compares = insertsort(A, size);
	printf("Array after sorting is:\n");
	printArray(A, size);	
	printf("took %ld steps\n", compares);
	return 0;
}

long insertsort(long A[], long size){

	long i, j, temp;//iterators

	long counter = 0;

	for(i = 1; i < size; i++){ //from 1 to size of array
      temp = A[i];//hold current value
      j = i-1;//set previous value

      while( (temp < A[j]) && (j >= 0) ){ //if previous value less than current and at 2 or more elements
      	A[j + 1] = A[j]; 
        j = j - 1;

        counter++;
      }
      	A[j + 1]=temp;
  	}

  	return counter;
}

void printArray(long A[], long size){
	long i;
	for(i = 0; i < size; i++){
		printf("%ld ", A[i] );
	}
	printf("\n");
	return;
}