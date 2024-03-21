#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coef, px, py, pz;
    struct node* next;
};

typedef struct node NODE;
NODE* first;

void insert(int coef, int px, int py, int pz)
{
    NODE* temp, *cur;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->coef = coef;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;

    if (first == NULL)
    {
        temp->next = temp;
        first = temp;
        return;
    }

    cur = first;
    while (cur->next != first)
    {
        cur = cur->next;
    }

    cur->next = temp;
    temp->next = first;
    return;
}

void display()
{
    NODE* cur;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    cur = first;
    do
    {
        printf("%dx^%dy^%dz^%d", cur->coef, cur->px, cur->py, cur->pz);
        if (cur->next != first)
            printf(" + ");
        cur = cur->next;
    } while (cur != first);
    printf("\n");
    return;
}

int evaluate(int x, int y, int z)
{
    NODE* cur;
    int v, s = 0;
    if (first == NULL)
    {
        printf("List is Empty\n");
    }
    cur = first;
    do
    {
        v = cur->coef * pow(x, cur->px) * pow(y, cur->py) * pow(z, cur->pz);
        s = s + v;
        cur = cur->next;
    } while (cur != first);
    return s;
}

int main()
{
    int coef, px, py, pz, x, y, z;
    int val;
    NODE*  first = NULL;
    int i;

    while (1)
    {
        printf("1. Insert Polynomial at end\n");
        printf("2. Display\n");
        printf("3. Evaluate\n");
        printf("4. EXIT\n");
        printf("Enter your choice: \t");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
            printf("Enter Coefficient: \t");
            scanf("%d", &coef);
            printf("Enter powers of x y z values:\t");
            scanf("%d %d %d", &px, &py, &pz);
            insert(coef, px, py, pz);
            break;

        case 2:
            display();
            break;

        case 3:
            printf("\nEnter x, y & z values for Evaluation: \t");
            scanf("%d %d %d", &x, &y, &z);
            val = evaluate(x, y, z);
            printf("\n Value: %d \n", val);
            break;

        case 4:
            return 0;

        default:
            printf("Wrong Choice. Enter 1, 2, 3, or 4\n");
            break;
        }
    }
}
