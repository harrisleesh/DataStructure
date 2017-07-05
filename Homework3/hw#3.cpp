//for visual studio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void init(QueueType *q);
void error(char *message);
int is_empty(QueueType *q);
int is_full(QueueType *q);
void enqueue(QueueType *q, element item);
element dequeue(QueueType *q);
element peek(QueueType *q);

int main(int argc, char *argv[])
{

	//file pointer
	FILE *fp = fopen(argv[1], "rt");
	QueueType *que = (QueueType*)malloc(sizeof(QueueType));
	init(que);


	//read file until end of file
	while (!feof(fp)) {
		char a;
		element b;
		fscanf(fp, "%c", &a);


		//switch statement
		switch (a) {
		case 'e': // if e then enqueue
			fscanf(fp, "%d", &b);
			enqueue(que, b);
			break;
		case 'd': // if d then dequeue
			dequeue(que);
			break;
		case 'p': // if p then print top
			if (is_empty(que))
				printf("Queue is empty\n");
			else
				peek(que);
			break;
		}
		
	}



	fclose(fp);



	return 0;
}

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


void init(QueueType *q)
{
	// init as 0 and print init	
	q->front = 0;
	q->rear = 0;
	printf("init front = %d, rear = %d\n", q->front, q->rear);
}

int is_empty(QueueType *q)
{
	// if the front number and rear number is same, it is empty
	if (q->front >= q->rear)
		return true;
	else
		return false;
}

int is_full(QueueType *q)
{
	// if rear number +1 is equal to max size, it is full
	if (q->rear + 1 == MAX_QUEUE_SIZE)
		return true;
	else
		return false;
}

void enqueue(QueueType *q, element item)
{
	// if it is not full, it coud enqueue
	if (is_full(q))
		printf("Queue is full\n");
	else {
		// the rear number is +1 and the item is pushed
		q->rear++;
		q->queue[q->rear] = item;
		printf("enqueue() = %d\n", item);
		printf("front = %d, rear = %d\n", q->front, q->rear);
		
	}
}

element dequeue(QueueType *q)
{
	// if it is not empty, it could dequeue
	if (is_empty(q))
		printf("Queue is empty\n");
	else {
		//queue remove the first item, so front number is +1
		q->front++;
		printf("dequeue() = %d\n", q->queue[q->front]);
		printf("front = %d, rear = %d\n", q->front, q->rear);
		return q->queue[q->front];
		
	}
}

element peek(QueueType *q)
{
	
	//find first item in queue
	printf("%d\n", q->queue[q->front + 1]);
	return q->queue[q->front + 1];
	
}