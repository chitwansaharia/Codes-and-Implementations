#include "mystack.h"

Stack::Stack()
{
	size = 0;
	head = NULL;
}
Stack::~Stack()
{

}
int Stack::top()
{
	if(head == NULL) return -1;
	return head->data;
}
void Stack::push(int x)
{
	node * temp = head;
	if(temp == NULL)
	{
		temp = new node();
		temp->data = x;
		temp->next = NULL;
		head = temp;
	}
	else
	{
		node* temp1 = new node();
		temp1->data = x;
		temp1->next = temp;
		head = temp1;
	}
}
int Stack::pop()
{
	if(head == NULL)
	{
		return -1;
	}
	else
	{
		node* temp = head;
		int pop_val = temp->data;
		head = head->next;
		delete temp;
		return pop_val;

	}
}
bool Stack::empty()
{
	if(head == NULL)
	{
		return true;
	}
	else
		return false;
}

