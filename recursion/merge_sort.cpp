#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){

    int mid = s + (e-s)/2;

    int l1 = mid -s + 1;
    int l2 = e - mid;

    int *arr1 = new int[l1];
    int *arr2 = new int[l2];

    int index = s;
    for(int i=0; i<l1; i++)
        i[arr1] = arr[index++];
    for(int i=0; i<l2; i++)
        i[arr2] = arr[index++];

    index = s;
    int index1 = 0; int index2 = 0;

    while (index1 < l1 && index2 < l2)
    {
        if(arr1[index1] < arr2[index2]){
            arr[index++] = arr1[index1++];
        }
        else if(arr1[index1] > arr2[index2]){
            arr[index++] = arr2[index2++];
        }
        else{
            arr[index++] = arr1[index1++];
            arr[index++] = arr2[index2++];
        }

    }
    while(index1 < l1)
        arr[index++] = arr1[index1++];
    while (index2 < l2)
        arr[index++] = arr2[index2++];

    delete []arr1;
    delete []arr2;
    return;
}

void merge_sort(int arr[], int s, int e){
    int mid = s + (e-s)/2;
    // base case
    if(s >= e)
        return;
    
    // right part
    merge_sort(arr, s, mid);

    // left part
    merge_sort(arr,mid+1, e);

    // merging two sorted arrays
    merge(arr, s, e);

    return;
}

void read_array(int arr[], int n){
    for(int i =0; i<n; i++){
        cout << "Enter the element at " << i << " index "<< endl;
        cin >> arr[i];
    }
}

void print_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cout << i[arr] << " ";
    return;
}

int main(){
     int n;
    cout << "Enter the size of Array" << endl;
    cin >> n;
    int* arr = new int[n];
    read_array(arr,n);
    merge_sort(arr, 0, n-1);
    print_array(arr, n);

    delete []arr;
    return 0;
}