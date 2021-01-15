

#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *link;
}*top=NULL;

void push(int item);
int pop();
int isEmpty();
void display();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Push\n");
                printf("2.Pop\n");
                printf("3.Display all items of the stack\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ") ;
                scanf("%d", &choice);

                switch(choice)
                {
                case 1:
                        printf("\nEnter the item to be pushed : ");
                        scanf("%d",&item);
                        push(item);
                        break;
                case 2:
                        item=pop();
                        printf("\nPopped item is : %d\n",item);
                        break;
                
                case 3:
                        display();
                        break;
                case 4:
                        exit(1);
                default :
                        printf("\nWrong choice\n");
                }
        }
}
void push(int item)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
                printf("\nStack Overflow\n");
                return;
        }
        tmp->data=item;
        tmp->link=top;
        top=tmp;
}

int pop()
{
        struct node *tmp;
        int item;
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        tmp=top;
        item=tmp->data;
        top=top->link;
        free(tmp);
        return item;
}

int peek()
{
        if( isEmpty() )
        {
                printf("\nStack Underflow\n");
                exit(1);
        }
        return top->data;
}

int isEmpty()
{
        if(top == NULL)
                return 1;
        else
                return 0;
}


void display()
{
        struct node *ptr;
        ptr=top;
        if(isEmpty())
        {
                printf("\nStack is empty\n");
                return;
        }
        printf("\nStack elements :\n\n");
        while(ptr!=NULL)
        {
                printf(" %d\n",ptr->data);
                ptr=ptr->link;
        }
        printf("\n");
}
