//Binary tree Using array
//Binary tree construction from array
//tree traversals

//Draw Tree using coordinate based approach


#include <stdio.h>
#include <stdlib.h>


int x, y, counter = 0;

typedef struct node
{
	struct node* left;  //pointer to left subtree
	struct node* right; //pointer to right subtree
	char data; // cell holding the contents of the nodes
	
}node;

//takes in an array form binary tree
//returns a pointer to the first node
//of a tree created from the array with all
//values inserted into the proper position
node* insert(char c[],int n)
{
	node*tree=NULL;
 	if(c[n]!='\0')
 	{
	  tree=(node*)malloc(sizeof(node));
	  tree->left=insert(c,2*n+1);
	  tree->data=c[n];
	  tree->right=insert(c,2*n+2);
 	}
 	return tree;
}

int height_recursive(node*tree)
{
    int height = 0;
   
    if (tree->left || tree->right) {
    	int leftheight = 0, rightheight = 0;

        if (tree->left) {
            leftheight = height_recursive(tree->left);
        }

        if (tree->right) {
            rightheight = height_recursive(tree->right);
        }

        if (leftheight > rightheight) {
            height = leftheight + 1;
        }
    	else{
    		height = rightheight + 1;
    	}
    }  
 
    return height;
}

int height(node*tree){
	int height = -1;
    if (tree != NULL) {
        height = height_recursive(tree);
    }
    return height;
}

void inorderDraw(node *tree, char A[][20])
{
	if(tree!=NULL){	
		inorderDraw(tree->left, A);
		x = counter++; //add one to global i at each call to track total nodes traversed		
	  	y = 3 - height_recursive(tree); //assuming saturated tree, depth of each node = tree height - subtree height
	  	//printf("(x,y) for %c is (%d,%d)\t", tree->data, x, y);
	  	A[y][x] = tree->data; //transfer node to corresponding array index
	  	inorderDraw(tree->right, A);	  	
	}
}

void inorder(node*tree)
{
	if(tree!=NULL){
		

		inorder(tree->left);
	  	printf("%c\t",tree->data);
	  	inorder(tree->right);
	  	
	}
}

void postorder(node*tree)
{
	if(tree!=NULL){ //if tree not emtpy
	
		postorder(tree->left);
	  	postorder(tree->right);
	  	printf("%c\t",tree->data);
	}
}

void preorder(node*tree)
{
	if(tree!=NULL)
	{
		printf("%c\t",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

int main()
{
	node* tree=NULL;
	//tree shape stored into 2d array
	char grid[5][20];
	//initialize array with spaces
	int i, j;
	for(i = 0; i < 5; i++){
		for(j = 0; j < 20; j++){
			grid[i][j] = ' ';
		}
	}

	int h;
	//tree array
	char c[100]={'0','1','2','3','4','5','6','7','8','9','A','B', 'C', 'D', 'E'};
	//build linked node tree from array
	tree=insert(c,0);	
	printf("Inorder traveral:\n");
	inorder(tree);
	printf("\nPostorder traversal:\n");
	postorder(tree);
	printf("\nPreorder traveral:\n");
	preorder(tree);
	printf("\n");
	printf("Binary Tree drawn:\n");
	inorderDraw(tree, grid);
	for(i = 0; i < 5; i++){ //print the 2d array as a grid
		for(int j = 0; j < 20; j++){
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	

	return 0;

}