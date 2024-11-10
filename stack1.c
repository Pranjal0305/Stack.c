#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL, *temp;

int count = 0;

void push()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        printf("Enter the data\n");
        scanf("%d", &newnode->data);
        newnode->next = top;
        top = newnode;
        count++;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;

        printf("The elements in the stack are:\n");
        int i = 1;
        while (temp != NULL)
        {
            printf("Element %d is %d\n", i, temp->data);
            temp = temp->next;
            i++;
        }
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
        count--;
    }
}
void peak()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The peak element is %d\n", top->data);
    }
}

int main()
{
    int choice = 1;
    while (choice)
    {
        printf("Press \n 1 to push the element\n 2 to pop the element\n 3 to display the elements\n 4 to display the peak\n0 to exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peak();
            break;
        case 0:
            choice = 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
