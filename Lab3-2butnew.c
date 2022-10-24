#include<stdio.h>
#include<stdbool.h>
int rear , front , number;
unsigned data;
int s[11];

void circular_queue()
{
    for(int i = 1; i <= 10; i++) {
        printf(" %d", s[i]);
    } printf("\n");
}
void FandRchecker()
{
    printf("\nFront : %d" ,front);
    printf("\nRear : %d" ,rear);
}
bool isempty()
{
    if(s[rear] == 0)
        return true;
    else
        return false;
}
bool isfull()
{
    if(s[front] > 0)
        return true;
    else
        return false;
}
void data_push()
{
    printf("What's a data you want to push in? :");
    scanf("%d",&s[rear]);
}
void data_pull()
{
    s[front] = 0;
    front++;
}

int main()
{
    int choice, strdata;
    printf("\n");
    circular_queue();
    FandRchecker();
    printf("\nPlease enter your number of channel you want to store data in :");
    scanf("%d" ,&number);
    printf("\nEnter your data :");
    scanf("%d" ,&strdata);
    s[number] = strdata;
    rear = number;
    front = number;
    rear ++;
    for(;;) {
        circular_queue();
        FandRchecker();
        printf("\nPlease Choose your Operation");
        printf("\n----------------------------------\n");
        printf("\n1.Push in Value");
        printf("\n2.Pull out Value");
        printf("\nEnter your choice here :");
        scanf("%d" ,&choice);

        switch(choice)
        {
            case 1 : if(isempty()) {
                data_push();
                rear++;
            } else {
                printf("Is full. Please try again.");
                return 1;
            } break;

            case 2 : if(isfull()) {
                data_pull(front);
            } else {
                printf("\nIs empty. Please try again.");
                return 1;
            } break;
        default:
        printf("\nPlease try again.");
        }
    if(rear > 10) {
        rear = 1;
    } if (front > 10) {
        front = 1;
    }
    }
}