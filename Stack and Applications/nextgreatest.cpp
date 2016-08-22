#include "mystack.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	//int next_greatest[n];
	int next_greatest_index[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		next_greatest_index[i]=-1;
	}
	
	Stack h;
	int i=0;
	while(i<n)
	{

		if(h.empty())
		{
			h.push(i);
			i++;
			continue;
		}
		else
		{
			while(arr[i]>=arr[h.top()])
			{
				
				int pop_ele = h.pop();
				if(pop_ele == -1)
				{
					break;
				}
				else
				{

					next_greatest_index[pop_ele] = i;
					
				}
			}
			h.push(i);
			i++;
		}

	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		if(next_greatest_index[i] == -1)
			cout<<-1<<" ";
		else cout<<arr[next_greatest_index[i]]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<next_greatest_index[i]<<" ";
	}
	cout<<endl;

}