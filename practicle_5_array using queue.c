#include<stdio.h>
int max,choice,x,i;
int front = -1,rear = -1;
int queue[100];
void insert();
int delete_1();
void display();

void insert(){ 
           if(rear == max-1){
          	printf("stack is over flow \n");
                                }       
           else{
                  if(front == -1){
        	         front=rear=0;	}
		         else 
	               rear=rear+1;
	                printf("enter queue:");
	                scanf("%d",&x); 
                 	}
                   queue[rear]=x;
		printf(" %d was inserted\n",x);	
                      }     
int delete_1(){  
           if(front == -1){
           	printf("the queue is over flow");
           }
           else {
		   x = queue[front];
		    if (front == max - 1)
                   front = 0;
            else if (front == rear) {
                  front = -1;
                   rear = -1;
           } else front = front + 1;
             printf("\n%d was deleted !\n", x);
             return x;  }	 return 0; 	
}
void display() {
 if(front == -1){
 	printf("queue is empty NOthing display.\n");
 }
 
 else{
 	printf("queue elements:");
 	for(i = front;i <= rear;i++){
 		printf("%d|",queue[i]);
	 }
	 printf("\n");
    }
}

int main(){
	printf("____ Queue USING ARRAY____\n");
	printf(" enter the value of queue [1-100]:");
	scanf("%d",&max);
	
	printf("\t (1)insert \n \t (2)delete \n \t (3)display \n \t (4)exit \n");
	
do{
	printf(" enter the value of your  choice [1-4]:");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			insert();
			break;
		case 2:
			delete_1();
			break;
			
		case 3:
			display();
			break;
			
		case 4:
			printf("queue is exit");
			break;
			
		default:
			printf("invalid user choice \n");
	}
}while(choice != 4); 
return 0;
}
