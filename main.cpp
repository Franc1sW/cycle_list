#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *joseph(node *head,int m,int k);
//创建一个循环链表（单向)
node *cycle_list(int n,int m,int k)
{
	node *head=new node;
	node *p=head;
	//node *temp;
	node *temp;
	for(int i=0;i<n;i++)
	{
		temp=new node;
		temp->data=i+1;
		p->next=temp;
		p=temp;
	}
	head=head->next;
	p->next=head;
	while(head->next!=head)
	{
			head=joseph(head,m,k);
	}
	return head;	
}
//约瑟夫问题
node *joseph(node *head,int m,int k)
{
	node *p=head;
	node *p2=head;
	int x=m+k-1;
	for(int i=0;i<x-1;i++)
	{
		p=p->next;
		if(i<x-2)
			p2=p2->next;
	}
	p2->next=p->next;
	delete p;
	head=p2->next;
	return head;
}
//打印循环链表
void print_list(node *head)
{
	node *p=head;
	while(p->next!=p)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
	if(p->next==p)
		cout<<"empty"<<endl;
}
int main()
{
	cout<<"input n,m,k"<<endl;
	int n,m,k;
	cin>>n>>m>>k;
	node *p=cycle_list(n,m,k);
	print_list(p);
	return 0;
}
