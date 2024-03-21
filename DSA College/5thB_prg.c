#include<stdio.h>
#include<stdlib.h>

void TOH(int n, char source, char auxillary, char destination)
{
    if(n == 1)
    {
        printf("Move Disc 1 from %c to %c\n", source,destination);
    }
    else
    {
        TOH(n-1, source, destination, auxillary);
        printf("Move Disc %d from %c to %c\n", n, source, destination);
        TOH(n-1, auxillary, source, destination);
    }

}

int main()
{
    int n;
    printf("Enter Number of Moves: ");
    scanf("%d", &n);

    TOH(n, 'A', 'B', 'C');
    return 0;
}