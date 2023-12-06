#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int p = arr[l];
    int i = l;
    int j = r+1;

    do{
        do{
            i++;
        }while(arr[i] < p);
        do{
            j--;
        }while(arr[j] > p);
        swap(arr[i], arr[j]);
    }while(i < j);

    swap(arr[i], arr[j]);
    swap(arr[l], arr[j]);
    return j;
}

void QuickSort(int arr[], int l, int r){
    if(l >= r){
        return; // base case
    }

    int p = partition(arr, l, r); // updation

    // recursive relation
    QuickSort(arr, l, p-1);
    QuickSort(arr, p+1, r);
    return;
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
    QuickSort(arr, 0, 99);
    print_array(arr,100);
    return 0;
}