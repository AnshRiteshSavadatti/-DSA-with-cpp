// count the minmun number of minimun facters the number is to all the number
#include<bits/stdc++.h>
using namespace std;

int N = 1000000;
vector<int>arr(N);

void createSieve(){
    arr[0] = 0;
    arr[1] = 0;
    for(int i =2; i <= N; i++){
        arr[i] = 1;
    }
    for(int i=2; i*i <= N; i++){
        if(arr[i] > 0){
            for(int j=i*i; j<=N; j += i){
                arr[j] = 0;
                arr[i] += 1;
            }
        }
    }
}

int main(){
    // O(log(log(N)));
    createSieve();
    while(1){
        printf("1 to Enter the number\n2 to exit\n");
        int ch;
        cin >> ch;
        int data;
        switch(ch){
            case 1:
                printf("Enter the number\n");
                scanf("%d",&data);
                // O(1);
                cout << arr[data] << endl;
                break;
            default:
                exit(0);
        }
    }
    return 0;
}