//for visual studio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE ];
	int front, rear;
} QueueType;

void init(QueueType *q);
void error(char *message);
int is_empty(QueueType *q);
int is_full (QueueType *q);
void enqueue( QueueType *q, element item );
element dequeue(QueueType *q);
element peek(QueueType *q);

int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[0], "rt");

	QueueType *que = malloc(sizeof(QueueType));
	init(que);
	
	while (!feof(fp)) {
		char a;
		element b;
		fscanf("%c", a);

		switch(a)
			case 'e':
				fscanf("%d", b);
				enqueue(que, b);
				break;
			case 'd':
				dequeue(que);
				break;
			case 'p':
				peek(que);
				break;
	}



	fclose(fp);


	/* fill in the blank*/
	
    return 0;
}

void error(char *message)
{
        fprintf(stderr,"%s\n",message);
        exit(1);
}


void init(QueueType *q)
{
	 q->front =0;
	 q->rear = 0;
}

int is_empty(QueueType *q)
{
/* fill in the blank*/
	if (q->front > q->rear)
		return true;
	else
		return false;
}

int is_full (QueueType *q)
{
/* fill in the blank*/
	if (q->rear - q->front -1 == MAX_QUEUE_SIZE)
		return true;
	else
		return false;
}

void enqueue( QueueType *q, element item )
{
/* fill in the blank*/
	q->rear++;
	q->queue[q->rear] = item;

}

element dequeue(QueueType *q)
{
/* fill in the blank*/
	q->front++;
	return q->queue[q->front - 1];
}

element peek(QueueType *q)
{
/* fill in the blank*/
	return q->queue[q->front];
}