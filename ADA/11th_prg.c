#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - (left + 1);
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        L[i] = a[left + i];

    for(j = 0; j < n2; j++)
        R[j] =  a[right + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }

    free(R);
    free(L);
}

void mergeSort(int a[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
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

    int *arr = (int*)malloc(n * sizeof(int));

    if(arr == NULL){
        printf("Memory Allocation Failed!\n");
    }

    generateRandomNumber(arr, n);

    clock_t start = clock();
    for(int i = 0; i < n; i++){
        mergeSort(arr, 0, n-1);
    }
    clock_t end = clock();

    double time_taken = (double)(end - start)/CLOCKS_PER_SEC;

    printf("The Time Taken to sort %d elements is %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}