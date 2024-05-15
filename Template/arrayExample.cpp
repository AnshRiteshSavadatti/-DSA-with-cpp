/*
    Basic exaple of templates
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T> int findKey(T * arr, T key, int n){
    for(int i=0; i<n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6};

    int ans = findKey(arr, 4, 6);
    cout << "The key is at location " << ans << endl;

    char ar[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    ans = findKey(ar, 'a', 6);
    cout << "The key is at location " << ans << endl;

    return 0;

}