#include "myqueue.h"
using namespace std;
myqueue::myqueue()
{
	head = NULL;
	size = 0;
}
myqueue::~myqueue()
{
	delnode(head);
}
void myqueue::delnode(node * n)
{
	if(n== NULL)
		return;
	delnode(n->next);
	delete n;
}
bool myqueue::enqueue(int a)
{
	if(head == NULL)
	{
		head = new node();
		head->data = a;
		head->next = NULL;
		size++;
		return true;
	}
	else
	{
		node* temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		node * temp1 = new node();
		temp1->data = a;
		temp1->next = NULL;
		size++;
		temp->next = temp1;
		return true;
	}
	return false;
}
int myqueue::dequeue()
{
	if(head == NULL)
	{
		return -1;
	}
	else
	{
		node* temp = head;
		int a = temp->data;
		temp = temp->next;
		delete head;
		head = temp;
		size--;
		return a;
	}
}
void myqueue::print()
{
	if(head == NULL)
	{
		cout<<"null"<<endl;
	}
	else
	{
		node* temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		} 
		cout<<endl;
	}
}
int main()
{
	myqueue Q;
	char c;
	cin>>c;
	while(c!='q')
	{
		if(c == 'e')
		{
			int n;
			cin>>n;
			int arr[n];
			for(int i = 0;i<n;i++)
			{
				cin>>arr[i];
			}
			for(int i = 0;i<n;i++)
			{
				Q.enqueue(arr[i]);
			}
		}
		if(c == 'p')
		{
			Q.print();
		}
		if(c == 'd')
		{
			int n;
			cin>>n;
			for(int i = 0;i<n;i++)
			{
				if(Q.dequeue() == -1)
					break;
			}
		}
		cin>>c;
	}
}
