#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* head;
void revlist(node* headpoint,node * head1,node * tail1)
{
	if(head1 == tail1)
		return;
	bool headpoint1  = true;
	if(head1 == head)
	{
		headpoint1 = false;
	}
	node * temp = head1;
	node * temp1 = head1->next;
	node * temp2 = NULL;
	while(temp1!=tail1)
	{
		temp2 = temp1->next;
		temp1->next = temp;
		temp = temp1;
		temp1 = temp2;
	}
	temp1->next = temp;
	head1->next = NULL;
	if(headpoint1)
	{
		headpoint->next = tail1;
	}
	else
	{
		head = tail1;
	}
	
}
void insert(int a)
{
	if(head == NULL)
	{
		head = new node();
		head->data =a;
		head->next = NULL;
	}
	else
	{
		node * temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = new node();
		temp->next->data = a;
		temp->next->next = NULL;
	}
}
void display()
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main()
{
	head = NULL;
	char ch;
	cin>>ch;
	//node * temp = head;
	while(ch!='q')
	{
		if(ch == 'i')
		{
			int n;cin>>n;
			int n1;
			for(int i = 0;i<n;i++)
			{
				cin>>n1;
				insert(n1);
			}

		}
		if(ch == 'p')
		{
			display();
		}
		if(ch == 'r')
		{
			int n;cin>>n;
			node * temp  = head;
			node * headpoint = NULL;
			while(temp!= NULL)
			{
				node * temp1  = temp;
				for(int i=1;i<n;i++)
				{
					if(temp1->next == NULL)
						break;
					temp1 = temp1->next;
				}
				bool t = false;
				node* temp2;
				if(temp1!=NULL)
				{
					temp2 = temp1 -> next;
					t = true;
				}
				revlist(headpoint,temp,temp1);
				headpoint = temp;
				if(t)
				{
					temp->next = temp2;
					temp = temp->next;
				}
			}
		}
		cin>>ch;
	}
}