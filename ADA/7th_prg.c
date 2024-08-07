#include<stdio.h>
int p[10], w[10], n, m;

void greedy_knapsack(){
    int i, j, k = 0;
    float max, profit;
    printf("Items included are: \n");
    for(i = 0; i < n; i++){
        max = 0;
        for(j = 0; j < n; j++){
            if(((float)p[j]) / w[j] > max){
                k = j;
                max = ((float)p[j])/ w[j];
            }
            
        }
        if(w[k] <= m){
            printf("%d ", k + 1);
            m = m - w[k];
            profit = profit + p[k];
            p[k] = 0;
        }
        else{
            break;
        }
    }
    printf("\nThe Discrete profit is %f\n", profit);
    printf("The Greedy Knapscak also includes items %d and portion %f\n", k + 1, ((float)m) / w[k]);
    profit = profit + ((float)m) / w[k] * p[k];
    printf("The Greedy Knapsack is = %f\n", profit);
}

int main(){
    int i;
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights of n items: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profits of n items: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the Knapsack capacity: \n");
    scanf("%d", &m);

    greedy_knapsack();
}
