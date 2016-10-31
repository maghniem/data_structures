#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>

void choose_n(int [], int);
void distrib(int [], int *, int *);

//MCS improved algorithm 60-254
//O(n) run time

//Input: ask the user for the size of the sequence

//will then fill the array with random itegers and go throug
//finding the Maximum contiguous sequence

//output: iterations taken to calculate the MCS and display the sum and sequence

int main(void){

	int elements;
	int pos = 0, neg = 0;
	int arraySize;
	printf("Please specify the sequence size: ");
	scanf("%d", &arraySize);
	int numbers[arraySize];

	int i = arraySize-1;
	int start = -1, end = -1;
	int maxsum = 0, sum = 0, iterationCounter=0; 
	int j;

	//fill the array with random integers
	choose_n(numbers, arraySize);

	printf("Sequence is: \n");
	int n;
	for (n = 0; n < arraySize; n++) //go right to left 
	{
		printf("%d ", numbers[n]);
	}	
	printf("\n");
	for (j = arraySize-1; j >=0 ; j--)
	{
		sum += numbers[j];
		if (sum > maxsum)
		{
			maxsum = sum;
			start = i;
			end = j;
		}
		if (sum < 0)
		{
			i = j - 1;
			sum = 0;
		}
		iterationCounter++;
		printf("max sum: %d\titeration: %d\n", maxsum, iterationCounter);
	}
	printf("MCS is: ");
	for(i = end; i < (start - end + 1); i++){
		printf("%d ", numbers[i]);
	}
	printf("\n\nMCS is from element: %d to %d (0 indexed)\n MAX SUM: %d\nIterations: %d\n", end, start, maxsum, iterationCounter);
	
	return 0;
}
//fill an array of size n with random integers
void choose_n(int out[], int arraySize){
	int i;   
   /* Intializes random number generator */
   srand(time(NULL));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < arraySize ; i++ ) 
   {

      out[i] = rand()%10-arraySize/2;
    }	    
} 
