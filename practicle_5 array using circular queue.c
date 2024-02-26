#include<stdio.h>
int max,x,i;
int front=-1,rear=-1;
int queue[100];
// enqueue operation 
void insert(int x){
	if((front == 0 && rear == max-1)||(front == rear+1)){
		printf("the queue is over flow\n");
	}
	else{
	if(front == -1 && rear == -1){
		front=0;
		rear=0;
	}
	else if(rear == max-1 && front != 0){
		rear = 0;
	}
	else{
		rear = rear+1;	
	}	
	queue[rear]=x;
	printf("the value %d is inserted... ",x);
}
}
// dequeue operation
void delete_2(){
if(front == -1){
		printf(" queue is underflow...");
	}
else{
	x=queue[front];
	if(front == rear){
		front=rear=-1;
	}
	else if(front == max-1){
		front=0;
	}
	else{
		front=front+1;
	}
	printf("the value %d is deleted",x);
}
}
void display(){
  int i;
  if (front == -1) {
    printf("\nThe Circular Queue is Empty ! Nothing To Display !!\n");
    return;
  }
  printf("the circular queue element was:");
  i = front;
  if (front <= rear) {
    printf("\n\n");
    while (i <= rear)
      printf("%d| ", queue[i++]);
    printf("\n");
  } else {
    printf("\n");
    while (i <= max - 1)
      printf("%d| ", queue[i++]);
    i = 0;
    while (i <= rear)
      printf("%d| ", queue[i++]);
    printf("\n");
  }
}

int main(){
	printf("____Circular Queue USING ARRAY____\n");
	printf("enter the size[1-100] of queue:");
	scanf("%d",&queue[max]);
	printf(" 1. INSERT\n 2. DELETE\n 3. DISPLAY\n 4. EXIT\n");
	int choice;
	while(choice != 4){
		printf("\n");
		printf("choice any one operation:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("enter queue:");
	            scanf("%d",&x);
				insert(x);
				break;
				
			case 2:
				delete_2();
				break;
			
			case 3:
				display();
				break;
				
			case 4:
				printf("queue is exit..");
				break;
				
			default:
				printf("invalid choice you choice...!");
				break;
				
		}
	}
	return 0;
}
