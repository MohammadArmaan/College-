#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char usn[20];
    char name[50];
    char programme[50];
    int sem;
    char phNo[15];
    struct Student *next;
};

struct Student *createNewNode(char usn[], char name[], char programme[], int sem, char phNo[])
{
    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    if (newNode != NULL)
    {
        strcpy(newNode->usn, usn);
        strcpy(newNode->name, name);
        strcpy(newNode->programme, programme);
        newNode->sem = sem;
        strcpy(newNode->phNo, phNo);
        newNode->next = NULL;
    }
    return newNode;
}

struct Student *insertAtFront(struct Student *head, struct Student *newNode)
{
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return head;
    }
    newNode->next = head;
    return newNode;
}

struct Student *insertAtEnd(struct Student *head, struct Student *newNode)
{
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return head;
    }

    if (head == NULL)
    {
        return newNode;
    }

    struct Student *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = head;
    return head;
}

struct Student *deleteAtFront(struct Student *head)
{
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return NULL;
    }
    struct Student *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Student *deleteAtEnd(struct Student *head)
{
    if (head == NULL)
    {
        printf("List is Empty!\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Student *current = head;
    struct Student *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
    return head;
}

void *displayAndCount(struct Student *head)
{
    struct Student *current = head;
    int count = 0;

    while (current != NULL)
    {
        printf("USN: %s, Name: %s, Programme: %s, Semester: %d, Phone Number: %s", current->usn, current->name, current->programme, current->sem, current->phNo);
        count++;
        current = current->next;
    }
    printf("The Number of Nodes in the Student List are: %d", count);
}

void *freeList(struct Student *head)
{
    struct Student *current = head;
    struct Student *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Student *head = NULL;
    int choice, sem, n;
    char usn[20], name[50], programme[50], phNo[15];

    do
    {
        printf("Single Linked Operations\n");
        printf("1. Create New Node\n");
        printf("2. Display the Status\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete at Front\n");
        printf("7. EXIT\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the Number of Students: ");
                scanf("%d", &n);
                for(int i = 0; i<n; i++)
                {
                    printf("\nEnter Student Details for Student %d\n", i+1);
                    printf("USN: ");
                    scanf("%s", usn);
                    printf("Name: ");
                    scanf("%s", name);
                    printf("Programme: ");
                    scanf("%s", programme);
                    printf("Semester: ");
                    scanf("%d", &sem);
                    printf("Phone Number: ");
                    scanf("%s", phNo);

                    struct Student *newNode = createNewNode(usn, name, programme, sem, phNo);
                    head = insertAtFront(head, newNode);
                }
                break;

            case 2:
                displayAndCount(head);
                break;

            case 3:
                printf("\nEnter Student Details\n");
                printf("USN: ");
                scanf("%s", usn);
                printf("Name: ");
                scanf("%s", name);
                printf("Programme: ");
                scanf("%s", programme);
                printf("Semester: ");
                scanf("%d", &sem);
                printf("Phone Number: ");
                scanf("%s", phNo);

                struct Student *newNodeEnd = createNewNode(usn, name, programme, sem, phNo);
                head = insertAtEnd(head, newNodeEnd);
                break;

            case 4:
                head = deleteAtEnd(head);
                break;

            case 5:
            printf("\nEnter Student Details\n");
            printf("USN: ");
            scanf("%s", usn);
            printf("Name: ");
            scanf("%s", name);
            printf("Programme: ");
            scanf("%s", programme);
            printf("Semester: ");
            scanf("%d", &sem);
            printf("Phone Number: ");
            scanf("%s", phNo);

            struct Student *newNodeFront = createNewNode(usn, name, programme, sem, phNo);
            head = insertAtFront(head, newNodeFront);
            break;

            case 6:
                head = deleteAtFront(head);
                break;

            case 7:
                printf("Exiting the Program!\n");
                break;

            default: 
                printf("Invalid Choice!!!");
                break;

        }
    }while(choice != 7);
    freeList(head);
    return 0;
}
