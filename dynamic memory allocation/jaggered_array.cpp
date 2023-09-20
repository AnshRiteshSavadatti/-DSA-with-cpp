#include<iostream>
using namespace std;

int main(){
    int n = 3;
    int size[3] = {2,3,5};

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[size[i]];
    } 

    for(int i =0; i<n; i++){
        for(int j=0; j<size[i]; j++)
            cin >> arr[i][j];
    }

    for(int i =0; i<n; i++){
        for(int j=0; j<size[i]; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
