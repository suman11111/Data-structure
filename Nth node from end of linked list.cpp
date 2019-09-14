#include <bits/stdc++.h> 
using namespace std;

class Node
{	public:
	int data;
	Node *next;
};

void push(Node** head_ref,int new_data)   //HEADREF IS POINTER NOT TO NODE BUT POINTER TO POINTER WHICH I POINTING TO NODE;
{
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=(*head_ref); 
	(*head_ref)=new_node;/*  move the head to point to the new node */
}

void KthNodesFromLast(Node** head_ref,int n,int k)
{
	int x=n-k+1;
	Node* temp=*head_ref;
	
	if(x>0)
	{
		while( x-1 && temp !=NULL)   //x-1 bcoz temp is pointing to head initially i.e. one node escaped
		{
			temp=temp->next;
			x--;
		}
		cout<<"\n"<<temp->data;
	}
	else
	{
		cout<<"\n"<<-1;
	}
	
	
	
}



  
void printList(Node *node)
{
	while(node!=NULL)
	{
		cout<<" "<<node->data;
		node=node->next;
	}
	
	
}



int main()
{
	Node* head=NULL; //head is an node pointer   but pointing to null,naya naam diye hai head 
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	cout<<"After pushing data";
	printList(head);
	
	int k=7;
	int n=6;
	
	KthNodesFromLast(&head,n,k);
	
	
	return 0;
	
	
}
