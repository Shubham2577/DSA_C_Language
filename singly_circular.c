#include<stdio.h>
#include<stdlib.h>
#define Memory (struct node*)malloc(sizeof(struct node));
typedef struct node
{
	int data;
	struct node *next;

}Node;

	Node *create(Node *list)
	{
		Node *newnode,*temp;
		int i,n;
		printf("\nenter limit::");
		scanf("%d",&n);
	for(i=0; i<n; i++)
	{
	newnode=Memory;
	printf("enter value::");
	scanf("%d",&newnode->data);
	if(list==NULL)
	{
	  temp=newnode;
	  list=newnode;	
	   newnode->next=list;
	}
	else
	{
	  temp->next=newnode;
	  temp=newnode;
	  newnode->next=list;
	}
	
	}
	  return list;
	}
	
	void display(Node *list)
	{
	    Node *temp=list;
	    do{
	       printf("%d\t",temp->data);
	         temp=temp->next;
	      }while(temp!=list);
	}
	
	
	
	Node *insertbeg(Node *list,int num)
	{
		Node *newnode,*temp;
		newnode=Memory;
		newnode->data=num;
		for(temp=list; temp->next!=list; temp=temp->next);
		newnode->next=list;
		list=newnode;
		temp->next=list;
	return list;	
	}
	
	Node *insertmid(Node *list,int num,int pos)
	{
		Node *newnode,*temp;
		int i;
		newnode=Memory;
		newnode->data=num;
		for(i=1,temp=list; temp->next!=list && i<pos-1; i++,temp=temp->next);
		newnode->next=temp->next;
		temp->next=newnode;
	return list;
	}
	
	Node *insertend(Node *list,int num)
	{
	   Node *temp,*newnode;
	   newnode=Memory;
	   newnode->data=num;
	   for(temp=list; temp->next!=list; temp=temp->next);
	    newnode->next=list;
	    temp->next=newnode;  
	return list;
	}
		
	int main()
	{
	Node *list=NULL;
	int ch,num,pos;
	do{
             printf("\n 1=create:: \n2=display:: \n 3=insertbeg:: \n 4=insertmid:: \n 5=insertend::");
             printf("\n enter choice::");
             scanf("%d",&ch);
             switch(ch)
             {
             case 1: list=create(list);
             		break;
             		
             case 2: display(list);
             		break;
             		
             case 3: printf("enter number::");
             	     scanf("%d",&num);
             	    list=insertbeg(list,num);
             	     break;
             	     
             case 4: printf("enter number::");
             	     scanf("%d",&num);
             	     printf("enter position:");
             	     scanf("%d",&pos);
             	    list=insertmid(list,num,pos);
             	     break;

	     case 5: printf("enter number::");
          	     scanf("%d",&num);
                list=insertend(list,num);
		break;
         
             default: printf("\n invalid choice::");
             }	
	
	}while(ch<=5);
	
	}
    