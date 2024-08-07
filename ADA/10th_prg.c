#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high){
    int pivot, i, j;
    pivot = a[high];
    i = low - 1;
    for(j = 0; j < high - 1; j++){
        if(a[j] < pivot)
            swap(&a[i], &a[j]);
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void generateRandomNumber(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] = rand() % 100000;
    }
}

int main(){
    int n;
    printf("Enter the number of sorts: ");
    scanf("%d", &n);

    if(n <= 5000){
        printf("The number of sorts must be greater than 5000!\n");
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("Memory Allocation Failed!\n");
    }

    generateRandomNumber(arr, n);

    clock_t start = clock();
    quickSort(arr, 0, n-1);
    clock_t end = clock();

    double time_taken = (double)(end - start)/CLOCKS_PER_SEC;

    printf("The time taken to sort %d elements is %f seconds\n", n, time_taken);

    free(arr);

    return 0;
}