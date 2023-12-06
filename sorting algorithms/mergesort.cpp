#include<bits/stdc++.h>
using namespace std;


void merge(int arr[],int n, int arr1[], int s1, int arr2[], int s2){
    int i=0, j=0, k=0;
    while(i < s1 && j < s2){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i];
            i++;
        }
        else{
            arr[k++] = arr2[j];
            j++;
        }
    }
    if(i == s1){
        for(; j < s2; j++)
            arr[k++] = arr2[j];
    }
    else{
        for(; i < s1; i++)
            arr[k++] = arr1[i];
    }
    return;
}

void mergesort(int arr[], float n){
    if (n <= 1) {
        return;  // Base case: already sorted
    }

    int s1 = n / 2;
    int s2 = n - s1;
    int arr1[s1];
    int arr2[s2];
    
    // copy
    for(int i=0; i<s1; i++){
        arr1[i] = arr[i];
    }
    for (int i = 0; i < s2; i++) {
        arr2[i] = arr[s1 + i];
    }
    
    // mergesort call
    mergesort(arr1,s1);
    mergesort(arr2, s2);
    
    // merge call
    return merge(arr, n, arr1, s1, arr2, s2);
}

void generate_array(int arr[], int n){
    srand(time(NULL));
    for(int i=0; i<n; i++)
        arr[i] = rand();
    return;
}

void print_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[100];
    generate_array(arr,100);
    mergesort(arr,100);
    print_array(arr,100);
    return 0;
}