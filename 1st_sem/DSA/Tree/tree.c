#include <stdio.h>
#include <stdlib.h>

struct structTree {
	int key;
	struct structTree * right;
	struct structTree * left;
}; typedef struct structTree tree;

tree * ROOT = NULL;

tree * insertnode (tree * root, int data){
	if(root == NULL){
		tree * newnode = (tree *)malloc(sizeof(tree));
		newnode->key = data;
		newnode->right = NULL;
		newnode->left = NULL;
		root = newnode;
	}else{
		if(root->key > data)
			root->left = insertnode(root->left, data);
		else
			root->right = insertnode(root->right, data);
	}

	return root;
}

tree * GetlowstInRightBranch(tree * root){
	if(root->left != NULL)
		return GetlowstInRightBranch(root->left);
	else
		return root;
}

tree * deletenode (tree * root, int data){
	if (root != NULL){
		if (root->key == data){
			if(root->left == NULL){
				tree * temp = root;
				root = root->right;
				free(temp);
			}else if (root->right == NULL){
				tree * temp = root;
				root = root->left;
				free(temp);
			}else{
				tree * lowstnode = GetlowstInRightBranch(root->right);
				root->key = lowstnode->key;
				root->right = deletenode(root->right,lowstnode->key);
			}

		}else{

			root->right = deletenode(root->right,data);
			root->left = deletenode(root->left,data);
			
		}
	}

	return root;
}

int InOrder(tree * root){
	if (root != NULL){
		InOrder(root->left);
		printf("%d ",root->key);
		InOrder(root->right);
	}
}

int main (){
	ROOT = insertnode(ROOT,15);
	insertnode(ROOT,10);
	insertnode(ROOT,20);
	insertnode(ROOT,9);
	insertnode(ROOT,11);
	insertnode(ROOT,12);
	insertnode(ROOT,24);
	insertnode(ROOT,17);
	insertnode(ROOT,16);
	insertnode(ROOT,25);
	insertnode(ROOT,24);
	insertnode(ROOT,26);

	InOrder(ROOT);

	deletenode(ROOT,24);

	InOrder(ROOT);



}
