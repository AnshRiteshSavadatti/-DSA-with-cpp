#include<iostream>
using namespace std;

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

int partion(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] < arr[s])
            cnt++;
    }
    // placing at right position
    swap(arr[s],arr[s + cnt]);
    int i= s; int j = e;
    int index = s + cnt;

    while(i < index && j > index){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < index && j > index){
            swap(arr[i++], arr[j--]);
        }
    }
    return cnt + s;
}

void quick_sort(int* arr, int s, int e){
    // base case
    if(s >= e)
        return;
    //updation
    int p = partion(arr,s,e);

    // recursive relatoin
    quick_sort(arr,s,p-1); // left wala part sort karo

    quick_sort(arr,p+1,e); // right wala part sort karo

    return;
}

int main(){
     int n;
    cout << "Enter the size of Array" << endl;
    cin >> n;
    int* arr = new int[n];
    read_array(arr,n);
    quick_sort(arr, 0, n-1);
    print_array(arr, n);

    delete []arr;
    return 0;
}