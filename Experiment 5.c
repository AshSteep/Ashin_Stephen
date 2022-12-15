#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int a[];
int Rear = -1;
int Front = -1;
void main()
{
    int choice,size[3];

    while(choice!=4)
    {
        printf("\n*****MENU*****\n \n 1.enQueue \n \n 2.deQueue \n \n 3.display \n \n 4.exit \n");
        printf("\n enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("invalid choice");
        }
    }
}


void enqueue()
{
    int value;
    printf("\n Enter the elements: \n");
    scanf("%d",&value);

    if((Rear+1)%3==Front)
    {
        printf("the queue is full");
    }
        else if(Front==-1 && Rear==-1)
        {
            Front=0;
            Rear=0;
            a[Rear]=value;
        }
        else
        {
            Rear=(Rear+1)%3;
            a[Rear]=value;
            printf("\n the elemenet is inserted");
        }
}
void dequeue()
{
    if (Front ==-1)
    {
        printf("Empty queue");

    }
    else if(Front=Rear)
    {

        Front =-1;
        Rear=-1;
    }
    else
    {
        Front=(Front+1)%3;
    }
    printf("the element is deleted");

}
void display()
{
    int i=Front;
    if(Front ==-1 && Rear ==-1)
    {
        printf("\n the queue is empty \n");
    }
    else
       printf("\n the elements are: ");
       while(i<=Rear)
       {
           printf("%d\t",a[i]);
           i++;
        }
}
