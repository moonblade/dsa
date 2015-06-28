/*
	Ex No. 22
	Implement Binary Search Tree
	S4R 036 Mohamed Insaf K
	07-04-2015
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* GetNewNode(int data);
void insert(struct node **root, int data);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node* search(struct node *, int );
int main()
{
	int choice, data;
	struct node *root = NULL;

	printf("Binary Search Tree");
	while(1)
	{
	printf("\n1. Insert"
		"\n2. Delete"
		"\n3. Inorder Traversal"
		"\n4. Preorder Traversal"
		"\n5. Postorder Traversal"
		"\n6. Exit"
		"\nPlease Choose: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter value to be inserted: ");
				scanf("%d", &data);
				insert(&root, data);
				break;
			case 2:
				scanf("%d", &data);
				if(search(root, data) != NULL)
					printf("Found\n");
				else
					printf("Not\n");
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				return 0;
				break;
			default:
				break;
		}
	}
}

struct node* GetNewNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(struct node **root, int data)
{
	if( *root == NULL )
		*root = GetNewNode(data);
	else if(data <= (*root)->data)
		insert(&((*root)->left), data);
	else
		insert(&((*root)->right), data);
}

void inorder(struct node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d, ", root->data);
	inorder(root->right);
}

void preorder(struct node *root)
{
	if(root == NULL)
		return;
	printf("%d, ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d, ", root->data);
}

struct node* search(struct node *root, int key)
{
//MODIFIED
	if(!root)
		return NULL;
	if((root->next)->data == key)
		return root;
	else if(key < (root->next)->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

int delete(struct node **root, int data)
{
	struct node *temp;
	if(!(*root))
		return NULL;
	if( )
	{
	}
	temp = search( *root, data);
}
