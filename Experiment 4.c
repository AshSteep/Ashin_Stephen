#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*ptr;

int push();
int pop();
int peek();
int display();
int main()
{
    int choice;
    while(1)
    {
        printf("\n Menu \n");
        printf(" 1.PUSH \n 2.POP \n 3.PEAK \n 4.DISPLAY \n 5.EXIT\n");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            exit(0);
            break;
            default: printf("Invalid choice");
        }
    }
}
int push()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));
    if(ptr == NULL)
    {
        printf("invalid\n");
    }
    else
    {
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\n Node inserted \n");
    }
}
int pop()
{
     struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning ...\n");
    }
}
int peek()
{
    int data;
    struct node *ptr;


    if(head==NULL)
    {
        printf("the stack is empty");
        return 0;
    }
    else
    {
        ptr=(head->data);
    }
    printf("the peek value is:%d",ptr);
}

int display()
{
     ptr = head;
    if(ptr == NULL)
    {
        printf("\n Nothing to print \n");
    }
    else
    {
        printf("\n printing values . . . . .\n");
        while (ptr->next!=NULL)
        {
            printf("%d",ptr->data);
            ptr = ptr -> next;
        }
         printf("%d->NULL",ptr->data);

    }
}
