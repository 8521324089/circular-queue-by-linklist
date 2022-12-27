#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head,*newnode,*temp;

int front=-1,rear=-1,size;

void enqueue(int element)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    if(front==-1 && rear==-1)   
    {  
        front=0;  
        rear=0;  
        newnode->data=element;  
        head=temp=newnode;
    }  
    else 
    {
        if((rear+1)%size==front)
        {
            printf("Queue is full \n");
        }
        else
        {
            rear=(rear+1)%size;
            newnode->data=element;
            temp->next=newnode;
            temp=newnode;
            //printf("%d is added in queue\n",temp->data);
        }
    }  
}

void dequeue()
{
       if((front==-1) && (rear==-1))  
    {  
        printf("Queue is empty\n");  
    }  
    else
    {
        printf("%d is removed from queue\n",head->data);
        if((front)%size==rear)
        {
            front=-1;
            rear=-1; 
            head=temp=0;
        }
        else
        {
            front=(front+1)%size;
            newnode=head;
            head=newnode->next;
            free(newnode);
        }
    }
}
void display()  
{  
    if(front==-1 && rear==-1)  
    {  
        printf("Queue is empty..\n");  
    }  
    else  
    {   
        newnode=head;
        int i=front;
        while((i%size)!=rear)
        {  
            printf("%d\t", newnode->data); 
            newnode=newnode->next; 
            i=(i+1)%size; 
        }  
        printf("%d\n",newnode->data);
    }  
}  
void main()
{
    printf("Enter the size of Queue = ");
    scanf("%d",&size);
    int c=1,element;
    while(c==1)
    {
    printf("Enqueue=1, dequeue=2, display=3  = ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        printf("Enter element =");
        scanf("%d",&element);
        enqueue(element);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        default:
        printf("Exiting!!!\n");
        break;
    }
    printf("To continue press 1 = ");
     scanf("%d",&c);
    }
}