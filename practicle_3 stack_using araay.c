#include<stdio.h>

int stack[100];
int choice,i,top = -1,x,n;
void push() {
	if(top >= n - 1)
	{
		printf("\t the stack is overflow\n");
	}
	
	else
	{
		printf("enter stack\n");
		scanf("%d",&x);
		top++;
		stack[top] = x;
	}
}

void pop() 
    {
	if(top < 0){
		printf("stack is underflow\n");
	}
	
	else{
		printf("the poped stack is=%d\n",stack[top]);
		top--;
	}
}

void display() 
    {
	if(top >= 0) {
		for(i=top;i>=0;i--){
			printf("the stack value = %d \n",stack[i]);
		}
	}
	
	else{
		printf("the stack is empty \n");
	}
}

void peep()
{
    if (top >= 0)
    {
        printf("\n The top element in STACK is: %d", stack[top]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}

void change()
{
    int pos, newValue;
    
    printf("Enter the position (0 to %d) of the element you want to change: ", top);
    scanf("%d", &pos);

    if (pos >= 0 && pos <= top)
    {
        printf("Enter the new value: ");
        scanf("%d", &newValue);
        
        stack[pos] = newValue;
        printf("Element at position %d changed to %d\n", pos, newValue);
    }
    else
    {
        printf("Invalid position\n");
    }
}
int main()
    {
	printf("\t*****stack*****\n");
	printf("enter the value of stack[1-100]:");
	scanf("%d",&n);

	printf("\t(1)push\n\t(2)pop\n\t(3)display\n\t(4)peep\n\t(5)change\n\t(6)exit\n\t");
	
	do{
	printf("chose any one[1-6]:");
	scanf("%d",&choice);
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
			peep();
			break;
			
			case 5:
			change();
			break;
			
			case 6:
			printf("stack is exit\n");
			break;
			
			default:
			printf("pleas enter valid choice\n");
			
		}
	}while(choice != 6);
	return 0;
}


