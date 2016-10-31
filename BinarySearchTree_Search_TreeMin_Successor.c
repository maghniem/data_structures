#include <stdlib.h>
#include <stdio.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};
 
/* function that allocates a new node with the given data and 
    NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->parent = NULL;

    return(node);
}
 
/* inserts a new node with the given number in the correct place in the tree. Returns the new
    root pointer which the caller should then use.*/
struct node* insert(struct node* node, int data)
{
    /* if the tree is empty, return a new,
      single node */
    if (node == NULL)
        return (newNode(data));
    else
    {
        struct node *temp;  //create newnode temp

        //   go down the tree 
        if (data < node->data) // if key is less or equal insert on left
        {    
            temp = insert(node->left, data); //insert newnode temp
            node->left  = temp; //set pointers
            temp->parent= node;
        }
        else if(data > node->data) //if data is greater than node.data insert on the right
        {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
        else //if they are equal do not insert duplicate
        {
            printf("Key %d already exists in tree\n\n", data);
            return node;
        }         

        //return the root node pointer unchanged but with a new insertion added
        return node;
    }
} 

void print_inorder( struct node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d ",tree->data);
        print_inorder(tree->right);
    }
}


//function will check nodes if greater or less than value
//will call search on the new node when traversing to left or right
//will return a pointer to the node when found (true)
//returns NULL if not found (false)
struct node* search(struct node * tree, int val)
{
    if(tree == NULL) //if key not found or tree is empty
    {
        return NULL;
    }

    if(val < (tree)->data) 
    {
        search( tree->left, val);
    }
    else if(val > (tree)->data)
    {
        search( tree->right, val);
    }
    else if(val == (tree)->data)
    {
        return tree; //when key is found return node
    }
}

//given a root node to a BST or a subtree, return leftmost leaf
struct node * TreeMin(struct node* node) {
    struct node* current = node;
  
    //loop down to find the leftmost leaf
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node * Successor(struct node *root, struct node *k)
{   
    if( k->right != NULL )
        return TreeMin(k->right);

    else{
        struct node *p = k->parent;
        while(p != NULL && k == p->right)
        {
            k = p;
            p = p->parent;
        }
        return p;
    }
}

int main(void){

    struct node *root = NULL; 
    struct node *tmp = NULL; 
    int i;

 //**********************************************************************  
    //insert the nodes using array

    int values[13] = {16, 5, 18, 2, 15, 17, 19, 1, 3, 3, 13, 12, 14};
    for(i = 0; i < 13; i++){
       root = insert(root, values[i]);
    }   
    //print using inorder display   
    printf("In Order Display\n");
    print_inorder(root);
    printf("\n\n");

 //************************************************************************
    //searching key values 
    int k;
    for( k = 1; k <=20; k++){  //search for values 1 to 20 in tree
        tmp = search(root, k);

        if (tmp) //if tmp is not NULL i.e key found  
        {
            printf("%d is found, parent is:\t", k);
            if( tmp->parent != NULL ) //must check if parent exists before printing, in case of root node
                printf("%d\n", (tmp->parent)->data );
            else
                printf("NULL\n");       
        }
    }
    printf("\n\n");
 //**********************************************************************
    //finding successor nodes   
    for( k = 1; k <=20; k++){  //search for values 1 to 20 in tree
        tmp = search(root, k);
        if(tmp){ //k must exist to have a successor
            tmp = Successor(root, tmp);
            if(tmp) //if successor found
                printf("Successor of node %d is: %d\n", k, tmp->data);
            else
                printf("No successor of %d\n", k);            
        }
    } 

    return 0;
}
    

