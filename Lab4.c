#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
char infix[100];

char s1[100];
int top1 = -1;

int s2[100];
int top2 = -1;

char q[100];
int f=-1;
int r=-1;

bool isFull1()
{
	if(top1==99){
		return true;
	}	
	return false;	
}
bool isFull2()
{
	if(top2==99){
		return true;
	}	
	return false;	
}

bool isEmpty1()
{
	if(top1==-1){
		return true;
	}
	return false;
}
bool isEmpty2()
{
	if(top2==-1){
		return true;
	}
	return false;
}

void push1(char data)
{
	if(isFull1()){
		return;
	}
	top1 = top1 + 1;
	s1[top1] = data;
}
void push2(char data)
{
	if(isFull2()){
		return;
	}
	top2 = top2 + 1;
	s2[top2] = data;
}

char peek1()
{
	if(isEmpty1()){
		return 'x';
	}
	return s1[top1];
}
int peek2()
{
	if(isEmpty2()){
		return 0;
	}
	return s2[top2];
}

char pop1()
{
	if(isEmpty1()){
		return 'x';
	}
	char data = s1[top1];
	top1 = top1 -1;
	return data;
}
int pop2()
{
	if(isEmpty2()){
		return 0;
	}
	char data = s2[top2];
	top2 = top2 -1;
	return data;
}
bool isFullq()
{
	if(r==99){
		return true;
	}
	return false;
}
bool isEmptyq()
{
	if(f==-1){
		return true;
	}
	return false;
}

void enqueue(char data)
{
	if (isFullq()){
		return;
	}
	if(f==-1){
		f=0;
	}
	r=r+1;
	q[r]=data;
}
char dequeue()
{
	if(isEmptyq()){
		return 'x';
	}
	char data = q[f];
	if(f==r){
		f=-1;
		r=-1;
	}
	else {
		f=f+1;
	}	
	return data ;
}

int chk(char data)
{
	switch(data){
		case '0': 
		case '1':
		case '2':	
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return 0;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':	
			return 1;
		case '(':
			return 2;	
		case ')':
			return 3;		
	return 4;		
	}
}

int prior(char data)
{
	switch(data){
		case '+':
		case '-':
			return 0;
		case '*':
		case '/':
			return 1;
		case '^':	
			return 2;
	}
	return 3;
}

void postfix()
{
	for(int i=0;i<strlen(infix);i++){
		switch(chk(infix[i])){
			case 0 :
				printf("%c",infix[i]);
				enqueue(infix[i]);
				break;
			case 1 : 
				for(;;){
					if (isEmpty1()){
						push1(infix[i]);
						break;
					}
					else if (peek1()=='('){
						push1(infix[i]);
						break;
					}
					else if (prior(peek1()) < prior(infix[i])){
						push1(infix[i]);
						break;
					}
					else{
						char data = pop1();
						printf("%c",data);
						enqueue(data);	
					}
				}	
				break;	
			case 2 : 
				push1(infix[i]);
				break;
			case 3 : 
				for(;;){
					char data = pop1();
					if(data == '('){
						break;
					}
					printf("%c",data);
					enqueue(data);
				}	
				break;
		} 
	}
	for(;;){
		if(isEmpty1()){
			break;
		}
		char data = pop1();
		printf("%c",data);
		enqueue(data);
	}
}

int convertnum(char data)
{
	switch(data){
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;		
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;							
	}
	return 0;
}
int power(int d1,int d2){
	int reseult=d1;
	int i;
	for(i=0;i<d2-1;i++)
		reseult*=d1;
		return reseult;
}

void resolve()
{
	for(;;){
		if(isEmptyq()){
			int data = pop2();
			printf("%d",data);
			break;
		}
		int data = dequeue();
		int datanum,d1,d2,dd;
		switch(chk(data)){
			case 0 : 
				datanum = convertnum(data);
				push2(datanum);
				break;
			case 1 :
				d2 = pop2();
				d1 = pop2();
				switch(data){
					case'+':
						dd = d1+d2;
						break;
					case'-':
						dd = d1-d2;
						break;
					case'*':
						dd = d1*d2;
						break;
					case'/':
						dd = d1/d2;
						break;	
					case'^':
						dd = power(d1,d2); 
						break;			
				}
				push2(dd);
				break;		
		}			
	}
}

int main()
{
	for(;;){
		printf("Infix > ");
		gets(infix);
		printf("Postfix > ");
		postfix();
		printf("\n");
		printf("Result > ");
		resolve();
		printf("\n\n");
	}
}