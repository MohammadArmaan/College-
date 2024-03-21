#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAX 100

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
    return stack->top == MAX-1;
}

void push(struct Stack *stack, int value)
{
    if(isFull(stack))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack->items[++stack->top] = value;
    }
}

int pop(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        return stack->items[stack->top--];
    }
}

int evaluateSuffix(char *suffix)
{
    struct Stack operatorStack;
    intializeStack(&operatorStack);
    int i = 0;

    while(suffix[i] != '\0')
    {
        char currentChar = suffix[i];

        if(isdigit(currentChar))
        {
            push(&operatorStack, currentChar - '0');
        }
        else
        {
            int operand2= pop(&operatorStack);
            int operand1= pop(&operatorStack);
        
            switch(currentChar)
            {
                case '+':
                    push(&operatorStack, operand1 + operand2);
                    break;

                case '-':
                    push(&operatorStack, operand1 - operand2);
                    break;

                case '*':
                    push(&operatorStack, operand1 * operand2);
                    break;
                
                default:
                    printf("Invalid Choice!");
                    break;

                
            }
        }
            i++;


    }
    return pop(&operatorStack);
}

int main()
{
    char suffix[MAX];

    printf("Enter Suffix Expression: ");
    scanf("%s",suffix);

    int result = evaluateSuffix(suffix);
    printf("Result: %d\n", result);

}