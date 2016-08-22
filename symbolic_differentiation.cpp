//the following code takes the input of the form:(a+b) = (+(a)(b))
//I have done all part of the question but it is giving compilation error due to some type specifier issues which i am unable to point out//

//correction made in the code:

//the compilation problem has been removed.now the code works..

#include<iostream>
using namespace std;


int brac(string s,int j)
{
	int i = j+1;
	int ctr = 1;
	while(ctr!=0)
	{
		if(s[i]=='(')
			ctr++;
		else if(s[i]==')')
			ctr--;
		i++;

	}
	return i;
}
string truncate(string s,int i,int j)
{
	string newstr;int k = 0;
	for(int l = i+1;l<j;l++)
	{
		newstr = newstr+s[l];
	}
	
	return newstr;
}
class formula
{	
	public:
	string v;
	formula *left;
	formula *right;
	
	virtual formula* derivative() = 0;
	virtual void print() = 0;

};
class plu : public formula
{
public:
	formula* derivative()
	{
		formula *f = new plu;
		f->left = this->left->derivative();
		f->right = this->right->derivative();
		return f;
	}
	void print()
	{	
		cout<<"(";
		left->print();
		cout<< "+";
		right->print();
		cout<<")";
	}
};
class minu : public formula
{
public:
	formula *derivative()
	{
		formula *f = new minu;
		f->left = this->left->derivative();
		f->right = this->right->derivative();
		return f;
	}
	void print()
	{
		cout<<"(";
		left->print();
		cout<<"-";
		right->print();
		cout<<")";
	}
};
class multiply: public formula
{
public:
	formula* derivative()
	{
		formula *f = new plu;
		f->left = new multiply;
		f->right = new multiply;
		f->left->left = this->right;
		f->left->right = this->left->derivative();
		f->right->left = this->left;
		f->right->right = this->right->derivative();
		return f;
	}
	void print()
	{
		cout<<"(";
		left->print();
		cout<<"*";
		right->print();
		cout<<")";
	}
};
class var: public formula
{
	formula *derivative()
	{
		formula *f = new var;
		f->left = NULL;
		f->right=NULL;
		if(this->v =="x")
		{
			f->v= "1";
		}
		else
			f->v = "0";
		return f;

	}
	void print()
	{
		
		cout<<v;
	
	}
};
class divide : public formula
{
public:
	formula* derivative()
	{
	 	formula *f  = new divide;
	 	f->left = new minu;
	 	f->left->left = new multiply;
	 	f->left->right = new multiply;
	 	f->left->left->left = this->right;
	 	f->left->left->right = this->left->derivative();
	 	f->left->right->left = this->left;
	 	f->left->right->right = this->right->derivative();
	 	f->right = new multiply;
	 	f->right->right = f->right->left = this->right;
	 	return f;
	 }
	 	void print()
	{
		cout<<"(";
		left->print();
		cout<<"/";
		right->print();
		cout<<")";
	}
	 
};
formula * construct(string s)
{
	if((s[0]>='0'&&s[0]<='9')||(s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z'))
	{
		formula* f = new var;
		f->left = NULL;
		f->right = NULL;
		f->v = s[0];
		return f;

	}
	else
	{
		formula *f;
		switch(s[0])
		{
			case '+':  f = new plu;break;
			case '-':  f = new minu;break;
			case '/':  f = new divide;break;
			case '*':  f = new multiply;

		}

			int left1 = brac(s,1);
			int right1 = s.length()-1;
			string sl = truncate(s,1,left1-1);
			string sr = truncate(s,left1,right1);
			f->left = construct(sl);
			f->right = construct(sr);

			return f;

	}
}


int main()
{
	string s;
	cin>>s;
	string s1 = truncate(s,0,s.length());
	formula *f = construct(s1);
	f->print();cout<<endl;
	formula *f1 = f->derivative();
	f1->print();


}