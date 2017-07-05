//for visual studio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;

void display(TreeNode *p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%d", p->key);
		display(p->right);
		printf(")");
	}
}

/*
We will implement binary search tree ADT with the three main functions
using iteration: insert, delete, and search. 
*/
TreeNode *search(TreeNode *node, int key)
{
	//if node is null, there is no key in the tree, so stop search
	if (node == NULL) {
		//printf("key is not in the tree: %d", key);
		return node;
	}

	//tree is sorted, if key is bigger than node's key, then search right sub tree.
	if (node->key == key) {
		return node;
		//printf("key is in the tree: %d", key);
	}
	else if (node->key < key) 
		search(node->right, key);
	else if (node->key > key)
		search(node->left, key);
}


void insert_node(TreeNode **root, int key)
{	
	
	if (*root == NULL) {
		//temp is inserted node
		TreeNode **temp = root;

		// initialize the node value and left, right child
		*temp = malloc(sizeof(TreeNode));
		(*temp)->key = key;

		TreeNode *left = malloc(sizeof(TreeNode));
		TreeNode *right = malloc(sizeof(TreeNode));
		left = NULL;
		right = NULL;
		(*temp)->left = left;
		(*temp)->right = right;
	}
	else if ((*root)->key < key)
		insert_node(&(*root)->right, key);		//find the location of new node
	else if ((*root)->key > key)
		insert_node(&(*root)->left,key);
	
}

void delete_node(TreeNode *node, int key)
{

	TreeNode **temp;
	temp = &node;
	while (1) {
		if ((*temp)->key == key) {
			//If the node to be deleted has both children, it is replaced with the smallest node in the right subtree.
			if ((*temp)->left != NULL && (*temp)->right != NULL) {
				while (1) {
					if ((*temp)->left != NULL)
						temp = &(*temp)->left;
					else {
						node->key = (*temp)->key;
						if ((*temp)->right == NULL)
							*temp = NULL;
						else
							temp = &(*temp)->right;
						break;
					}
				}
				return;
			}
			// replaced by left
			else if ((*temp)->left != NULL)
				(*temp) = (*temp)->left;
			// replaced by right
			else if ((*temp)->right != NULL)
				(temp) = (*temp)->right;
			else {
				
				*temp = NULL;
				
			}
			return;
		}
		else if ((*temp)->key < key)
			temp = &(*temp)->right;
		else if ((*temp)->key > key)
			temp = &((*temp)->left);
	}
}




void main(int argc, char *argv[])
{
	char command;
	int key;
	FILE *input;
	TreeNode *root = NULL;

	if (argc == 1) input = fopen("input.txt", "r");
	else input = fopen(argv[1], "r");
	while (1) {
		command = fgetc(input);
		if (feof(input)) break;
		switch (command) {
		case 'i':
			fscanf(input, "%d", &key);
			insert_node(&root, key);
			break;
		case 'd':
			fscanf(input, "%d", &key);
			delete_node(root, key);
			break;
		case 's':
			fscanf(input, "%d", &key);
			if (search(root, key) != NULL)printf("key is in the tree: %d\n", key);
			else printf("key is not in the tree: %d\n", key);
			break;
		case 'p':
			display(root);
            printf("\n");
			break;
		default:
			break;
		}
	}
}
