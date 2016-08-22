#include "list_of_list.h"

template<class T>
datastore<T>::datastore()
{
	head = NULL;
}
template<class T>

datastore<T>::~datastore()
{
	deleteList(head);
}
template<class T>
void datastore<T>::deleteList(count_list* list)
{
	if(list == NULL)
	{
		return;
	}

	deleteItem(list->node);
	deleteList(list->next);
	delete list;
}
template<class T>
void datastore<T>::deleteItem(item* item1)
{
 if(item1 == NULL)
 {
 	return;
 }
 deleteItem(item1->next);
 delete item1;

}
template<class T>
void datastore<T>::insert(T t)
{
	int count1 = search(t);
	count_list *temp = head;
	
	if(count1 == -1)
	{

		item* newitem = new item();
		newitem->id = t;
		newitem->next = NULL;
		if(head == NULL)
		{
			head = new count_list();
			head->count = 1;
			head->num = 1;
			head->next= NULL;
			head->node = newitem;
			//clean();
			return;
		}
		if(head->count == 0)
		{
			temp = head->next;
			if(temp == NULL)
			{
				head->next = new count_list();
				head->next->count = 1;
				head->next->num = 1;
				head->next->node = newitem;
				head->next->next = NULL;
				clean();
				return;
			}
		}
		if(temp->count == 1)
		{
			item* temp1 = temp->node;
			temp->node = newitem;
			newitem->next = temp1;
			temp->num++;

			return;
		}
		else
		{
			count_list * newlist = new count_list();
			newlist->count = 1;
			newlist->num = 1;
			newlist->next = temp;
			if(head->count == 0)
			{
				head->next = newlist;
			}
			else
			{
				head = newlist;
			}
			newlist->node = newitem;
			return; 

		}
	}
	else
	{
		while(temp->count != count1)
		{
			temp = temp->next;
		}	
		item* temp2 = NULL;	
		item* temp1 = temp->node;
		while(temp1->id != t)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		if(temp2 == NULL)
		{
			temp->node = temp1->next;
		}
		else
		{
			temp2->next = temp1->next;
		}
		temp->num--;
		temp = temp->next;
		count1++;
		item* newitem = new item();
		newitem->id = t;
		newitem->next = NULL;
		if(temp == NULL)
		{
			count_list* temp3 = head;
			count1--;
			while(temp3->count != count1)
			{
				temp3 = temp3->next;
			}
			count_list* newlist = new count_list();
			newlist->count = count1+1;
			newlist->num = 1;
			newlist->node = newitem;
			newlist->next = temp3->next;
			temp3->next = newlist;
			clean();
			return;
				
		}
		if(temp->count == count1)
		{
			item* node1 = temp->node;
			temp->node = newitem;
			newitem->next = node1;
			temp->num++;
			clean();
			return;
		}
		else
		{
			count_list* temp3 = head;
			count1--;
			while(temp3->count != count1)
			{
				temp3 = temp3->next;
			}
			
			count_list* newlist = new count_list();
			newlist->count = count1+1;
			newlist->num = 1;
			newlist->node = newitem;
			newlist->next = temp3->next;
			temp3->next = newlist;
			clean();
			return;
		}

	}

}
template<class T>
void datastore<T>::clean()
{
	count_list * tempp = head;
	count_list * tempp1 = NULL;
	while(tempp!=NULL)
	{
		if(tempp->node == NULL)
		{
			if(tempp1 == NULL)
			{
				head  = tempp->next;
			}
			else
			{
				tempp1->next = tempp->next;
			}
			break;
		}
		tempp1 = tempp;
		tempp=tempp->next;
	}

}
template<class T>
int datastore<T>::search(T t)
{
	if(head == NULL)
	{
		//cout<<"hello";
		return -1;

	}
	count_list *temp = head;

	while(temp!=NULL)
	{
		item* temp1 = temp->node;
		while(temp1!=NULL)
		{
			if(temp1->id == t)
			{
				return temp->count;
			}
			temp1 = temp1->next;

		}
		temp = temp->next;
	}

	return -1;
}
template<class T>
int datastore<T>::find_max()
{
	if(head == NULL)
	{
		return -1;
	}
	count_list* temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	return temp->count;
}
template<class T>
void datastore<T>::list_max()
{
	int count1 = find_max();
	if(count1 == -1)
	{
		return;
	}
	else
	{
		count_list* temp = head;
		while(temp->count!=count1)
		{
			temp = temp->next;
		}

		item* list = temp->node;
		//cout<<temp->count<<" ";
		while(list!=NULL)
		{
			cout<<list->id<<" ";
			list = list->next;		
		}
		cout<<endl;
	}
}
template<class T>
void datastore<T>::decrement(T t)
{
	int count1 = search(t);
	if(count1 == 0 || count1 == -1)
	{
		return;
	}
	else
	{
		count_list* temp = head;
		count_list* temp1 = NULL;
		while(temp->count!=count1)
		{
			temp1 = temp;
			temp = temp->next;
		}
		if(temp1 == NULL)
		{
			item* item1 = temp->node;
			item* item2 = NULL;
			while(item1->id!=t)
			{
				item2 = item1;
				item1 = item1->next;
				

			}
			if(item2 == NULL)
			{
				temp->node = item1->next;
			}
			else
			{

				item2->next = item1->next;
			}
			temp->num--;
			count1--;
			count_list* temp2 = head;
			head = new count_list();
			head->count = count1;
			head->num = 1;
			item* node = new item();
			node->id = t;
			node->next = NULL;
			head->node = node;
			head->next = temp2;
			clean();
			return;
		}
		else
		{
			item* item1 = temp->node;
			item* item2 = NULL;
			while(item1->id!=t)
			{
				item2 = item1;
				item1 = item1->next;
				

			}
			if(item2 == NULL)
			{
				temp->node = item1->next;
			}
			else
			{
				item2->next = item1->next;
			}
			count1--;
			temp->num--;
			item* node = new item();
			node->id = t;
			node->next = NULL;
			if(temp1->count == count1)
			{
				temp1->num++;
				node->next = temp1->node;
				temp1->node = node;
			}
			else
			{
				//cout<<"hello"<<count1<<endl;
				count_list* tt = new count_list();
				tt->count = count1;
				tt->num = 1;
				tt->node = node;
				tt->next = temp;
				temp1->next = tt;
			}
			clean();
		}

	}
	
}
template<class T>
void datastore<T>::print()
{
	count_list* temp = head;
	if(head == NULL)
	{
		return;
	}
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->count<<" ";
			item* node = temp->node;
			while(node!=NULL)
			{
				cout<<node->id<<" ";
				//cout<<"hello";
				node=node->next;
			}
			cout<<endl;
			temp = temp->next;
		}
	}
}
template<class T>
void datastore<T>::reset()
{
	
	datastore resetlist;
	count_list *temp = head;
	if(temp == NULL)
	{
		return;
	}
	else
	{
		while(temp!=NULL) 
		{
			item * temp1 = temp->node;
			while(temp1!=NULL)
			{
				resetlist.insert(temp1->id);
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
		head = resetlist.head;
		head->count = 0;
		resetlist.head = NULL;

	}

	
}
template<class T>
void datastore<T>::list_zero()
{
	if(head == NULL||head->count != 0)
	{
		return;
	}
	if(head->count == 0)
	{
		item* i = head->node;
		while(i!=NULL)
		{
			cout<<i->id<<" ";
			i = i->next;
		}
		cout<<endl;
	}

}
template<class T>
void datastore<T>::list_count(int n)
{
	count_list* temp = head;
	while(temp!=NULL)
	{
		if(temp->count == n)
		{
			cout<<temp->count<<" ";
			item* i = temp->node;
			while(i!=NULL)
			{
				cout<<i->id<<" ";
				i = i->next;
			}
			cout<<endl;
			break;
		}
		temp = temp->next;
	}
}
template<class T>
int datastore<T>::eject(T t)
{
	count_list* temp = head;
	int count1 = search(t);
	if(count1 == -1)
	{
		return 0;
	}
	else
	{
		while(temp->count!=count1)
		{
			temp = temp->next;
		}
		item* i = temp->node;
		item* i2 = NULL;
		while(i->id!=t)
		{		
			i2 = i;
			i = i->next;
		}
		if(i2 == NULL)
		{
			temp->node = i->next;
		}
		else
		{
			i2->next = i->next;
		}
		return 1;


	}
}
template class datastore<int>;
template class datastore<char>;
template class datastore<double>;
template class datastore<float>;