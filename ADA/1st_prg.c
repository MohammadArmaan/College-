#include<stdio.h>
#include<stdlib.h>
int parent[10];

int find(int m){
    int p = m;
    while(parent[p] != 0)
        p = parent[p];
    return p;
}

void union_ij(int i, int j){
    if(i<j){
        parent[i] = j;
    }
    else{
        parent[j] = i;
    }
}

void kruskal(int a[10][10], int n){
    int i, j, u, v, min, sum = 0, k = 0;
    while(k < n-1){
        min = 99;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(a[i][j] < min && i != j){
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        i = find(u);
        j = find(v);

    if(i != j ){
        union_ij(i, j);
        printf("(%d %d) = %d", u, v, a[u][v]);
        sum = sum + a[u][v];
        k++;
        a[u][v] = a[v][u] = 99;
    }

                
    }
    printf("The Minimum cost spanning tree is %d", sum);
}

int main(){
    int a[10][10], i, j, n;
    printf("--------------------------------------------------------------------\n");
    printf("To Find Minimum Cost Spanning tree from Krushkal's ALgorithm\n");
    printf("--------------------------------------------------------------------\n");
    I:printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if(n>0){
        printf("Enter the adjacency matrix: ");
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d", &a[i][j]);
        kruskal(a, n);
    }
    else{
        printf("Enter the vaild number of vertices: \n");
        goto I;
    }
    return 0;
}