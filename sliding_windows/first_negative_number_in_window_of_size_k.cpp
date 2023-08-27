// number of windows in array is [size - k + 1]


//    ///                                                  THE BELOW CODE IS BRUTE FORCE 
// #include<bits/stdc++.h>
// using namespace std;

// void read_array(int arr[], int n){
//     for(int i=0; i<n; i++)
//         cin >> arr[i];
// }

// void print_array(int arr[] ,int n){
//     for(int i=0; i<n; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

// void neg_number(int arr[], int n, int k){
//     int i = 0, j = 0;
//     bool flag = true;
//     int cnt = 0;
//     while(j - i + 1 <= k ){        
//         if(arr[j] < 0 && flag == true ){
//             cout  << arr[j] << " ";
//             flag = false;
//             cnt++;
//         }
//         j++;
//     }
//     if(cnt == 0)
//         cout << 0 << " ";
//     else   
//         cnt = 0;
//     while(j < n && i <= n-k){
//         i++;
//         j++;
//         for(int k = i; k<=j; k++){
//             if(cnt == 0 && arr[k] < 0){
//                 cout << arr[k]  << " ";
//                 cnt++;
//                 break;
//             }  
//         }
//         if(cnt  > 0)
//             cnt = 0;
//         else
//             cout << 0 << " ";
//     }

// }


// int main(){
//     int n;
//     int k;
//     int arr[1000];
//     cout << "Enter the size of array" << endl;
//     cin >> n;
//     cout << "Enter the size of subarray " << endl;
//     cin >> k;
//     cout << "Enter the array elements "<< endl;
//     read_array(arr,n);
//     print_array(arr,n);
//     neg_number(arr,n,k);   
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

void read_array(int arr[], int n){
    for(int i=0; i<n; i++)
        cin >> arr[i];
}

void print_array(int arr[] ,int n){
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void neg_number(int arr[], int n, int k){
    int i = 0, j = 0;
    bool flag = true;
    list<int>l;
    while(j < n){
        if( j - i + 1 <= k){
            if(arr[j] < 0 && flag == true ){
            cout  << arr[j] << " ";
            l.push_back(arr[j]);
            flag = false;
            }
        j++;
        }
        else{
            if(l.size() == 0)
                cout << 0 << " ";
            flag = true;
            if(arr[i] == l.front()){
                l.pop_front();
            }
            i++;
            j++;
            if(arr[j] < 0){
                l.push_back(arr[j]);
                if(flag == true){
                    cout  << arr[j] << " ";
                    flag = false;
                }
            }
            if(l.size() == 0)
                cout << 0 << " ";
            else
                cout << l.front() << " ";
        }
    }

}


int main(){
    int n;
    int k;
    int arr[1000];
    cout << "Enter the size of array" << endl;
    cin >> n;
    cout << "Enter the size of subarray " << endl;
    cin >> k;
    cout << "Enter the array elements "<< endl;
    read_array(arr,n);
    print_array(arr,n);
    neg_number(arr,n,k);   
    return 0;
}