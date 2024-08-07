#include<stdio.h>
#include<stdlib.h>

void prims(int a[10][10], int n, int source){
    int i, j, u, v, min, sum = 0, k = 0, t = 0, s[10];
    for(i=0; i<n; i++){
        s[i] = 0;
    }
    s[source] = 1;
    k = 1;
    while(k <= n-1){
        min = 99;
        for(i = 0; i<n; i++){
            for(j=0; j<n; j++){
                if(s[i] == 1 && s[j] == 0){
                    if(a[i][j] < min && i != j){
                        min = a[i][j];
                        u = i;
                        v = j;  
                    }
                }
            }
        }

        printf("(%d %d) = %d\n", u, v, min);
        sum = sum + min;
        s[u] = 1;
        s[v] = 1;
        k++;
    }

    for(i = 0; i<n; i++){
        if(s[i] != 1){
            t = 1;
        }
    }

    if(t==0){
        printf("The Minimum Cost Spanning tree is %d", sum);
    }
    else{
        printf("The Minimum Cost Spanning tree is not possible\n");
    }
}

int main(){
    int a[10][10], i, j, n, source;
    printf("-------------------------------------------------------------------\n");
    printf("To Find the Minimum Cost Spanning tree using Prims Algorithm\n");
    printf("-------------------------------------------------------------------\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the Adjacency matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex: \n");
    scanf("%d", &source);

    prims(a, n, source);

    return 0;
}