#include<stdio.h>
#define M 20

int main()
{
    int s1[M], s2[M];
    int top1=-1, top2=-1;
    int ch, i;
    
while(1)
{
    printf("Enter your choice:\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Exit\n>>");
    scanf("%d", &ch);

    switch(ch)
    {
    case 1://inserting .
        if(top1==M-1)
        {
            printf("\tQueue is full. Cannot insert!\n\n");
        }
        else
        {
            top1++;
            printf("\nEnter element:");
            int val;
            scanf("%d", &val);
            s1[top1]=val;
        }
    break;

    case 2://deleting.
        if(top1==-1)
        {
            printf("\tQueue is Empty. Nothing to delete!\n\n");
        }
        else 
        {
            while(top1>0)
            {
                top2++;
                s2[top2]=s1[top1];
                top1--;
            }
            printf("\n\tDeleted element is: %d\n\n", s1[top1]);
            top1--;

            while(top2>=0)
            {
                top1++;
                s1[top1]=s2[top2];
                top2--;
            }
        }
    break;

    case 3://displaying.
        if(top1==-1)
        {
        printf("\tQueue is Empty. Nothing to Display!\n");
        }
        else
        {
            printf("\nElements in the queue are:");

            for(i=0; i<=top1; i++)
            {
                printf(" %d >>",s1[i]);
            }
        }
        printf("\n\n");
    break;

    case 4://Exiting

        printf("\nExited the program.");
        return 0;
    break;

    default:

        printf("\nInvalid choice! Try Again.\n");
    break;
    }
}
}