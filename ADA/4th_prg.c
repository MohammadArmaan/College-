#include<stdio.h>
#include<stdlib.h>
int d[10], p[10], visited[10];

void dijtras(int a[10][10], int n, int s){
    int i, j, u, v, min;
    for(v = 0; v < n; v++){
        d[v] = 99;
        p[v] = -1;
        visited[v] = 0;
    }
    d[s] = 0;
    for(i = 0; i < n; i++)
        min = 99;
        for(j = 0; j < n; j++){
            if(d[j] < min && visited[j] == 0){
                min = d[j];
                u = j;
            }
        }
        visited[u] = 1;

    for(v = 0; v < n; v++){
        if((d[u] + a[u][v] < d[v]) && (u != v) && (visited[v] == 0)){
            d[v] = d[u] + a[u][v];
            p[v] = u;
        }
    }
}

void path(int v, int s){
    if(p[v] != -1){
        path(p[v], s);
    }
        printf("->%d", v);
}

void display(int n, int s){
    for(int i = 0; i < n; i++){
        if(i != s){
            printf("%d", s);
            path(i, s);
            printf("= %d\n", d[i]);
        }
    }
}

int main(){
    int i, j, a[10][10], n, s;
    printf("------------------------------------------------------------------------------\n");
    printf("To find the shortest path using Dijstras Algorithm\n");
    printf("------------------------------------------------------------------------------\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);

    printf("The Shortest Path between %d remaining vertices are \n", s);

    dijtras(a, n, s);

    printf("The Shortest Path is: \n");
    display(n, s);

    return 0;

}