#include<iostream>
using namespace std;
class students						//creating a class objects of which serve as the elements of linked list
{
	public:
	int roll;
	
	students *next;
};
int main()
{
	students *traverse,*head;								
	int i = 0;

	traverse = new students;					//creating the first element of linked list
	head  = traverse;							//traverse is pointing temporarily to the 1st element of the linked list and head is pointing to it permanently
	int size;									//taking the size of linked list as an input
	cin>>size;
	while(i<size-1)
	{

		traverse->next = new students;			//creating elements of linked list one by one and assigning them their values and linking them
		traverse->roll = i+1;
		traverse = traverse->next;
		i++;
	}
	traverse->roll = i+1;						//initialising the last element of linked list
	traverse->next = NULL;
	if(size>1)
	{
		students *head1 = traverse;					//for reversal now we make a new head1 that points to the last element
		traverse = head;
	
		i=0;
		while(i<size)								//output of original linked list
		{
			cout<<traverse->roll<<" ";
		
			traverse = traverse->next;
			i++;
		}
		cout<<endl;
	
		students *temp1 = head;
		students *temp2=temp1->next;				//creating pointers that point to the first 3 elements of the linked list
		students *temp3=temp2->next;
		i=0;
		while(i<size-1)								//code for reversing the linking
		{
			temp2 ->next = temp1;
			temp1 = temp2;
			temp2 = temp3;
			if(temp3)
			{
				temp3 = temp3->next;
			}	
			i++;
		}
		head->next = NULL;				//making the next pointer of fist element of the original linked list to null 

	
		students *traverse1 = head1;
		for(i=0;i<size;i++)							//giving the output of reversed linked list 
		{
			cout<<traverse1->roll<<" " ;
			traverse1 = traverse1->next;
		}
	}	
	else
	{
		cout<<"linked list is already reversed";
	}
	
}





