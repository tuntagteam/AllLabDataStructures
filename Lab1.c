#include<stdio.h>
#include<stdbool.h>
int main() 
{
    while(true) {
        int a,b,c,d,money;
        printf("Please Enter your emount for change coins\n");
        printf("(If you put 0 The program will shut off) = ");
        scanf("%d" ,&money);
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        if(money > 0)
        {
            if(money >= 10)
            {
                a = money/10;
                money = money - (a*10);
            }
            if(money >= 5 && money < 10)
            {
                b = money/5;
                money = money - (b*5);
            }
            if(money >= 2 && money < 5)
            {
                c = money/2;
                money = money - (c*2);
            }
            if(money == 1)
            {
                d = money/1;
                money = money - d;
            }
        }
        else 
            return 0;
        printf("your 10 coin : %d\n" ,a);
        printf("your 5 coin : %d\n" ,b);
        printf("your 2 coin : %d\n" ,c);
        printf("your 1 coin : %d\n" ,d);
    }
}