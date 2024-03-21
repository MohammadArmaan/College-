#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Stack
{
    int items[MAX];
    int top;
};

void intializeStack(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == MAX - 1;
}

void push(struct Stack *stack, int value)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack->items[++stack->top] = value;
        printf("%d Pushed into the Stack\n", value);
    }
}

int pop(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack->items[stack->top--];
    }
}

void display(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        for(int i = 0; i < stack->top; i++)
        {
            printf("%d", stack->items[i]);
        }
        printf("\n");
    }
}

int isPalendrome(struct Stack *stack, const char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        push(stack, str[i]);
    }
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(pop(stack) != str[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    struct Stack stack;
    intializeStack(&stack);

    int choice, value;
    char str[50];

    do
    {
        printf("\n Stack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if it is palendrome or not\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the value to Push into Stack: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                value = pop(&stack);
                if(value !=  -1)
                {
                    printf("%d is Poped from the Stack\n", value);
                }
                break;
            
            case 3:
                printf("Enter the String to Check wheater it is Palendrome or not: ");
                scanf("%s", str);
                if(isPalendrome(&stack, str))
                {
                    printf("It is a Palendrome\n");
                }
                else
                {
                    printf("It is not a Palendrome\n");
                }
                break;
            
            case 4:
                display(&stack);
                break;

            case 5: 
                printf("Exiting from the program!\n");
                break;

            default:
                printf("Invalid Choice!!!");
                break;
        }
    } while (choice != 5);
    return 0;
    
}
