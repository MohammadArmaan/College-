#include<stdio.h>
#include<stdlib.h>


void warshals(int a[10][10], int n){
    int i, j, k;
    for(k = 1; k <= n; k++)
    for(i = 1; i <= n; i++)
    for(j = 1; j <= n; j++)
    a[i][j] = a[i][j] || a[i][k] && a[k][j];

}

int main(){
    int i, j, a[10][10], n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("Enter the Adajacency matrix: \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    warshals(a, n);

    printf("Resultant Matrix: \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}