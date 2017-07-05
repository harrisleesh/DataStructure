#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) {t=x; x=y; y=t;}
#define MAX_SIZE 10
#define NAME_SIZE 32

/* i is leftlist of index
   j is right index of list
   k is sorted index */
void merge(int list[], int left, int mid, int right)
{  
	// variables initiate
   int Lpos, Rpos, elements;
   int leftEnd = mid;
   int rightEnd = right;
   Lpos=left;  
   Rpos=mid+1; 
   elements = right - left + 1;
   int TmpArr[MAX_SIZE];
   int TmpPos = Lpos;

   // Merge in TmpArr
   while (Lpos <= leftEnd &&Rpos <= rightEnd) {
	   if (list[Lpos] <= list[Rpos])
		   TmpArr[TmpPos++] = list[Lpos++];
	   else
		   TmpArr[TmpPos++] = list[Rpos++];
   }
   //if there is remains, then push in Tmparr
   while (Lpos <= leftEnd)
	   TmpArr[TmpPos++] = list[Lpos++];
   while (Rpos <= rightEnd)
	   TmpArr[TmpPos++] = list[Rpos++];
   // move from Tmparr to list
   for (int i = 0; i < elements; i++, rightEnd--)
	   list[rightEnd] = TmpArr[rightEnd];

}

void merge_sort(int list[], int left, int right)
{  
   int mid;
   if(left<right){
      mid = (left+right)/2;     /* divide balanced list */
      merge_sort(list, left, mid);    /* left part list merge */
      merge_sort(list, mid+1, right); /* right part list merge  */
	  merge(list, left, mid, right);    /* merge exact */
   }
}

void main()
{  
   FILE *f;
   int i;
   int list1[MAX_SIZE]; 
   f= fopen("input1.txt","r");
   fscanf(f,"%d %d %d %d %d %d %d %d %d %d",
	   &list1[0],&list1[1],&list1[2],&list1[3],&list1[4],
	   &list1[5],&list1[6],&list1[7],&list1[8],&list1[9]);

   // merging sort
   merge_sort(list1, 0, MAX_SIZE-1); /* call merge sort */
   printf("merge_sort: \n");
   for(i=0; i<MAX_SIZE; i++) 
	   printf("%d \t", list1[i] );
   fclose(f);
}