#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) {t=x; x=y; y=t;}
#define MAX_SIZE 10
#define NAME_SIZE 32

//adjust �Լ��� ������ �����ð��� �ٷ���� ������ �˷α������� �����Ǿ� ����
void adjust(int heap[], int root, int n)
{  

}

void heap_sort(int list[], int n)
{  

	//fill in the balnk

}


void main()
{  
   FILE *f;
   int i;
   int list1[MAX_SIZE]; 
   f= fopen("input2.txt","r");
   fscanf(f,"%d %d %d %d %d %d %d %d %d %d",
	   &list1[0],&list1[1],&list1[2],&list1[3],&list1[4],
	   &list1[5],&list1[6],&list1[7],&list1[8],&list1[9]);
   //������
   heap_sort(list2, MAX_SIZE); /* �������� ȣ�� */
   printf("heap_sort: \n");
   for(i=1; i<=MAX_SIZE; i++) //printf("%d \t", );

}