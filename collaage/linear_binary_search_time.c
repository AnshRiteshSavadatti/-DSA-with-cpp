#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define N 1000
#define iter 1000000

int linearSearch(int arr[], int N, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
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
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Key not found in the array
}

int main() {
    int arr[N];
    int arr[0] = 1;
    int key = 1;
    for(int i=0; i<N; i++){
        arr[i] = rand();
    }
    clock_t = s,e;
    s = clock();
    for(int i=0; i<itr; i++){
        int linearResult = linearSearch(arr, N, key);
    }
    e = clock();
    double d = (s-e)/CLK_TCK;
    printf("The time taken be linear search is %g\n",d);

    if (linearResult != -1) {
        printf("Linear Search: Element found at index: %d\n", linearResult);
    } else {
        printf("Linear Search: Element not found in the array\n");
    }
    clock = s;
    int binaryResult = binarySearch(arr, 0, N - 1, key);
    clock = e;
    d = (s-e) / CLK_TCK;
    printf("The time taken be binary search is %g\n",d);
    if (binaryResult != -1) {
        printf("Binary Search: Element found at index: %d\n", binaryResult);
    } else {
        printf("Binary Search: Element not found in the array\n");
    }

    return 0;
}
