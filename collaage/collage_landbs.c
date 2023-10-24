#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define N 100000
#define iter 1000000

int linearSearch(int arr[], int key) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == key) {
            return 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } 
        
        else {
            right = mid - 1;
        }
    }

    return -1; 
}

int main() {
    int arr[N];
    arr[N-1] = 1;
    int key = -1;
    for(int i=1; i<N; i++){
        arr[i] = rand();
    }
    clock_t  s,e;
    s = clock();
    for(int i=0; i<iter; i++){
        int linearResult = linearSearch(arr, key);
    }
    e = clock();
    double d = ((e-s)/CLK_TCK);
    printf("The time taken be linear search is %g\n",d/iter);

    for(int i=0; i<N; i++){
        arr[i] = i;
    }
     s = clock();
    for(int i=0; i<iter; i++){
    int binaryResult = binarySearch(arr, 0, N - 1, key);
    }
    e = clock();
    d = ((e-s) / CLK_TCK);
    printf("The time taken be binary search is %g\n",d/iter);
    

    return 0;
}
