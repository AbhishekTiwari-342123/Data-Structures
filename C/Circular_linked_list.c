#include <stdio.h>
#include <stdlib.h>

//Defining the Structure
typedef struct node{
	int data;
	struct node *next;
}node;

//Intialising the head/start of the List
node *head=NULL;

//All the methods for the Circular Linked List

void create_node()
{
	node *p=(node *)malloc(sizeof(node));
	printf("Enter the data.\n");
	scanf("%d",&p->data);
	if(head==NULL){
		head=p;
		p->next=head;
	}
	else
		{
			node *q=head;
			while(q->next!=head)
				q=q->next;
			q->next=p;
			p->next=head;
			q=NULL;
		}	
	
		p=NULL;
}
void insert_beg()
{
	node *p=(node *)malloc(sizeof(node));
	printf("Enter the data.\n");
	scanf("%d",&p->data);
	if(head==NULL){
		head=p;
		p->next=head;
	}
	else
	{
		node *q=head;
		while(q->next!=head)
		{
			q=q->next;
		}
		q->next=p;
		p->next=head;
		head=p;
		q=NULL;
	}
	p=NULL;
}
void insert_end()
{
	node *p=(node *)malloc(sizeof(node));
	printf("Enter the data.\n");
	scanf("%d",&p->data);
	if(head==NULL){
		head=p;
		p->next=head;
	}
	else
	{
		node *q=head;
		while(q->next!=head)
		{
			q=q->next;
		}
		q->next=p;
		p->next=head;
		q=NULL;
	}
	p=NULL;
	
}
void insert_at_pos(int pos)
{
	if((pos < 1 ) || (pos > length()+1))
	{
		printf("Invalid Position");
		return;
	}
	if(pos==1)
		insert_beg();
	else if(pos==length()+1)
		insert_end();
	else
	{
	node *link1=(node *)malloc(sizeof(node));
	printf("Enter the data.\n");
	scanf("%d",&link1->data);
	link1->next=NULL;
	int ctr=1;
	node *p=head;
	while(ctr<pos-1)
	{
		p=p->next;
		ctr++;
	}
	link1->next=p->next;
	p->next=link1;
	}	
}
void delete_beg()
{
	if(head==NULL)
	{
		printf("Circular List is empty.\n");
		return;		
	}
	if(head->next==head)
		head=NULL;
	else
	{
		node *q=head;
		while(q->next!=head)
			q=q->next;
	
		q->next=head->next;
		head=head->next;
		q=NULL;
		free(q);
	}
	
}
void delete_end()
{
	if(head==NULL)
	{
		printf("Circular List is empty.\n");
		return;		
	}
	if(head->next==head)
		head=NULL;
	else
	{
		node *p=head,*q=head;
		while(p->next!=head)
		{
			q=p;
			p=p->next;
		}	
		q->next=head;
		q=NULL;
		p=NULL;
		free(p);
		free(q);
	}	
}
void delete_at_pos(int pos)
{
	if(pos<1 || pos>length())
	{
			printf("Invalid Position");
			return;
	}
	if(pos==1)
		delete_beg();
	else if(pos==length())
		delete_end();
	else
	{
		int ctr=1;
		node *p=head,*q=head;
		while(ctr<pos)
		{
			q=p;
			p=p->next;
			ctr++;
		}
		q->next=p->next;
		q=NULL;
		p=NULL;
		free(q);
		free(p);
	}	
}
int length()
{
	int ctr=0;
	node *p=head;
	while(p->next!=head)
	{
		ctr++;
		p=p->next;
	}
}
void display()
{
	if(head==NULL)
	{
		printf("The Circular List is empty.\n");
		return;
	}
	node *p=head;
	while(p->next!=head){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d ",p->data);
}

//The Main Function

void main()
{


	printf("\nEnter the choice\n");
	printf("1. Create Node\n");
	printf("2. Insert at Beginning\n");
	printf("3. Insert at End\n");
	printf("4. Insert at any Position\n");
	printf("5. Delete at  Beginning\n");
	printf("6. Delete at End\n");
	printf("7. Delete at any Position\n");
	printf("8. Display List\n");
	int ch;
	scanf("%d",&ch);
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:	printf("Enter the number of nodes you wish to create.\n");
				int i,n;
				scanf("%d",&n);
				for(i=1;i<=n;i++)
					create_node();
				break;
			case 2:insert_beg();
				break;
			case 3:insert_end();
				break;
			case 4:printf("\nEnter the position.");
			       int p;
			       scanf("%d",&p);
			       insert_at_pos(p);
			       break;
			case 5:delete_beg();
			       break;
			case 6:delete_end();
			       break;
			case 7:printf("\nEnter the position you want to delete");
			       int q;
			       scanf("%d",&q);
			       delete_at_pos(q);
		   	       break;    
			case 8:display();
			       break;		   
		}
	printf("\nEnter the choice\n");
	printf("1. Create Node\n");
	printf("2. Insert at Beginning\n");
	printf("3. Insert at End\n");
	printf("4. Insert at any Position\n");
	printf("5. Delete at  Beginning\n");
	printf("6. Delete at End\n");
	printf("7. Delete at any Position\n");
	printf("8. Display List\n");
	scanf("%d",&ch);
	}	
	getch();	
}
