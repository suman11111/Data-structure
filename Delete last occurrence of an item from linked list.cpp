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
	(*head_ref)=new_node; 
}


void deleteLastK(Node** head_ref,int k)
{
	Node* temp=*head_ref;
	Node* catch1;
	
	while(temp!=NULL )   //1st find the occurence of last node with value k
	{	
		if(temp->data==k)
		{
			
			catch1=temp;
			
		}
		
		temp=temp->next;
	}

// now deletion happen according to the place where the node with value k is located

// if node is located somwhere in the middle of linked list
	if(catch1!=NULL && catch1->next!=NULL)
	{
		temp=*head_ref;
		while(temp->next!=catch1)
		{
			temp=temp->next;
		}
		temp->next=catch1->next;
		free(catch1);
	}
	
	// if node to be deleted is last node
	
	if(catch1!=NULL && catch1->next==NULL)
	{
		temp=*head_ref;
		while(temp->next!=catch1)
		{
			temp=temp->next;
		}
		temp->next=NULL;
		free(catch1);
		
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
	Node* head=NULL; 
	push(&head,4);
	push(&head,4);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	cout<<"After pushing data";
	printList(head);
	
	int k=4;
	
	deleteLastK(&head,k);
	
	cout<<endl<<"After deleting last occurence of item:";
	printList(head);
	
	
	return 0;
	
	
}
