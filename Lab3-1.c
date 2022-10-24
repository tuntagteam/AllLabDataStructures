#include<stdio.h>
#include<stdbool.h>
int tower[3][5] = {{0,4,3,2,1},{0,0,0,0,0},{0,0,0,0,0}};
int top[3] = {4,0,0};
int from , moveto , data;
void showstack(int a)
    {
        printf("Tower of #%d = \n" ,a);
        for(int i = 1; i<=4; i++)
            {
                printf("\t\t%d" ,tower[a][i]);
            }
        printf("\n");
    }
void push (int a , int data)
    {
        top[a] = top[a]+1;
        tower[a] [top[a]] = data;
    }
int pop(int a)
    {
        int x = tower[a] [top[a]];
        tower[a][top[a]] = 0;
        top[a] = top[a] - 1;
        return x;
    }
bool rule(int a, int aa)
    {
        if(top[a] > 0 && top[aa] <4)
            {
                return true;
            } else {
                return false;
            }
    }
    void return1()
    {
        return;
    }
int main()
{
    printf("Welcome to tower of hanoi ");
    for(;;)
    {
        showstack(0);
        showstack(1);
        showstack(2);
        printf("pop from >>> ");
        scanf("%d" ,&from);
        printf("Move to >>> ");
        scanf("%d" ,&moveto);
            if(rule(from , moveto) == true)
            {
                data = pop(from);
                push(moveto,data);
                data = 0;
            } else {
                printf("\nPlease try again\n");
                return1();
            }
    }
}