#include<stdio.h>
#include<stdbool.h>
int rear , front , number;
unsigned data;
int s[11];

void circular_queue()
{
    for(int i = 1; i<=10; i++)
        {
            printf("  %d" ,s[i]);
        }
        printf("\n");
} void FandRchecker() {
    printf("\nFront = %d" ,front);
    printf("\nRear = %d" ,rear);
} bool isempty() {
    if(s[rear] == 0)
        return true;
    else return false;
} bool isfull() {
    if(s[front] > 0)
        return true;
    else   
        return false;
} void data_push() {
    printf("What a data do you want to push in ");
    scanf("%d" ,&s[rear]);
} void data_pull() {
    s[front] = 0;
    front++;
} void return1() {
    return;
} int main() {
    int choice , strdata;
    circular_queue();
    printf("\nFront = %d" ,front);
    printf("\nRear = %d" ,rear);
    printf("\nPlease enter your number of channel do you want to store data");
    scanf("%d" ,&number);
    printf("\nPlease Enter your data");
    scanf("%d" ,&strdata);
    s[number] = strdata;
    rear = number;
    front = number;
    rear ++;
    for(;;) {
        circular_queue();
        FandRchecker();
        printf("\nPlease choose your operation");
        printf("\n1. Push in Value");
        printf("\n2. Pull out Value");
        printf("\n3. Close program");
        scanf("%d" ,&choice);

        switch(choice)
            {
                case 1 :
                    if(isempty()) {
                        data_push();
                        rear++;
                    } else {
                        printf("Is Full please Try again ");
                        return1();
                    }
                break;

                case 2 :
                    if(isfull()) {
                        data_pull();
                    } else {
                        printf("\nIs Empty please Try again ");
                        return1();
                    }
                break;

            default :
                printf("\nPlease Try Again ");
            }
    if (rear > 10) {
        rear = 1;
    } if (front > 10) {
        front = 1;
    }
    }
}