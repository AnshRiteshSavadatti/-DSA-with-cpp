#include<iostream>
using namespace std;

int main(){
    int n;
    cout <<"Enter the number of rows "<<endl;
    cin >>n;
    cout<< "Enter the number of columns " << endl;
    int m;
    cin >> m;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        cin >>arr[i][j];
    }
     
     cout << "The arrays elements are " << endl;
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
     }

    // releasing memory
    for(int i=0; i<n; i++)
        delete []arr[i];
    
    delete []arr;
    
    return 0;
}