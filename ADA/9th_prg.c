#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int a[], int n){
    int i, j, min_idx;
    for(i = 0; i < n; i++){
        min_idx = i;
        for(j = 0; j < n; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

void generateRandomNumber(int a[], int n){
    int i;
    for(i = 0; i<n; i++){
        a[i] = rand()%100000;
    }
}

int main(){
    int i, n;
    printf("Enter the number of sorts: ");
    scanf("%d", &n);

    if(n <= 5000){
        printf("The number of sorts must be greater than 5000!\n");
    }

    int *arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("Memory Allocation Failed!\n");
    }

    generateRandomNumber(arr, n);

    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    double time_taken = (double)(end - start)/CLOCKS_PER_SEC;

    printf("The Time Taken to sort %d elements is %f", n, time_taken);
    
    free(arr);

    return 0;
}