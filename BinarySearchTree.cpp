#include <iostream>

using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

struct node* NewNode(int data)
{
	struct node* node = new(struct node);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
};

static int lookup(struct node* node,int target)
{

	if(node == NULL)
	{
		return false;
	}

	else
	{
		if(target == node->data)
		{
			return true;
		}

		else
		{
			if(target < node->data)
			{

				return lookup(node->left,target);

			}

			else
			{

				return lookup(node->right,target);
			}
		}
	}


}

struct node* insert(node* node,int data)
{

	if(node == NULL)
	{
		return NewNode(data);
	}

	else
	{
		if(data <= node->data)
		{
			node->left = insert(node->left,data);
		}
		else
		{
			node->right = insert(node->right,data);
		}
		return node;
	}

}

int size(struct node* node)
{
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		return size(node->left) + 1 + size(node->right);
	}

}

int MaxDepth(struct node* node)
{
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		int LDepth = MaxDepth(node->left);
		int RDepth = MaxDepth(node->right);

		if(LDepth > RDepth) return LDepth + 1;
		else return RDepth + 1;
	}

}

int MinValue(struct node* node)
{
	struct node* current = node;

	while(current->left != NULL)
	{
		current = current->left;
	}

	return current->data;
}

int MaxValue(struct node* node)
{
	struct node* current = node;

	while(current->right != NULL)
	{
		current = current->right;
	}

	return current->data;
}

void printTree(struct node* node)
{
	if (node == NULL)
	{
		return ;
	}
	else
	{
		printTree(node->left);
		cout << node->data << " ";
		printTree(node->right);

	}

}

void printPostOrder(struct node* node)
{
	if (node == NULL)
	{
		return ;
	}
	else
	{
		printTree(node->left);
		printTree(node->right);
		cout << node->data << " ";
	}
}


int main(){

	struct node* root = NewNode(7);
	insert(root,1);
	insert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	//cout << lookup(node,40) << endl;
	cout << size(root) << endl ;
	cout << MaxDepth(root) << endl ;
	cout << MinValue(root) << endl ;
	cout << MaxValue(root) << endl ;

	printTree(root);
	printPostOrder(root);

	return 0;
}

