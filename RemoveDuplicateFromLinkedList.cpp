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

void RemoveDuplicate(Node** head_ref)
{
	Node* temp=*head_ref,*prev,*need;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
		if(prev!=temp && prev->data==temp->data)
		{
			prev->next=temp->next;
			need=temp;
			temp=temp->next;
			free(need);
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
	push(&head,4);
	push(&head,2);
	push(&head,2);
	push(&head,1);
	
	cout<<"After pushing data";
	printList(head);
	
	
	
	RemoveDuplicate(&head);
	cout<<endl;
	printList(head);
	
	
	return 0;
	
	
}
