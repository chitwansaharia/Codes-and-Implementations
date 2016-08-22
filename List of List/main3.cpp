#include "list_of_list.h"
int main()
{
	datastore<int>x;
	char ch;
	cin>>ch;
	while(ch!='q')
	{
		if(ch =='i')
		{
			int n;cin>>n;
			for(int i = 0;i<n;i++)
			{
				int h;
				cin>>h;
				x.insert(h);
			}
		}
		if(ch == 'p')
		{
			x.print();
		}
		if(ch == 'd')
		{
			int n;cin>>n;
			x.decrement(n);
		}
		if(ch == 's')
		{
			int n;
			cin>>n;
			cout<<x.search(n)<<endl;
		}
		if(ch == 'm')
		{
			cout<<x.find_max()<<endl;
		}
		if(ch == 'l')
		{
			x.list_max();
		}
		if(ch == 'z')
		{
			x.list_zero();
		}
		if(ch == 'r')
		{
			x.reset();
		}
		if(ch == 'c')
		{
			int n;
			cin>>n;
			x.list_count(n);
		}
		if(ch == 'x')
		{

		}
		if(ch == 'e')
		{
			int n;cin>>n;
			cout<<x.eject(n)<<endl;;
		}
		cin>>ch;
	}
}