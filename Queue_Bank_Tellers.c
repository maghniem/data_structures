//Malek Maghnie

/*This program implements a circular array with the following operations:
enqueue, dequeue, front, size, isEmpty, and isFull. 
The program checks when the queue is full in the enqueue operation
and when the queue is empty in the dequeue operation.*/

/*This program implements a queue to simulate a bank with 3 tellers and one line. The time between arrival of
customers is a random integer between 1 and 5. When a customer arrives, the customer gets in line. When any of
the three tellers is available, the first customer in line goes to that teller. The time to process that customer’s
transaction is another random integer between 1 and 5. When the transaction is completed, the customer leaves.

The simulation is done for 100 customer and  the average time the customer waits in the queue is reported.*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define MAX_ITEMS 250 //max array size
#define MAX 5 //max range
#define MIN 1 //min range

//queue structure defined 
typedef struct circularQueue_s
{
	int front;
	int back; //will enqueue at back
	int size;
	int data[MAX_ITEMS]; //array to be used holding MAX_ITEMS definition
}circularQueue_t;

void initializeQueue(circularQueue_t *theQueue);
int isEmpty(circularQueue_t *theQueue);
int isFull(circularQueue_t *theQueue);
int Enqueue(circularQueue_t *theQueue, int theItemValue);
int Dequeue(circularQueue_t *theQueue, int *theItemValue);
void printQueue(circularQueue_t *theQueue);

unsigned int waitTime(void);
 

int main(void)
{

	int customersDequeued = 100; //iterator for people dequeued
	int i;
	int popped; //catch variable for dequeued value
	int time1, time2, time3; //time duration variable for each teller
	int enQtime; //time duration for new customer showing up
	int totalWait = 0; //total seconds of queue operation


	//set tellers with value between 1 to 5 to simulate service time
	time1 = waitTime();
	time2 = waitTime();
	time3 = waitTime();

	

	circularQueue_t   myQueue; //define queue
	initializeQueue(&myQueue);	 //init with 0 values

	
	for (i = 0; i < 3; ++i)
	{
		Enqueue(&myQueue, 1); //fill 3 spots in the queue that will be at the 3 tellers
	}

	enQtime = waitTime(); // set between 1 to 5 for when next customer shows up
	
	while(customersDequeued > 0){
		if (enQtime == 0) { 	//when enQtime hits 0, Enqueue new customer
			Enqueue(&myQueue, 1);
			enQtime = waitTime();	//then set when next one will show up		
		}

		if (time1 == 0 && (isEmpty(&myQueue) == 0)) {  //when teller1 is finished (hits 0) and there was someone in line being serviced, dequeue them
			Dequeue(&myQueue, &popped);
			customersDequeued--; //count it as 1 customer being served and decrement 
			time1 = waitTime(); //set amount of time new customer will spend at this teller
		}
		if (time2 == 0 && (isEmpty(&myQueue) == 0)) {
			Dequeue(&myQueue, &popped);		//repeat above for teller2
			customersDequeued--;
			time2 = waitTime();
		}
		if (time3 == 0 && (isEmpty(&myQueue) == 0)) {
			Dequeue(&myQueue, &popped);	//repeat above for teller3 
			customersDequeued--;
			time3 = waitTime();
		}
		if (time1 > 0) { //if at this point teller service time is still 0, meaning line was empty and never executed waitTime()
			--time1;		//do not decrement service time
		}
		if (time2 > 0) {
			--time2;
		}
		if (time3 > 0) {
			--time3;
		}
		--enQtime; //always decrement time for next customer to show up after setting above
		
		totalWait++; //count how many iterations total it takes to dequeue 100 times (customers), will represent total seconds 
	}					//per 100 customers 

	printf("%d\n", totalWait);
	

	return 0;
}

void initializeQueue(circularQueue_t *theQueue)
{
	int i;

	theQueue->size = 0;
	theQueue->front = 0;
	theQueue->back = 0;

	for (i = 0; i<MAX_ITEMS; i++)
	{
		theQueue->data[i] = 0; //set array to {0}
	}

	return;
}

int isEmpty(circularQueue_t *theQueue)
{
	if (theQueue->size == 0) 
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int isFull(circularQueue_t *theQueue)
{
	if (theQueue->size >= MAX_ITEMS)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int Enqueue(circularQueue_t *theQueue, int theItemValue)
{
	if (isFull(theQueue))
	{
		printf("The queue is full\n");
		printf("You cannot add items\n");
		return(-1);
	}
	else
	{
		theQueue->size++;
		theQueue->data[theQueue->back] = theItemValue;//enqueue at back
		theQueue->back = (theQueue->back + 1) % MAX_ITEMS; //set back 1 space away
	}
}

int Dequeue(circularQueue_t *theQueue, int *theItemValue)
{
	if (isEmpty(theQueue))
	{
		printf("isempty\n");

		return(-1);
	}
	else
	{
		*theItemValue = theQueue->data[theQueue->front];   // deqeue at front
		theQueue->front = (theQueue->front + 1) % MAX_ITEMS; //set front 1 space ahead
		theQueue->size--;

		return(0);
	}
}

void printQueue(circularQueue_t *theQueue)
{
	int frontPos, backPos;
	frontPos = theQueue->front;
	backPos = theQueue->size;
	while (backPos > 0)
	{
		
		printf(" %d ", theQueue->data[frontPos]);
		frontPos = (frontPos + 1) % MAX_ITEMS;
		backPos--;
		

	}
	printf("\n");

	return;

}

 unsigned int waitTime(void)
{
	srand(time(NULL));
	return (MIN + rand() % ((MAX - MIN) + 1));
}