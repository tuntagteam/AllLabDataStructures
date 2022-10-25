#include<stdio.h>
#include<stdbool.h>

int cqarr [10];
int front,rear;

void showdata(){
	printf("\n");
	for(int i=0;i<10;i++){
		printf(" %d",cqarr[i]);
	}
	printf("\nFront = %d",front + 1);
	printf("\nRear  = %d",rear + 1);
	printf("\n\n");
}

void showmenu(){
	printf("Circular Queue program\n");
	printf("1.Push in value\n");
	printf("2.Pull out value\n");
	printf("3. Exit\n");
	printf("Enter command > ");
}

bool isfull(){
	if(((front==0)&&(rear==9))||(front==rear+1)){
		return true;
	}
	else{
		return false;
	}
}

bool isempty(){
	if (rear==-1){
		return true;
	}
	else {
		return false;
	}
}

void enqu(int a){
	if(isfull()){
		printf("\n*Queue is full*\n");
		return;
	}
	else if(isempty()){
		front=0;
		rear=0;
	}
	else if(rear==9){
		rear=0;
	}
	else{
		rear=rear+1;
	}
	cqarr[rear] = a;
}

void dequ(){
	if (isempty()){
		printf("\n*Queue is empty*\n");	
	}
	else {
		cqarr[front]=0;
		if (front==rear){
			front=-1;
			rear=-1;
		}
		else if (front==9){
			front=0;
		}
		else{
			front+=1;
		}
	}
	
}

int main(){
	int ansUser;
	front=-1;
	rear=-1;
	for(int i=0;i<10;i++){
			cqarr[i]=0;
		}
	while(true){
		showdata();
		showmenu();
		scanf("%d",&ansUser);
		if (ansUser==1){
			int data;
			printf("Enter you data > ");
			scanf("%d",&data);
			enqu(data);
		}
		else if (ansUser==2){
				dequ();
		}
		else if (ansUser==3){
				printf("\nExit\n");
				return 0;	
		}
		else{
			printf("\n----Error----\n");
		}	
	}	
}
