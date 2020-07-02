#include<stdio.h>
int LEAP(int y)
{
    int R;
    if((y%4==0&&y%100!=0)||(y%400==0))
    R=29;
    else
    R=28;
    return (R);
}
int DAYS(int m,int y)
{
    int R;
    R=((m==1||m==3||m==5||m==7||m==8||m==10||m==12)?31:(m==4||m==6||m==9||m==11)?30:m==2?LEAP(y):0);
    return (R);
}
int CALD(int d,int m,int y)
{
    int A,B,S,C,P,R;
    A=(((y-1)%100)*5/4)%7;
    B=((y-1)-(y-1)%100)%4;
    B=(B==0?0:B==100?5:B==200?3:B==300?1:B==400?0:1);
    S=(m==1?0:m==2?3:m==3?3:m==4?6:m==5?1:m==6?4:m==7?6:m==8?2:m==9?5:m==10?0:m==11?3:m==12?5:1);
    C=d%7;
    printf("%d %d %d \n",A,B,C);
    R=LEAP(y);
       if(R==29)
        {
            P=A+B+S+C;
            P=P%7;
            if(m>2)
            P=(P+1)%7;
            else
            P=P;
        }
    else
        {
            P=A+B+S+C;
            P=P%7;
        }
        if(y<=2000)
            P=(P+1)%7;
        return (P);

}
int main()
{
    int CALD(int d,int m,int y);
    int DAYS(int m,int y);
    int LEAP(int y);
    int d,m,y,A,B,C,R,S,choice,i,j,n=1;
    printf("Enter your choice:\n1.Day on any Date\n2.Month of year\n\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("\nEnter date(dd/mm/yyyy):");
            scanf("%d/%d/%d",&d,&m,&y);
            R=LEAP(y);
            if((R==29&&m==2&&d>29)||(R==28&&m==2&&d>28)||(d>31||d<1||m<1||m>12))
            goto wrong;
            int P=CALD(d,m,y);
            (P==0?printf("\nSunday"):P==1?printf("\nMonday"):P==2?printf("\nTuesday"):P==3?printf("\nWednesday"):P==4?printf("\nThursday"):P==5?printf("\nFriday"):P==6?printf("\nSaturday"):printf("\nMistake"));
                break;
        }
        case 2:
        {
            printf("Enter month and year(mm/yyyy):");
            scanf("%d/%d",&m,&y);
            if(m>12)
            goto wrong;
            d=1;
            int R=DAYS(m,y);
            int P=CALD(d,m,y);
            printf("S  M  T  W  T  F  S \n");
            for(i=1;i<=1;i++)
            {
                for(j=0;j<P;j++)
                {
                    printf("   ");
                }
                for(j=P;j<=6;j++)
                {
                    printf("%d  ",n);
                    n++;
                }
            }
            printf("\n");
            for(i=2;i<=6;i++)
            {
                for(j=0;j<=6;j++)
                {
                    {if(n<10)
                    printf("%d  ",n);
                    else
                    printf("%d ",n);}
                    n++;
                    if(n>R)
                    goto label;
                }
                printf("\n");
            }
        }
            wrong:
            printf("\nSomething wrong\n");
            label:
            break;
            default :
            printf("\nInvalid option\n");
            break;
    }
}

