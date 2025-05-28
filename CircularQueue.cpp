#include<stdio.h>
#define Size 7
int CQ[Size],F=-1,R=-1;
void C_Enqueue();
void C_Dequeue();
void C_Display();
void Count();
void Front();
void Rear();
int main()
{
    int choice;
    while(1)
    {
        printf("For Enqueue enter 1\nFor Dequeue enter 2\nFor Display enter 3\n"
               "For Count enter 4\nFor Front Element enter 5\nFor Rear Element enter 6\n"
               "7 For Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                C_Enqueue();
                break;
            case 2:
                C_Dequeue();
                break;
            case 3:
                C_Display();
                break;
            case 4:
                Count();
                break;
            case 5:
                Front();
                break;
            case 6:
                Rear();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}
void C_Enqueue()
{
    int el;
    if((R+1)%Size==F)
    printf("Queue is FUll!!!!!\n");
    else
    {
        printf("Enter element\n");
        scanf("%d",&el);
        if(F==-1 || R==-1)
        {
            F=0;
            R=0;
            CQ[R]=el;
        }
        else
        {
        R   =(R+1)%Size;  
        CQ[R]=el;
        }
    
    printf("Element %d enqueued.\n", el);
    }
}
void C_Dequeue()
{
    if (F == -1 || R == -1) 
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d element deleted\n", CQ[F]); 
        if (F == R) 
        {
            F = R = -1; 
        }
        else
        {
            F = (F + 1) % Size; 
        }
    }
}
void C_Display()
{
    if(F == -1 || R==-1)
    printf("Queue is empty\n");
    else
    {
        if(F<=R)
        {
        printf("Elements are:\n");
        for(int i=F;i<=R;i++)
        {
            printf("CQ[%d] = %d\n",i,CQ[i]);
        }
        }
        else
        {
            for(int i=F;i<=Size-1;i++) 
            {
                printf("CQ[%d] = %d\n",i,CQ[i]);
            }
            for(int i=0;i<=R;i++)
            {
                printf("CQ[%d] = %d\n",i,CQ[i]);
            }
        }
    }
}

void Count()
{
    if(F == -1 || R == -1)
    {
        printf("Queue is empty, count = 0\n");
    }
    else
    {
        int count;
        if(F <= R)
        {
            count = R - F + 1; 
        }
        else
        {
            count = (Size - F) + (R + 1);
        }
        printf("Number of elements in queue: %d\n", count);
    }
}

void Front()
{
    if(F == -1 || R == -1)
    {
        printf("Queue is empty, no front element\n");
    }
    else
    {
        printf("Front element: %d at position %d\n", CQ[F], F);
    }
}

void Rear()
{
    if(F == -1 || R == -1)
    {
        printf("Queue is empty, no rear element\n");
    }
    else
    {
        printf("Rear element: %d at position %d\n", CQ[R], R);
    }
}
