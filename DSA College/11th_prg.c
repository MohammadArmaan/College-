#include <stdio.h>
#include <stdlib.h>

int choice, count, n, a[10][10], source, s[10], i, j;

void BFS(int n, int a[10][10], int source, int s[0])
{
    int q[10], u;
    int front = 1, rear = 1;
    s[source] = 0;
    q[rear] = source;
    while (front <= rear)
    {
        q[front] = u;
        front = front + 1;
        for (i = 0; i <= n; i++)
            if (a[u][i] == i && s[i] == 0)
            {
                rear = rear + 1;
                q[rear] = i;
                s[i] = 1;
            }
    }
}

int main()
{
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix: ");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    while (1)
    {
        printf("1. BFS\n 2. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the source: ");
                scanf("%d", &source);
                for(i=1; i<=n; i++)
                s[i] = 0;
                BFS(n, a, source, s);
                for(i = 1; i <= n; i++)
                if(s[i] == 0)
                {
                    printf("Node %d is not reachable\n", i);
                }
                else
                {
                    printf("Node %d is reachable,", i);
                }
        }
    }
}
