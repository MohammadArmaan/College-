#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct CircularQueue
{
    int items[MAX];
    int front;
    int rear;
};

void intializeQueue(struct CircularQueue *queue)
{
    queue->rear = -1;
    queue->front = -1;
}

int isEmpty(struct CircularQueue *queue)
{
    return queue->rear == -1 && queue->front == -1;
}

int isFull(struct CircularQueue * queue)
{
    return (queue->rear + 1)%MAX == queue->front;
}

void Enqueue(struct CircularQueue * queue, int value)
{
    if(isFull(queue))
    {
        printf("Queue Overflow!!\n");
    }
    else
    {
        if(isEmpty(queue))
        {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1)%MAX;
        queue->items[queue->rear] = value;
        printf("%d is Enqueued in Circular Queue\n", value);
    }
}

void Dequeue(struct CircularQueue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue Underflow!!\n");
    }
    else
    {
        printf("%d Dequeued from Circular Queue\n", queue->items[queue->front]);
        if(queue->front == queue->rear)
        {
            intializeQueue(queue);
        }
        queue->front = (queue->front + 1)%MAX;
    }

}

void display(struct CircularQueue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is Empty!\n");
    }
    printf("\nCircular Queue Details: \n");
    int i = queue->front;
    do
    {
        printf("%d", queue->items[i]);
        i = (i + 1)%MAX;
    } while (i != (queue->rear + 1)%MAX);
    printf("\n");
    
}

int main()
{
    struct CircularQueue queue;
    intializeQueue(&queue);

    int choice;
    char value;

    do
    {
        printf("\nCircular Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the value to be Enqueued in Circular Queue: ");
                scanf("%d", &value);
                Enqueue(&queue, value);
                break;
            
            case 2:
                Dequeue(&queue);
                break;

            case 3:
                display(&queue);
                break;

            case 4:
                printf("Exiting the Program!\n");
                break;

            default:
                printf("Invalid Choice!!!\n");
                break;
        }
    }while(choice != 4);
    return 0;
}