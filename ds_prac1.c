#include<stdio.h>
#include<stdlib.h>
#define M 20

int main()
{
    char s1[M], s2[M];
    int t1 = -1, t2 = -1;
    int ch;
    char val;

    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1.Insert\n2.Delete\n3.Undo\n4.Redo\n5.Exit\n>>");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                if(t1 == M-1)
                {
                    printf("Cannot insert. Stack is full.\n");
                }
                else
                {
                    printf("Enter Element: ");
                    scanf(" %c", &val);
                    t1++;
                    s1[t1] = val;
                    printf("%c inserted.\n", val);
                }

                if(t1 == -1)
                {
                    printf("Stack is empty.\n");
                }
                else
                {
                    printf("Current stack: ");
                    for(int i = 0; i <= t1; i++)
                    {
                        printf("%c ", s1[i]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                if(t1 == -1)
                {
                    printf("Cannot delete. Stack empty.\n");
                }
                else
                {
                    printf("%c is   deleted.\n", s1[t1]);
                    t2++;
                    s2[t2] = s1[t1];
                    t1--;
                }

                if(t1 == -1)
                {
                    printf("Stack is empty.\n");
                }
                else
                {
                    printf("Current stack: ");
                    for(int i = 0; i <= t1; i++)
                    {
                        printf("%c ", s1[i]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                if(t1 == -1)
                {
                    printf("Nothing to undo.\n");
                }
                else
                {
                    printf("Undo: %c\n", s1[t1]);
                    t2++;
                    s2[t2] = s1[t1];
                    t1--;
                }

                if(t1 == -1)
                {
                    printf("Stack is empty.\n");
                }
                else
                {
                    printf("Current stack: ");
                    for(int i = 0; i <= t1; i++)
                    {
                        printf("%c ", s1[i]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                if(t2 == -1)
                {
                    printf("Nothing to redo.\n");
                }
                else
                {
                    printf("Redo: %c\n", s2[t2]);
                    t1++;
                    s1[t1] = s2[t2];
                    t2--;
                }

                if(t1 == -1)
                {
                    printf("Stack is empty.\n");
                }
                else
                {
                    printf("Current stack: ");
                    for(int i = 0; i <= t1; i++)
                    {
                        printf("%c ", s1[i]);
                    }
                    printf("\n");
                }
                break;

            case 5: 
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
