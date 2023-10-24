#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

void print(vector<vector<char>> arr, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int isSafe(vector<vector<char>> arr, int n, int r, int c){
    int row = r;
    while(row >= 0){
        if(arr[row][c] == 'Q')
            return 0;
        row--;
    }
    int col = c;
    row = r;
    while(row >=0 && col >=0){
        if(arr[row][col] == 'Q')
            return 0;
        row--;
        col--;
    }

    row = r;
    col = c;
    while(row >=0 && col < n){
        if(arr[row][col] == 'Q'){
            return 0;
        }
        row--;
        col++;
    }
    return 1;
}

int solution(vector<vector<char>> arr, int n, int row, int col){
    if(row == n){
        print(arr, n);
        return 1;
    }
    
    for(col = 0; col < n; col++){
        if(isSafe(arr, n, row, col)){
            arr[row][col] = 'Q';
            solution(arr, n, row+1, col);
            arr[row][col] = '-';
        }
    }
    return 0;
}

int main(){
    int n;
    cout << "Enter the number of queens" << endl;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n, '-'));
    clock_t s, e;
    s = clock();
    solution(arr,n, 0, 0);
    e = clock();
    double d = e - s;
    cout << endl << "The time taken is " << d/1000 << endl;
    return 0;
}