#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};
struct node*head;
void push(){ int data;
        struct node*ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        
        if(ptr == NULL){
        	printf("a stack is full...\n");
		}
		
		else{
			printf("enter the data you are store:");
			scanf("%d",&data);
			
			if(head == NULL){
				ptr->data=data;
				ptr->next=NULL;
				head=ptr;
			}
			
			else{
				ptr->data=data;
				ptr->next=head;
				head=ptr;
			}
	          printf("item is pushed......\n\n");	}
      
  
};
void pop(){
        struct node*ptr;
        int item;
        
        if(head == NULL){
        	printf("underflow.....\n");
		}
		
		else{
			item=head->data;
			ptr=head;
			head=head->next;
			free(ptr);
			printf("item_popped....\n");
		}
};
void display(){
	struct node*ptr;
	ptr=head;
	
	if(head == NULL){
		printf("THE STACK IS EMPTY....\n");
	}
	
	else{
		printf("PRINTING THE STACK ALEMENT....\n");
		
		while(ptr != NULL){
			printf("\t|%d|\n",ptr->data);
			ptr=ptr->next;
		}
	}
};

int main(){    int choice=0;
       printf("\t____STACK USING LINK LIST____\n");
       
      
       	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n"); 
while(choice != 4){
       	printf(" enter the operation you can choice: ");
       	scanf("%d",&choice);
       	printf("\n");
       	switch(choice){
       		case 1:
       			push();
       			break;
       				
       		case 2:
       			pop();
       			break;
       			
       		case 3:
       			display();
       			break;
       			
       		case 4:
       			printf("existing....\n");
       			break;
       			
       		default:
       			printf("plese enter the valid choice\n");
       			
       			
		   }
	   }
	
}
