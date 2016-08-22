//the below program works for string inputs of all input sizes(not when the third string is smaller than the first two)....  
//but it is ensured that all the possible outputs are printed.. 
//the program keeps in mind that the starting character must not be assigned 0





#include<iostream>
#include<map>
#include<cstring>
using namespace std;
bool b = true;
map<char,int> m;
map<char,int>prev;
int *carry;
int size;
int count =0;

bool assign(int n,string s,bool arr[])
{	
	if(n==s.length())
	{	

		if(s.length()==size*3)
		{
			if(m[s[n-1]]==0||(m[s[n-2]]==0 && s[n-2]!='0')||(m[s[n-3]]==0 && s[n-3]!=0))
				return false;
		}
		if(s.length()==size*3+1)
		{
			if((m[s[n-3]]==0 && s[n-3]!='0')||(m[s[n-4]]==0 && s[n-4]!= '0'))
				return false;
		}
		
		if(prev!=m || count==0)
		{
		map<char,int> :: iterator i1 = m.begin();
		while(i1!=m.end())
		{	if(i1->first!='0')
			cout<<i1->first<<" "<<"="<<" "<<i1->second<<endl;
			i1++;
		}
		prev=m;
		count++;
		cout<<endl;
		}
		
		return true;
	}

		if(s[n]=='0')
		{
			if(assign(n+1,s,arr))
			{
				return true;
			}
			else
				return false;

		}
	for(int i=0;i<=9;i++)
	{	
		
				if((n+1)==s.length()&&(n+1)%3!=0)
			{
				if(carry[size+1]==0)
				{
					return false;
				}
			    if(m[s[n]]==-1)
				{
					if(arr[1]==false)
					{
						m[s[n]]=1;
						arr[1]=true;
					}
					else
						return false;
				}
				if(m[s[n]]!=-1)
				{
					if(m[s[n]]!=1)
					{
						return false;
					}
				}
				bool dum = assign(n+1,s,arr);
				if(dum)
				{
					return true;
				}
			}
			else 
			{
			if((n+1)%3!=0)
			{	
			bool b1=true;
			if(m[s[n]]==-1)
			{
				while(arr[i] && i<10)
				{
					i++;
				}
				if(i==10)
				{
					return false;
				}
				b1=false;
				m[s[n]]=i;
				arr[i]=true;
			}	
			//cout<<s[n]<<"--->"<<m[s[n]]<<"  ";
			if(!assign(n+1,s,arr))
			{	
				if(!b1)
				{
					arr[m[s[n]]]=false;
					m[s[n]]=-1;
					continue;
				}
					if(b1)
						return false;
				}
				else if(assign(n+1,s,arr))
				{	
					if(!b1)
					{
						arr[m[s[n]]]=false;
						m[s[n]]=-1;
						continue;
					}
					else
					{
						return true;
					}
					
				}

		}
		else if((n+1)%3==0)	
		{
			
			bool b2=true;
			int z = m[s[n-1]]+m[s[n-2]]+carry[(n+1)/3];
			if(n+1==s.length() && z>=10)
			{
				return false;
			}
			if(arr[z%10]==false)
			{
				if(m[s[n]]==-1)
				{
				b2=false;
				m[s[n]]=z%10;
				arr[z%10]=true;
				
				if(z>=10)
					carry[((n+1)/3)+1]=1;
				b=assign(n+1,s,arr);
				}

				else if(m[s[n]]!=-1)
				{
					if(z%10==m[s[n]])
					{
						//carry=0;
						if(z>=10)
						{
							carry[((n+1)/3)+1]=1;
						}
						b = assign(n+1,s,arr);

					}
					else
					{
						return false;
					}
				}
				
			}	
				
			else
			{
				if(z%10==m[s[n]])
				{	
					if(z>=10)carry[((n+1)/3)+1]=1;
					b=assign(n+1,s,arr);
				}
					else
					{
						return false;
					}
			}	
					if(!b)
					{
					carry[((n+1)/3)+1]=0;
					if(b2)
					{
						return false;
					}
					else
					{
					arr[m[s[n]]]=false;
					m[s[n]]=-1;
					return false;
					}}
					else if(b)
					{	

						carry[((n+1)/3)+1]=0;
						if(b2)
						{	
							return true;
						}
						else
						{
							arr[m[s[n]]]=false;
							m[s[n]]=-1;
							return true;
						}
					}
					
				}
		}
		
			
	
	}
	
	return false;
}



int main()
{
	
		
	string s1;string s2;string s3;
	cin>>s1;
	cin>>s2;
	cin>>s3;

	int size1,size2;
	size2 = s1.length();
	size1=s2.length();
	size = max(size1,size2);
	char *s5 = new char[size];
	if(s1.length()<s2.length())
	{	int i;
		for( i =0;i<size1-size2;i++)
		{
			s5[i]='0';
		}int k=0;
		for(;i<s2.length();i++)
		{
			s5[i]=s1[k];
			k++;
		}
		s1=s5;

	}
	if(s1.length()>s2.length())
	{	int i;
		for( i =0;i<size2-size1;i++)
		{
			s5[i]='0';
		}int k=0;
		for(;i<s1.length();i++)
		{
			s5[i]=s2[k];
			k++;
		}
		s2=s5;

	}


	string s4=s1+s2+s3;
	
	int k=0;
	for(int i=size-1;i>=0;i--)
	{
		s4[k]=s1[i];
		s4[k+1]=s2[i];
		if(s3.length()>s1.length())
		s4[k+2]=s3[i+1];
		else
			s4[k+2]=s3[i];
		k+=3;
	}
	if(s3.length()>s1.length())
	{
	s4[k]=s3[0];
	}

	carry = new int[size+2];
	for(int i=0;i<=size+1;i++)
		carry[i]=0;
	for(int i =0;i<s4.length();i++)
	{	
		if(s4[i]!='0')
		m[s4[i]]=-1;
	}
	m['0']=0;

	bool arr[10];
	for(int j=0;j<10;j++)
	{
		arr[j]=false;
	}
	bool b8 = assign(0,s4,arr);
	if(count==0)
	{
		cout<<"NO SOLUTION"<<endl;
	}
	else
		cout<<"No. of Solutions"<<" "<<"="<<" "<<count<<endl;
	
}