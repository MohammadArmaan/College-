#include<iostream>
#include<stdio.h>
using namespace std;

void asc_to_des(int A[], int n)
{
    int i, j, temp;
    for(i = 0; i<n-1; i++)
    {
        for(j = 0; j<n/2; j++)
        {
            if(A[j-1] > A[j])
            {
                temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
        }

        for(j = n/2; j<n-1; j++)
        {
            if(A[j+1] > A[j])
            {
                temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }

        }

    }
    for(i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;


}

int main()
{
    int arr[] = {3,5,7,9,12,3,4,67,43};
    int len = sizeof(arr)/sizeof(arr[0]);
    asc_to_des(arr, len);

    return 0;
}