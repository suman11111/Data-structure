//sorted linked list is given
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

void RemoveMiddle(Node** head_ref)
{
	Node* fp=*head_ref;
	Node* sp=*head_ref;
	
	while(fp!=NULL && fp->next!=NULL)
	{
		fp=fp->next->next;
		sp=sp->next;
	}
	cout<<"\n Middle deleted element is:"<<sp->data;
	
	Node*temp=*head_ref;
	while(temp->next!=sp)
	{
		temp=temp->next;
	}
	temp->next=sp->next;
	free(sp);
	
	
	
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
	
	
	RemoveMiddle(&head);
	cout<<"\n After deleting middle element:";
	
	printList(head);
	
	return 0;
	
	
}
