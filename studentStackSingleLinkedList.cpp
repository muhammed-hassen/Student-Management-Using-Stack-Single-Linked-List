#include<iostream>
using namespace std;
class
node {
	public: string name;
	int age;
	string sex;
	node* next;
};
class student{
	node* stacktop;
	public: 
	bool isEmpty();
	void push(string name,int age, string sex);
	void pop();
	void top();
	void view();
	student()
	{
		stacktop=NULL;
		
	}
	
};
void student::pop()
{
	if(isEmpty())
	{
		cout<<"\nthe stack is empty";
	}
	else
	{
		node* cnode=stacktop;
		stacktop=stacktop->next;
		cnode->next=NULL;
		delete cnode;
		cout<<"\nsucefully poped";
	}
}
void student::top()
{
	if(isEmpty())
	{
		cout<<"\nthe stack is empty";
	}
	else
	{
		cout<<"\nName\tAge\tsex";
		cout<<"\n"<<stacktop->name<<"\t"<<stacktop->age<<"\t"<<stacktop->sex;
	}
}
void student::view()
{
	if(!isEmpty())
	{
		node* temp=stacktop;
		cout<<"\nName\tAge\tSex";
		while(temp)
		{
			cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->sex;
			temp=temp->next;
		}
	}
	else
	{
		cout<<"\nthe stack is empty";
	}
}
void student::push(string name,int age,string sex)
{
	node*	newnode=new node;
	newnode->name=name;
	newnode->age=age;
	newnode->sex=sex;
	if(isEmpty())
	{
		stacktop=newnode;
		newnode->next=NULL;
	}
	else
	{
		newnode->next=stacktop;
		stacktop=newnode;
	}
	cout<<"\nsucefully pushed";
}

bool student::isEmpty()
{
	if(stacktop==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int choice;
	string name,sex;
	int age;
	student su;
	do
	{
		cout<<"\n========= Student Managment ============";
		cout<<"\n1push";
		cout<<"\n2top";
		cout<<"\n3pop";
		cout<<"\n4view";
		cout<<"\n5exit";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter name";
				cin>>name;
				cout<<"\nEnter age";
				cin>>age;
				cout<<"\nEnter sex";
				cin>>sex;
				su.push(name,age,sex);
				break;
			case 2:
				su.top();
				break;
			case 3:
				su.pop();
				break;
			case 4:
				su.view();
				break;
			
		}
	}while(choice!=5);
}
