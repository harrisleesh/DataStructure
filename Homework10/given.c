#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KEY_SIZE	20	
#define TABLE_SIZE	7	
#define equal(e1,e2) (!strcmp(e1.key,e2.key))

typedef struct				
{   
    char key[KEY_SIZE];	
} element;

struct list
{   
    element item;
    struct list *link;
};
struct list *hash_table[TABLE_SIZE];


int hash_function(char *key)
{
 //fill in the blank

	//first transfrom the key
	int value = transform(key);
	
	//square
	value = value*value;
	int meta = value;
	int temp = 0;
	int result = 0;
	int sum = 0;
	int n = 0;
	int address = 0;

	//find binary value
	for (int i = 1; value > 0; i *= 10)

	{

		temp = value % 2;

		sum = temp * i;

		result = result + sum;

		value /= 2;
		n++;
	}
	n /= 2;

	//find hash address
	for (int i = 0; i < n-2; i++) {
		meta /= 2;
	}
	address = (meta % 2);

	meta /= 2;
	address += (meta % 2) * 10;
	meta /= 2;
	address += (meta % 2) * 100;
	

	//return address
	return address;
	
}

void hash_chain_find(element item, struct list *ht[])
{
 //fill in the blank
	// node initate
	struct list *node;
	int i;
	int find = 0;

	// if key is valid
	// then print
	for (i = 0; i<TABLE_SIZE; i++) {
		for (node = ht[i]; node; node = node->link) {
			if (item.key == node->item.key) {
				printf("키를 찾았음(item.key: %s)\n", item.key);
				find = 1;
			}
		}
	}
	// if not
	// then print this
	if(find==0)
		printf("키를 찾지못했음(item.key: %s)\n", item.key);
}

void hash_chain_print(struct list *ht[])
{
   struct list *node;
   int i;
   for(i=0;i<TABLE_SIZE;i++){
      printf("[%d] ->", i);
      for(node=ht[i]; node; node=node->link){  
	     printf("%s->", node->item.key);
      }
      printf("\n");
   }
}

int transform(char *key)
{
	int number=0;
	while(*key) number += *(key++);
	return number;
}

void hash_chain_add(element item, struct list *ht[])
{
   int hash_value = hash_function(item.key);
   struct list *ptr; 
   struct list *node_before=NULL, *node = ht[hash_value];
   for(; node; node_before=node, node=node->link){  
	  if(equal(node->item, item)){ 
                printf("input err\n");
                return;
      }
   }

	ptr = (struct list *)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;

	if(node_before) node_before->link = ptr;
	else ht[hash_value]=ptr;
}

void main()
{
	FILE* f;
	element tmp;
	char input[KEY_SIZE]=" ";
	f=fopen("input.txt","r");
	while(fscanf(f, "%s", &input) != EOF){
		strcpy(tmp.key, input);
		hash_chain_add(tmp, hash_table);
	}
	hash_chain_print(hash_table);
	
	strcpy(tmp.key, "x");
	hash_chain_find(tmp, hash_table);
	strcpy(tmp.key, "c");
	hash_chain_find(tmp, hash_table);
}