#include<stdio.h>
#include<stdlib.h>

typedef struct list
{  
    int data;
    struct list *next;

}*SLL;

SLL getnode()
{
    SLL new;
    new=malloc(sizeof (struct list));
    new->next=NULL;
    return new;
}

int main()
{
    SLL head, temp, t1;
    int val, ch;
    char cont;

    head=NULL;

    while(1)
    {
        printf("Enter your choice:\n\t1.Enter bill amount\n\t2.Display all bills for the day\n\t3.Delete the last bill\n\t4.Exit\n>>");
        scanf("%d", &ch);

    switch(ch)
    {

    case 1:
        do{
        
        if(head==NULL)
        {
            head=getnode();
            printf("Enter the amount:");
            scanf("%d", &val);
            head->data=val;
            t1=head;
            printf("First Bill of the day is Rs.%d\n", head->data);
        }
        
        else
        {
            temp=getnode();
            printf("Enter the amount:");
            scanf("%d", &val);
            temp->data=val;
            t1->next=temp;
            t1=temp;
        }
        printf("Type 'Y' to continue.\n\t>>");
        scanf(" %c", &cont);

    } while(cont=='Y' || cont=='y');
    break;

    case 2:
        if(head==NULL)
        {
            printf("No bills found.");
        }
        else
        {
            temp=head;
            printf("\nBills for the day are:");

            while(temp!=NULL)
            {
                printf("\n\t\tRs.%d", temp->data);
                temp=temp->next;
            }
        }
        printf("\n\n");
    break;

    case 3:
        if (head==NULL)
        {
            printf("No bills to delete.\n\n");
        }
        else if (head->next==NULL)
        {
            printf("Deleted last bill of Rs.%d\n\n", head->data);
            free(head);
            head=NULL;
        }
        else
        {
            temp=head;

            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            printf("Deleted last bill of Rs.%d\n\n", temp->next->data);
            free(temp->next);
            temp->next=NULL;
        }
    break;

    case 4: exit(0);

    default: printf("Invalid choice! Try again.\n");
    }

    }

}