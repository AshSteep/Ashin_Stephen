#include <stdio.h>
#include <stdlib.h>
void atBeg(int);
void atEnd(int);
void aftrloc(int,int);
void dltbeg();
void dltend();
void dltloc(int);
void diplay();
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head,*temp,*prev;
void main()
{
int value,choice,loc;
    while(1)
    {
        printf("\n__Menu__\n");
        printf("1.Insert at beginning\n2.Insert at the end\n3.Insert after a value\n4.Delete From Begning\n5.Delete from End\n6.Delete a particular location\n7.Display\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item:");
                scanf("%d",&value);
            atBeg(value);
                break;
           case 2:printf("Enter the item:");
                scanf("%d",&value);
            atEnd(value);
                break;
            case 3:printf("Enter the value: \n");
                scanf("%d",&loc);
                printf("Enter the item: \n");
                scanf("%d",&value);
            aftrloc(value,loc);
                break;
            case 4:dltbeg();
                break;
            case 5:dltend();
                break;
            case 6:printf("\nEnter the location:");
                scanf("%d",&loc);
            dltloc(loc);
                break;
            case 7:display();
                break;
            default:printf("Opss! Wrong Selection! Try again.");
        }
    }
}
void atBeg(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->prev=NULL;
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        temp=head;
        head=newNode;
        newNode->next=temp;
        temp->prev=newNode;
        newNode->prev=NULL;
    }

}
void atEnd(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->prev=NULL;
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=NULL;
    }
}
void aftrloc(int value,int loc)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->prev=NULL;
    newNode->data = value;
    newNode->next=NULL;
    if(head == NULL)
    {
        printf("List Empty!!");
    }
    else if(temp->prev==NULL && temp->data==loc && temp->next==NULL)
    {
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
    }
    else
    {
        temp=head;
      while(temp->data != loc && temp->next!=NULL)
      {
    temp=temp->next;
      }
      if(temp->data==loc && temp->next==NULL)
      {
        newNode->next=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
      }
      else if(temp->data==loc && temp->next!=NULL)
      {
        newNode->next=temp->next;
        temp->next=newNode;
        temp->next->prev=newNode;
        newNode->prev=temp;
      }
      else
      {
         printf("Location not found!!");
      }
    }
}
void dltbeg(int loc)
{
    if(head==NULL)
    {
        printf("List is Empty!\n");
    }
    else if(temp->prev==NULL && temp->data==loc && temp->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        head=temp->next;
        temp->next=NULL;
    }
}
void dltend()
{
    if(head==NULL)
    {
        printf("List is Empty!\n");
    }
    else if(temp->prev==NULL && temp->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}
void dltloc(int loc)
{
   if(head==NULL)
    {
        printf("The list is Empty!!\n");
    }
    else if(temp->prev==NULL && temp->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        while(temp->data!=loc && temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void display()
{
        if(head==NULL)
        {
            printf("\nList is Empty!\n");
        }
        else
        {
            temp=head;
            printf("\nList elements are:\n");
            while(temp->next!=NULL)
                {
                    printf("%d-->",temp->data);
                    temp=temp->next;
                }
                    printf("%d--->NULL",temp->data);
        }
}
