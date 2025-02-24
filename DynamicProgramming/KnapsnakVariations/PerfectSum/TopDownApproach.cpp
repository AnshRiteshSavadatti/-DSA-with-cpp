// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int perfectSum(int arr[], int n, int sum) {
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));
    
    for(int i = 0; i <= n; i++) t[i][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the desired sum: ";
    cin >> sum;

    int arr[n];

    // Random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100); // Change the range as needed

    cout << "Generated array: ";
    for(int i = 0; i < n; i++) {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = perfectSum(arr, n, sum);
    cout << "Number of subsets with sum " << sum << " is: " << result << endl;

    return 0;
}
