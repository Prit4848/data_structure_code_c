#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};
struct node*head;
struct node*front=NULL;
struct node*rear=NULL;
void insert(){
	int item,data;
	struct node*ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("the queue is overflow\n");
		return;
	}
	
	else{
		printf("enter value:");
		scanf("%d",&item);
		ptr->data=item;
		
		if(front == NULL){
			front=ptr;
			rear=ptr;
			front->next=NULL;
			rear->next=NULL;	
		}
		
		else{
			rear->next=ptr;
			rear=ptr;
			rear->next=NULL;
		}
		
	}
	
}

void delete(){
	struct node*ptr;
	if(front == NULL){
		printf("the queue is underflow....\n");
		return;
	}
	
	else{
	ptr=front;
	front=front->next;
	free(ptr);	
	}
	
}

void display(){
	struct node*ptr;
	ptr=front;
	if(ptr == NULL){
		printf("empty queue....\n");
	}
	else{
		printf("the queue are:");
		
		while(ptr != NULL){
			printf("%d|",ptr->data);
			ptr=ptr->next;
		}
	}
}

int main(){
	int choice=0;
	printf("\t___QUEUE USING LINK LIST___\n");
	

		printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
	while(choice != 4){	
	    printf("\n");	
		printf("choice any one operation:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("exiting the operation.....\n");
				break;
			default:
				printf("invalid choice....\n");
				break;
		}
	}
	return 0;
}
