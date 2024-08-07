#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int s[MAX], x[MAX], d;

void sumOfSubset(int p, int k, int r){
    int i;
    x[k] = 1;
    if((p + s[k]) == d){
        for(i = 1; i <= k; i++){
            if(x[i] == 1){
                printf("%d ", s[i]);
            }
        }
        printf("\n");
    }
    else if(p + s[k] + s[k + 1] <= d){
        sumOfSubset(p + s[k], k + 1, r - s[k]);
    }
    if((p + r - s[k] >= d) && (p + s[k + 1] <= d)){
        x[k] = 0;
        sumOfSubset(p, k + 1, r - s[k]);
    }
}

int main(){
    int i, n, sum = 0;
    printf("Enter the n value: ");
    scanf("%d", &n);

    printf("Enter the set in increasing order: \n");
    for(i = 1; i <= n; i++){
        scanf("%d", &s[i]);
    }

    printf("Enter the max value: ");
    scanf("%d", &d);

    for(i = 1; i <= n; i++)
        sum = sum + s[i];
        if(sum < d || s[i] > d)
            printf("Sum of Subset not possible!\n");
        else
            sumOfSubset(0, 1, sum);

    return 0;
    
}
