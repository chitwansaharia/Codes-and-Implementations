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
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		if(next_greatest_index[i]!=-1)
		{
			for(int j=i;j<next_greatest_index[i];j++)
			{
				sum+=(arr[i]-arr[j]);
			}
			i = next_greatest_index[i]-1;
		}
		else if(next_greatest_index[i] == -1 && i!=n-1)
		{
			int j=0;
			i++;
			for(j=i;next_greatest_index[j]!=-1;j++);
			
			while(i<j)
			{
				sum+=(arr[j]-arr[i]);
				i++;
			}
			i=i-1;
		}
	}
	i=0;
	for( i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<sum<<endl;

}