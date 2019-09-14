#include <bits/stdc++.h> 
using namespace std;

class Node
{	public:
	int data;
	Node *next;
};

void push(Node** head_ref,int new_data)   
{
	Node* new_node=new Node();
	new_node->data=new_data;
	new_node->next=(*head_ref); 
	(*head_ref)=new_node;/*  move the head to point to the new node */
}

void skippeddeletenode(Node** head_ref,int m,int n)
{
	if(*head_ref==NULL)
	cout<<"not possible";
	
	Node* temp= *head_ref;
	Node* prev;
	
	while(m-1 && temp!=NULL)
	{
		temp=temp->next;
		m--;
	}
	
	
	while(n && temp!=NULL)
	{
		prev= temp;
		if(temp->next)   //only if  temp->next will not be  then only enter inside
		{
			temp=temp->next;
			prev->next=temp->next;
			free(temp);
			temp=prev;
			n--;
		}
		else
		{
			break;
		}
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
	push(&head,4);
	push(&head,2);
	push(&head,1);
	cout<<"After pushing data";
	printList(head);
	int m=3,n=3;
	
	skippeddeletenode(&head,m,n);
	
	cout<<"\n";
	printList(head);
	
	
	return 0;
	
	
}
