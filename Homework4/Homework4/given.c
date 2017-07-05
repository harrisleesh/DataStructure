//for visual studio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef int element;
typedef struct _TreeNode
{
	element data;
	struct _TreeNode * left;
	struct _TreeNode * right;
} TreeNode;

TreeNode * createTreeNode(void)
{
	TreeNode * a = NULL;
	a->data = 0;
	a->left = NULL;
	a->right = NULL;
	return a;
}

void setData(TreeNode * node, element data)
{
	node->data = data;
}

element getData(TreeNode * node)
{
	return node->data;
}

void makeLeftSubTree(TreeNode * main, TreeNode * sub)
{
	main->left = sub;
}

void makeRightSubTree(TreeNode * main, TreeNode * sub)
{
	main->right = sub;
}

TreeNode * getLeftSubTree(TreeNode * node)
{
	return node->left;
}

TreeNode * getRightSubTree(TreeNode * node)
{
	return node->right;
}
void printInorder(TreeNode *root) {
	if (root->left != NULL)
		printInorder(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		printInorder(root->right);
		
}
void printPreorder(TreeNode *root){
	
	printf("%d ", root->data);
	if (root->left != NULL)
		printPreorder(root->left);
	else if (root->right != NULL)
		printPreorder(root->right);
}
void printPostorder(TreeNode *root){
	if (root->left != NULL)
		printPostorder(root->left);
	if (root->right != NULL)
		printPostorder(root->right);
	printf("%d ", root->data);
}
int main(void){
	FILE *input;
	input = fopen("input.txt", "r");
	char command;
	TreeNode * root = createTreeNode();
	setData(root, 54);
	TreeNode * B = createTreeNode();
	setData(B, 27);
	makeLeftSubTree(root, B);
	TreeNode * C = createTreeNode();
	setData(C, 87);
	makeRightSubTree(root, C);
	TreeNode * D = createTreeNode();
	setData(D, 13);
	makeLeftSubTree( B,D);
	TreeNode * E = createTreeNode();
	setData(E, 44);
	makeRightSubTree(B, E);
	TreeNode * F = createTreeNode();
	setData(F, 71);
	makeLeftSubTree(C, F);
	TreeNode * G = createTreeNode();
	setData(G, 92);
	makeRightSubTree(C, G);
	TreeNode * H = createTreeNode();
	setData(H, 1);
	makeLeftSubTree(D, H);
	TreeNode * I = createTreeNode();
	setData(I, 37);
	makeLeftSubTree(E, I);
	TreeNode * J = createTreeNode();
	setData(J, 64);
	makeLeftSubTree(F, J);
	




	while (!feof(input)) {
		fscanf_s(input, "%c", &command);
		switch (command) {
		case 'i': printf("Inorder:   "); printInorder(root); printf("\n");
			break;
		case 'r': printf("Preorder:  "); printPreorder(root); printf("\n");
			break;
		case 'o': printf("Postorder: "); printPostorder(root); printf("\n");
			break;
		default:
			break;
		}
	}

	fclose(input);
    return 0;
}
