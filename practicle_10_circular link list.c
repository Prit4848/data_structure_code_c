#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node*next;
};
struct node*last=NULL;
void insertatend(int data){
	struct node*ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	
	if(last == NULL){
		ptr->info=data;
		ptr->next=ptr;
		last=ptr;
	}	
	
	else{
		ptr->info=data;
		ptr->next=last->next;
		last=ptr;
	}
	printf("inserted value....!\n");
}

void insertbeforenode(int position,int data){
	struct node*ptr,*temp;
	int i;
	ptr=(struct node*)malloc(sizeof(struct node));
	temp=last->next;
	if(temp == NULL){
		printf("list is empty....!");
		return;
	}
	for(i=1;i<position;i++){
		temp=temp->next;
		if(temp == last->next){
			printf("invalid position to insert before \n");
			return;
		}
	}
      ptr->info=data;
      ptr->next=temp->next;
      temp->next=ptr;
      printf("insert valid %d before node at position %d \n",data,position);
}

void deletefirstnode(){
	struct node*ptr;
	if(last == NULL){
		printf("\n list is empty.....!");
	}
	else{
		ptr=last->next;
		last->next=ptr->next;
		free(ptr);
	}
	printf("delete fist_node.....!");
}

void deleteafterspecific(position){
         struct node*ptr,*temp;
         temp=last->next;
         int i;
         if(last == NULL){
         	printf("list is empty");
         	return;
		 }
         for(i=1;i<position;i++){
         	temp=temp->next;
         	if(temp == last->next){
         		printf("invalid position to delete after \n");
         		return;
			 }
		 }       
	ptr=temp->next;
	temp->next=ptr->next;
	free(ptr);
	printf("delete node after position %d \n",position);
}

int display(){
	struct node*temp;
	temp=last != NULL ? last->next : NULL;
	
	if(temp == NULL){
		printf("list is empty...\n");
		return 0;
	}
	printf("circular link list.");
	do{
		printf("%d->",temp->info);
		temp=temp->next;
	}while(temp != last->next);
	printf("\n");
	
     return 0;
}

int main(){
	int choice,position,data;
	
	printf("___circular link list___");
	
	    printf("\n");
	    printf("1. Insert a node at the end of the linked list.\n");
        printf("2.Insert a node before specified position\n");
        printf("3.Delete a first node of the linked list. \n");
        printf("4.Delete a node after specified position. \n");
        printf("5.display\n");
        printf("6.exit\n");
    do{ printf("\n");
	    printf("choice abow any one:");
        scanf("%d",&choice);
       
        
        switch(choice){
        	case 1:
        		printf("enter the value you have insert:");
        		scanf("%d",&data);
        		insertatend(data);
        		break;
        		
        	case 2:
        		printf("enter node position:");
        		scanf("%d",&position);
        		printf("enter the data you have insert:");
        		scanf("%d",&data);
        		insertbeforenode(position,data);
        		break;
        		
        	case 3:
        		 deletefirstnode();
        		 break;
        		 
        	case 4:
        		printf("enter the node position:");
        		scanf("%d",&position);
        		deleteafterspecific(position);
        		break;
        		
        	case 5:
        		display();
        		break;
			     	
        	case 6:
        		printf("exit....!");
        		break;
        		
        	default:
        		printf("you have an invalid choice plase enter valid choice....!");
        		break;	
		}
        
	}while(choice != 6);
	return 0;
}
