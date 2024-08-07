#include <stdio.h>
#include <stdlib.h>
int temp[10], k = 0;

void sort(int a[10][10], int id[10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (id[i] == 0){
            id[i] = -1;
            temp[k++] = i;

            for (j = 0; j < n; j++){
                if (a[i][j] == 1 && id[j] != 1){
                    id[j]--;
                }
            }
            i = -1;
        }
    }
}


int main(){
    int i, j, a[10][10], id[10], n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1){
                id[j]++;
            }
        }
    }

    sort(a, id, n);

    if(k != n){
        printf("Topological sort not possible!");
    }
    else{
        printf("The Sorted vertices are: \n");
        for(i=0; i<k; i++){
            printf("%d", temp[i] + 1);
        }
        printf("\n");
    }

    return 0;
}