#include "bst.h"
using namespace std;
BST::BST()
{
	root=NULL;
}
BST::~BST()
{
	delete root;
}
bool BST::search(int x) const
{	
	BSTNode* temp = root;
	while(temp!=NULL)
	{
		if(temp->data == x)
		{
			return true;
		}
		else if(temp->data<x)
		{
			temp = temp->right;
		}
		else
		{
			temp= temp->left;
		}
	}
	return false;

}
void BST::insertrecur(BSTNode* node,int x)
{
 		if(node->data>x)
		{
			if(node->left == NULL)
			{
				node->left = new BSTNode();
				node->left->data = x;
				node->left->left = NULL;
				node->left->right = NULL;
				return;
			}
			else
				insertrecur(node->left,x);
		}
		else if(node->data<x)
		{
			if(node->right == NULL)
			{
				node->right = new BSTNode();
				node->right->data = x;
				node->right->left = NULL;
				node->right->right = NULL;
				return;
			}
			else
				insertrecur(node->right,x);
		}
	
	
}
void BST::insert(int x)
{
		if(root==NULL)
		{
			root = new BSTNode();
			root->data = x;
			root->left = NULL;
			root->right = NULL;
			return;
		}
		insertrecur(root,x);
		
}
void BST::print() const
{
	printrecur(root);
	cout<<endl;
} 
void BST::printrecur(BSTNode * node) const
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL)
		{
			cout<<node->data<<" ";
			return;
		}
	if(node->left!=NULL)
	{
		printrecur(node->left);

	}
	cout<<node->data<<" ";
	if(node->right!=NULL)
	{
		printrecur(node->right);
	
	}

}
void BST::printroot() const
{
	if(root == NULL)
		return;
	else
	{
		//cout<<root->data<<" ";
	
	if(root->left != NULL)
		cout<<root->left->data<<" " ;
	cout<<root->data;
	if(root->right!=NULL)
		cout<<root->right->data<<" ";
	}
	cout<<endl;

}
void BST::remove(int x)
{
		BSTNode* temp1 = NULL;
		BSTNode* temp2 = root;
		if(temp2 == NULL)
		{
			return;
		}
		while(true)
		{
			if(temp2->data == x)
			{
				if(temp1 == NULL)
				{
					root = temp2->left;
					BSTNode* temp3 = temp2->right;
					temp1 = temp2-> left;
					while(temp1->right!=NULL)
					{
						temp1 = temp1->right;
					}
					temp1->right = temp3;
					return;
				}
				if(temp1->right->data == x)
				{
					temp1->right = temp2->right;
					BSTNode* temp4 = temp2->left;
					if(temp2->right!=NULL)
					{
						BSTNode* temp3 = temp2->right;
						while(temp3->left!=NULL)
						{
						temp3 = temp3->left;
						}
					temp3->left = temp4;
					return;
					}
					else
					{
						temp1->right = temp2->left;
						return;
					}
				}
				else
				{
					temp1->left = temp2->left;
					BSTNode* temp4 = temp2->right;
					if(temp2->left!=NULL)
					{
						BSTNode* temp3 = temp2->left;
						while(temp3->right!=NULL)
						{
						temp3 = temp3->right;
						}
					temp3->right = temp4;
					return;
					}
					else
					{
						temp1->left = temp2->right;
						return;
					}
					
				}
			}
			else if(temp2->data>x )
			{
				temp1 = temp2;
				temp2 = temp2->left;
			}
			else
			{
				temp1 = temp2;
				temp2 = temp2->right;
			}
		}


}
void BST::rebalance(int x)
{
BST * temp = new BST();
temp->insert(x);
remove(x);
while(root!=NULL)
{
	temp->insert(root->data);
	remove(root->data);
}		
root = temp->root;
temp->root = NULL;	
}