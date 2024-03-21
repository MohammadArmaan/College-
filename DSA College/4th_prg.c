#include<stdio.h>
#include<stdlib.h>
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

void push(struct Stack *stack, char value)
{
    if(isFull(stack))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        stack->items[++stack->top] = value;
        // printf("%s Pushed inside to Stack\n");
    }
}

char pop(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow!\n");
        return '\0';
    }
    else
    {
        return stack->items[stack->top--];
    }
}

int getPrecedence(char operator)
{
    switch(operator)
    {
        case '+':
        case '-':
            return 1;
        
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int infixToPostfix(char *infix, char *postfix)
{
    struct Stack operatorStack;
    intializeStack(&operatorStack);
    int i = 0, j = 0;

    while(infix[i] != '\0')
    {
        char currentChar = infix[i];

        if(isalnum(currentChar))
        {
            postfix[j++] = currentChar;
        }
        else if(currentChar == '(')
        {
            push(&operatorStack, currentChar);
        }
        else if(currentChar == '(')
        {
            while(!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(')
            {
                postfix[j++] = pop(&operatorStack);
            }
        }
        else
        {
            while(!isEmpty(&operatorStack) && getPrecedence(currentChar) <= getPrecedence(operatorStack.items[operatorStack.top]))
            {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, currentChar);
        }
        i++;
    }
    while(!isEmpty(&operatorStack))
    {
        postfix[j++] = pop(&operatorStack);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter Infix Operation: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The Postfix Expression is: %s", postfix);
    return 0;
}