#include<stdint.h>
#include<stdlib.h>

int setunion();
int intersection();
int difference();
int equality();
int main()
{
    int choice;
    while(1)
    {
        printf("\n \n Menu \n");
        printf(" 1.Find the Union \n 2.Find the Intersection \n 3.Find the Difference \n 4.Check the Equality \n");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            setunion();
            break;
            case 2:
            intersection();
            break;
            case 3:
            difference();
            break;
            case 4:
            equality();
            break;
            default: printf("Invalid choice");
        }
    }

}

int setunion()
{
    int s[10],s1[5],s2[5],i,n,m;
    printf("\n Enter the size of first set:");
    scanf("%d",&n);
    printf("\n Enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size of second set :");
    scanf("%d",&m);
    printf("enter the array elements:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find union");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            s[i]=s1[i]||s2[i];
        }
        printf("union is:");
        for(i=0;i<n;i++)
        {
          printf("%d",s[i]);
        }
    }
}
int intersection()
{
    int s[50],s1[20],s2[20],i,n,m;
    printf("Enter the size of first set:");
    scanf("%d",&n);
    printf("enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size of second set:");
    scanf("%d",&m);
    printf("enter the array elements:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find intersection");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            s[i]=s1[i] && s2[i];
        }
        printf("intersection is:");
        for(i=0;i<n;i++)
        {
          printf("%d",s[i]);
        }
    }
}

int difference()
{
    int s[50],s1[20],s2[20],i,n,m;
    printf("Enter the size of first set:");
    scanf("%d",&n);
    printf("enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size of second set:");
    scanf("%d",&m);
    printf("enter the array elements:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find Difference");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            s2[i]=!s2[i];
        }
        for(i=0;i<n;i++)
        {
            s[i]=s1[i] && s2[i];
        }
        printf("Difference is:");
        for(i=0;i<n;i++)
        {
          printf("%d",s[i]);
        }
    }
}
int equality()
{
    int s[50],s1[20],s2[20],i,n,m;
    printf("Enter the size of first set:");
    scanf("%d",&n);
    printf("enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s1[i]);
    }
    printf("Enter the size of second set:");
    scanf("%d",&m);
    printf("enter the array elements:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&s2[i]);
    }
    if(n!=m)
    {
        printf("We cannot find Equality");
    }
    else
    {
        int count=0;
        for(i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                count=1;
            }
        }
        if(count==1)
            printf("These two sets are not equal");
        else
            printf("Two sets are equal");
    }
}
