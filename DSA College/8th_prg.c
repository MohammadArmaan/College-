#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee
{
    char ssn[15];
    char name[50];
    char dept[20];
    char designation[30];
    float sal;
    char phNo[15];
    struct Employee * prev;
    struct Employee *next;

};

struct Employee * createEmployeeNode(char ssn[], char name[], char dept[], char designation[], float sal, char phNo[])
{
    struct Employee * newNode = (struct Employee*)malloc(sizeof(struct Employee));
    if(newNode != NULL)
    {
        strcpy(newNode->ssn, ssn);
        strcpy(newNode->name, name);
        strcpy(newNode->dept, dept);
        strcpy(newNode->designation, designation);
        newNode->sal = sal;
        strcpy(newNode->phNo, phNo);
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

struct Employee *insertAtEnd(struct Employee * head, struct Employee * newNode)
{
    if(newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return head;
    }
    if(head == NULL)
    {
        return newNode;
    }
    struct Employee * current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Employee * deleteAtEnd(struct Employee * head)
{
    if(head == NULL)
    {
        printf("List is Empty!\n");
        return NULL;
    }
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Employee * current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

struct Employee * insertAtFront(struct Employee * head, struct Employee * newNode)
{
    if(newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return head;
    }
    if(head == NULL )
    {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Employee* deleteAtFront(struct Employee* head) 
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) 
    {
        free(head);
        return NULL;
    }

    struct Employee* newHead = head->next;
    newHead->prev = NULL;
    free(head);
    return newHead;
}



void displayAndCount(struct Employee * head)
{
    struct Employee * current = head;
    int count = 0;

    printf("\n Employee List\n");
    while(current != NULL)
    {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Sal: %f, PhNo: %s", current->ssn, current->name, current->dept, current->designation, current->sal, current->phNo);
        count++;
        current = current->next;
    }
    printf("Number of nodes in the list: %d\n",count);
}

int main()
{
    struct Employee * head = NULL;
    int choice;
    char ssn[15], name[50], dept[20], designation[30], phNo[15];
    float sal;
    do
    {
        printf("Doubly Linked List Operation Menu\n");
        printf("1. Create an Employee list using end Insertion\n");
        printf("2. Display the status of Employee List and count the number of nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete at Front\n");
        printf("7. Demonstrate Doubly Ended Queue\n");
        printf("8. EXIT\n");

        printf("Emter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the number of Employees: ");
                int n;
                scanf("%d", &n);

                for(int i = 0; i < n; i++)
                {
                    printf("Enter details of Employee %d: \n", i+1);
                    printf("SSN: ");
                    scanf("%s",ssn);
                    printf("Name: ");
                    scanf("%s",name);
                    printf("Department: ");
                    scanf("%s",dept);
                    printf("Designation: ");
                    scanf("%s",designation);
                    printf("Salary: ");
                    scanf("%f",&sal);
                    printf("Phone Number: ");
                    scanf("%s", phNo);

                    struct Employee * newNode = createEmployeeNode(ssn, name, dept, designation, sal, phNo);
                    head = insertAtEnd(head, newNode);
                    
                }
                break;

            case 2:
                displayAndCount(head);
                break;

            case 3:
                printf("Enter details of Employee: \n");
                printf("SSN: ");
                scanf("%s",ssn);
                printf("Name: ");
                scanf("%s",name);
                printf("Department: ");
                scanf("%s",dept);
                printf("Designation: ");
                scanf("%s",designation);
                printf("Salary: ");
                scanf("%f",&sal);
                printf("Phone Number: ");
                scanf("%s", phNo);

                struct Employee * newNodeEnd = createEmployeeNode(ssn, name, dept, designation, sal, phNo);
                head = insertAtEnd(head, newNodeEnd);
                break;

            case 4:
                head = deleteAtEnd(head);
                break;

            case 5:
                printf("Enter details of Employee: \n");
                printf("SSN: ");
                scanf("%s",ssn);
                printf("Name: ");
                scanf("%s",name);
                printf("Department: ");
                scanf("%s",dept);
                printf("Designation: ");
                scanf("%s",designation);
                printf("Salary: ");
                scanf("%f",&sal);
                printf("Phone Number: ");
                scanf("%s", phNo);

                struct Employee * newNodeFront = createEmployeeNode(ssn, name, dept, designation, sal, phNo);
                head = insertAtFront(head, newNodeFront);
                break;

            case 6:
                head = deleteAtFront(head);
                break;

            case 7:
                printf("Enter details of Employee: \n");
                printf("SSN: ");
                scanf("%s",ssn);
                printf("Name: ");
                scanf("%s",name);
                printf("Department: ");
                scanf("%s",dept);
                printf("Designation: ");
                scanf("%s",designation);
                printf("Salary: ");
                scanf("%f",&sal);
                printf("Phone Number: ");
                scanf("%s", phNo);

                struct Employee * newNodeDeque = createEmployeeNode(ssn, name, dept, designation, sal, phNo);
                
                printf("Inserting at the End of the List(Enqueue): \n");
                head = insertAtFront(head, newNodeDeque);
                displayAndCount(head);
                break;

            case 8:
                printf("Exiting the program!");
                break;

            default:
                printf("Invalid Choice!");


        }
        
    } while(choice != 8);
    struct Employee * current = head;
    struct Employee * temp;
    while(current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}