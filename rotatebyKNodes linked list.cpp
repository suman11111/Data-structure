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

void rotateByKNodes(Node** head_ref,int k)
{
	int count=1;
	Node* temp=*head_ref;
	Node* prev;
	
	if(k==0)  		//if no ratation by any number of nodes
		return;
		
	while(count<=k && temp!=NULL)
	{	
		prev=temp;
		temp=temp->next;
		count++;
		
	}
	if(temp==NULL)   //when k is equal to total number of nodes in list then obviously temp will become null in while loop above so we will live the loop as it is
	{
		return;
	}
	
	prev->next=NULL;    // if k is less then number of nodes
	Node *tp=temp;
	
	while(tp->next!=NULL)
	{
		tp=tp->next;
	}
	tp->next=*head_ref;
	
	*head_ref=temp;
	
	
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
	
	int k=4;
	
	rotateByKNodes(&head,k);
	cout<<endl;
	printList(head);
	
	
	return 0;
	
	
}
